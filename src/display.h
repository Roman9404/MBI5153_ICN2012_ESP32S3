#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_log.h"
#include "driver/rmt.h"

#define MBI_GCLK                37  //тактирование уровней серого
#define MBI_LE                  38  //данные/команда
#define MBI_DCLK                36  //тактирование линии данных
#define MBI_SDI                 35  //данные

#define HC595_SER               11   //данные, которые будут сдвигаться в регистрах
#define HC595_OE                13   //outpu enable
#define HC595_RCLK              14   //такт защелки
#define HC595_SRCLR             10   //очитска регистра
#define HC595_SRCLK             12   //тактовый сигнал

/*Для теста длинног дисплея ICN2012*/
#define EN         48
#define EN1        47
#define EN2        21
#define EN3        9
#define EN4        8
#define A0         16
#define A1         17
#define A2         18


#define ghost_elimination_ON    1   //послесвечение выключенно
#define ghost_elimination_OFF   0   //послесвечение включено
#define gray_scale_13           1   //шкала серого 13 бит
#define gray_scale_14           0   //шкала серого 14 бит
#define gclk_multiplier_ON      1   //делитель gclk включен
#define gclk_multiplier_OFF     0   //делитель gclk выключен
#define line_num_16             15  //количество линий 16
#define line_num_32             31  //количество линий 32
#define line_num_1              0   //количество линий 1
#define current_1               15  //ток на светодиоде
#define current_2               30  //ток на светодиоде

#define clock_delay             0

#define l                   65532  
#define o                   0 

#define RMT_TX_CHANNEL RMT_CHANNEL_0

void Display_init ();
void rmt_tx_init(void);
void HC595_gpio_init ();
void MBI_gpio_init();
void mbi_clock (uint8_t clock);
void mbi_GCLK_clock (uint32_t GCLK_clock);
void mbi_configuration(uint8_t ghost_elimination, uint8_t line_num, uint8_t gray_scale, uint8_t gclk_multiplier,uint8_t current);
void mbi_set_config (uint16_t config);
void mbi_set_data (uint16_t data);
void PreActive ();
void VertSync ();
void soft_reset();
void mbi_set_frame(uint16_t red [256],uint16_t green [256], uint16_t blue [256]);
void tx_end_callback (char *test);
void HC595_send_data (uint data) ;