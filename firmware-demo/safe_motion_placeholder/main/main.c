#include <stdbool.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "coco_safe_demo";

void app_main(void)
{
    ESP_LOGI(TAG, "CoCo Robot Lite safe-motion placeholder");
    ESP_LOGI(TAG, "No actuator driver or motion GPIO is initialized by this example");

    while (true) {
        ESP_LOGI(TAG, "Demo idle: motion output remains unconfigured");
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}
