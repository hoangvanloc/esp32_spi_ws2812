#include "SPI_ws2812.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
static const char* TAG = "MAIN";
//example use
void app_main(void)
{	
	CRGB leds[LED_MAX_NBER_LEDS]; //24 led
	initSPIws2812();
	CRGB c;
    while(1) 
	{
		for(int i = 0 ; i < LED_MAX_NBER_LEDS ; i++)
		{
			c.r = 0;
			c.g = i;
			c.b = 0;
			leds[i] = c;
		}
		fillBuffer((uint32_t *)leds,LED_MAX_NBER_LEDS);
		led_strip_update();
		vTaskDelay(100 / portTICK_PERIOD_MS);
        
    }
}
