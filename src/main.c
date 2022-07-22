#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

#include "esp_log.h"
#include "driver/rmt.h"

#include "display.h"

#define BLINK_GPIO 2
#define INPUT_GPIO 7
#define ESP_INTR_FLAG_DEFAULT 0

extern uint16_t test_long_disp_red[512];
extern uint16_t test_long_disp_green[512];
extern uint16_t test_long_disp_blue[512];
extern uint16_t test_long_disp_black[512];
extern uint16_t hello[512];

int pulse = 100;

int btn = 0;

static void IRAM_ATTR gpio_isr_handler(void* arg)
{
    gpio_intr_disable(INPUT_GPIO);
    btn++;// = !btn;
    if (btn == 3) btn=0;
   // gpio_intr_enable(INPUT_GPIO);
}

void app_main() 
{
    gpio_pad_select_gpio(BLINK_GPIO);
    gpio_pad_select_gpio(INPUT_GPIO);
    gpio_pad_select_gpio(39);//для длинного дисплея
    
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_direction(INPUT_GPIO, GPIO_MODE_INPUT);
    gpio_set_direction(39, GPIO_MODE_OUTPUT);//для длинного дисплея


    gpio_set_pull_mode(INPUT_GPIO,GPIO_PULLDOWN_ONLY); 
    gpio_set_intr_type(INPUT_GPIO, GPIO_INTR_POSEDGE);
    gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);
    gpio_isr_handler_add(INPUT_GPIO, gpio_isr_handler, (void*) INPUT_GPIO);
    
    Display_init ();


    rmt_tx_init();
    mbi_set_frame(hello, hello, hello);

    while (1)
    {
       
    }

}