#include <stdbool.h>
#include <stdint.h>

#include "driver/i2c_master.h"
#include "esp_err.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define DEMO_I2C_PORT 0
#define DEMO_SDA_GPIO 8
#define DEMO_SCL_GPIO 9
#define PCA9685_ADDRESS 0x40
#define PCA9685_MODE1 0x00
#define PCA9685_PRESCALE 0xFE
#define PCA9685_LED0_ON_L 0x06
#define DEMO_CHANNEL 0
#define DEMO_PULSE_LOW 280
#define DEMO_PULSE_HIGH 330

static const char *TAG = "coco_servo_demo";

static void write_register(i2c_master_dev_handle_t device, uint8_t reg, uint8_t value)
{
    const uint8_t bytes[] = {reg, value};
    ESP_ERROR_CHECK(i2c_master_transmit(device, bytes, sizeof(bytes), 100));
}

static void set_channel_pulse(i2c_master_dev_handle_t device, uint16_t off_tick)
{
    const uint8_t start_register = PCA9685_LED0_ON_L + (4 * DEMO_CHANNEL);
    const uint8_t bytes[] = {
        start_register,
        0x00,
        0x00,
        (uint8_t)(off_tick & 0xFF),
        (uint8_t)((off_tick >> 8) & 0x0F),
    };
    ESP_ERROR_CHECK(i2c_master_transmit(device, bytes, sizeof(bytes), 100));
}

static void disable_demo_channel(i2c_master_dev_handle_t device)
{
    const uint8_t start_register = PCA9685_LED0_ON_L + (4 * DEMO_CHANNEL);
    const uint8_t bytes[] = {start_register, 0x00, 0x00, 0x00, 0x10};
    ESP_ERROR_CHECK(i2c_master_transmit(device, bytes, sizeof(bytes), 100));
}

void app_main(void)
{
    ESP_LOGW(TAG, "SUPERVISED DEMO: remove the servo horn and keep a physical disconnect ready");
    ESP_LOGW(TAG, "GPIO assignments are placeholders; confirm them before applying servo power");

    i2c_master_bus_config_t bus_config = {
        .i2c_port = DEMO_I2C_PORT,
        .sda_io_num = DEMO_SDA_GPIO,
        .scl_io_num = DEMO_SCL_GPIO,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
        .flags.enable_internal_pullup = true,
    };

    i2c_master_bus_handle_t bus_handle = NULL;
    ESP_ERROR_CHECK(i2c_new_master_bus(&bus_config, &bus_handle));

    i2c_device_config_t device_config = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = PCA9685_ADDRESS,
        .scl_speed_hz = 100000,
    };

    i2c_master_dev_handle_t device = NULL;
    ESP_ERROR_CHECK(i2c_master_bus_add_device(bus_handle, &device_config, &device));

    write_register(device, PCA9685_MODE1, 0x10);
    write_register(device, PCA9685_PRESCALE, 121);
    write_register(device, PCA9685_MODE1, 0x20);
    vTaskDelay(pdMS_TO_TICKS(5));
    write_register(device, PCA9685_MODE1, 0xA0);

    const uint16_t demo_positions[] = {
        DEMO_PULSE_LOW,
        292,
        305,
        318,
        DEMO_PULSE_HIGH,
        318,
        305,
        292,
        DEMO_PULSE_LOW,
    };

    for (unsigned int cycle = 0; cycle < 3; ++cycle) {
        ESP_LOGI(TAG, "Limited demo sweep %u of 3", cycle + 1);
        for (unsigned int step = 0; step < sizeof(demo_positions) / sizeof(demo_positions[0]); ++step) {
            set_channel_pulse(device, demo_positions[step]);
            vTaskDelay(pdMS_TO_TICKS(350));
        }
    }

    disable_demo_channel(device);
    ESP_LOGI(TAG, "Demo finished; PWM channel disabled. Disconnect servo power before handling.");

    while (true) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
