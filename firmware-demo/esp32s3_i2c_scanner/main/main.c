#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>

#include "driver/i2c_master.h"
#include "esp_err.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define DEMO_I2C_PORT 0
#define DEMO_SDA_GPIO 8
#define DEMO_SCL_GPIO 9

static const char *TAG = "coco_i2c_demo";

void app_main(void)
{
    ESP_LOGI(TAG, "CoCo Robot Lite: supervised I2C scan demo");
    ESP_LOGW(TAG, "Disconnect actuators and verify the placeholder GPIO assignments first");

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

    unsigned int found = 0;
    for (uint8_t address = 0x08; address <= 0x77; ++address) {
        esp_err_t result = i2c_master_probe(bus_handle, address, 50);
        if (result == ESP_OK) {
            ESP_LOGI(TAG, "Simulated-lab peripheral acknowledged at 0x%02" PRIx8, address);
            ++found;
        } else if (result != ESP_ERR_TIMEOUT && result != ESP_ERR_NOT_FOUND) {
            ESP_LOGW(TAG, "Probe at 0x%02" PRIx8 " returned %s", address, esp_err_to_name(result));
        }
        vTaskDelay(pdMS_TO_TICKS(5));
    }

    ESP_LOGI(TAG, "Scan complete: %u responding address(es)", found);
    ESP_ERROR_CHECK(i2c_del_master_bus(bus_handle));
}
