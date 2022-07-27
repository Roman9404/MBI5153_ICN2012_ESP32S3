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
extern uint16_t zaneprazdneny [512];
extern uint16_t one_h [512];
extern uint16_t busy [512];
extern uint16_t zanjat [512];
extern uint16_t hujnja [512];
extern uint16_t svoboden [512];
extern uint16_t brest [512];
extern uint16_t vashe_hujnja [512];
extern uint16_t vashe_hujnja_2 [512];
extern uint16_t zanjat_2 [512];
extern uint16_t pivo [512];

int pulse = 100;

int btn = 0;

static void IRAM_ATTR gpio_isr_handler(void* arg)
{
    gpio_intr_disable(INPUT_GPIO);
    btn++;
    if (btn == 12)
    {
        btn=0;
        gpio_intr_enable(INPUT_GPIO);
    } 
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
    //mbi_set_frame(zaneprazdneny, test_long_disp_black, test_long_disp_black);

    while (1)
    {
        if (btn== 0)
        {
            mbi_set_frame(hello, hello, hello);
            gpio_intr_enable(INPUT_GPIO);
            while (btn==0){}
        }
        if (btn== 1)
        {
            mbi_set_frame(zaneprazdneny, test_long_disp_black, test_long_disp_black);
            gpio_intr_enable(INPUT_GPIO);
            while (btn==1){}
        }

        if (btn== 2)
        {
            mbi_set_frame(one_h, test_long_disp_black, test_long_disp_black);
            gpio_intr_enable(INPUT_GPIO);
            while (btn==2){}
        }

         if (btn== 3)
        {
            mbi_set_frame(busy, test_long_disp_black, test_long_disp_black);
            gpio_intr_enable(INPUT_GPIO);
            while (btn==3){}
        }

        if (btn== 4)
        {
            mbi_set_frame(zanjat, test_long_disp_black, test_long_disp_black);
            gpio_intr_enable(INPUT_GPIO);
            while (btn==4){}
        }   

        if (btn== 5)
        {
            mbi_set_frame(hujnja, test_long_disp_black, test_long_disp_black);
            gpio_intr_enable(INPUT_GPIO);
            while (btn==5){}
        }

        if (btn== 6)
        {
            mbi_set_frame(test_long_disp_black, svoboden, test_long_disp_black);
            gpio_intr_enable(INPUT_GPIO);
            while (btn==6){}
        }

        if (btn== 7)
        {
            mbi_set_frame(brest, brest, test_long_disp_black);
            gpio_intr_enable(INPUT_GPIO);
            while (btn==7){}
        }

        if (btn== 8)
        {
            mbi_set_frame(vashe_hujnja, test_long_disp_black, test_long_disp_black);
            gpio_intr_enable(INPUT_GPIO);
            while (btn==8){}
        }

        if (btn== 9)
        {
            mbi_set_frame(vashe_hujnja_2, test_long_disp_black, test_long_disp_black);
            gpio_intr_enable(INPUT_GPIO);
            while (btn==9){}
        }

        if (btn== 10)
        {
            mbi_set_frame(zanjat_2, test_long_disp_black, test_long_disp_black);
            gpio_intr_enable(INPUT_GPIO);
            while (btn==10){}
        }

        if (btn== 11)
        {
            mbi_set_frame(pivo, pivo, test_long_disp_black);
            gpio_intr_enable(INPUT_GPIO);
            while (btn==11){}
        }
    }

}