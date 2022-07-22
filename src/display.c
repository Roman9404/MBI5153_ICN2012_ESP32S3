#include "display.h"

bool latch = 0;
bool reg1 = 0;
uint16_t config_reg = 0;

char test=1;

/*
uint16_t eye [256] =   {
    o, l, o, o, o, l, l, o, l, o, l, o, o, o, l, l,
    o, l, o, o, o, l, o, o, l, o, l, o, o, o, l, o,
    o, l, o, l, l, l, o, o, l, l, o, o, l, l, l, o,
    o, o, o, l, o, l, o, o, o, l, o, o, l, o, l, o,
    o, l, o, l, l, l, o, o, o, o, l, o, l, l, l, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,};

uint16_t green_1 [256] = {
    o, l, o, o, o, l, l, o, l, o, l, o, o, o, l, l,
    o, l, o, o, o, l, o, o, l, o, l, o, o, o, l, o,
    o, l, o, l, l, l, o, o, l, l, o, o, l, l, l, o,
    o, o, o, l, o, l, o, o, o, l, o, o, l, o, l, o,
    o, l, o, l, l, l, o, o, o, o, l, o, l, l, l, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, l, l, o, o, l, l, o, o, o,
    o, o, o, o, l, o, l, l, l, l, o, o, o, l, o, o,
    o, o, o, l, o, o, l, l, l, l, l, o, o, l, o, o,
    o, o, o, l, l, o, o, l, l, l, l, o, l, l, o, o,
    o, o, o, o, l, l, l, l, l, l, l, l, l, o, o, o,
    o, o, o, o, o, l, l, l, l, l, l, l, o, o, o, o,
    o, o, o, o, o, o, o, l, l, l, l, o, o, o, o, o,
    o, o, o, o, o, o, o, l, o, o, l, o, o, o, o, o,
    o, o, o, o, o, o, o, l, o, o, l, o, o, o, o, o,
    o, o, o, o, o, o, l, l, o, l, l, o, o, o, o, o,};

uint16_t green_2 [256] = {
    o, l, o, o, o, l, l, o, l, o, l, o, o, o, l, l,
    o, l, o, o, o, l, o, o, l, o, l, o, o, o, l, o,
    o, l, o, l, l, l, o, o, l, l, o, o, l, l, l, o,
    o, o, o, l, o, l, o, o, o, l, o, o, l, o, l, o,
    o, l, o, l, l, l, o, o, o, o, l, o, l, l, l, o,
    o, o, o, o, o, o, o, o, o, o, o, o, l, o, o, o,
    o, o, o, o, o, o, o, l, l, o, o, o, o, l, o, o,
    o, o, o, l, o, o, l, l, l, l, o, o, o, l, o, o,
    o, o, o, l, o, o, l, l, l, l, l, o, o, l, o, o,
    o, o, o, l, l, o, o, l, l, l, l, o, l, l, o, o,
    o, o, o, o, l, l, l, l, l, l, l, l, l, o, o, o,
    o, o, o, o, o, l, l, l, l, l, l, l, o, o, o, o,
    o, o, o, o, o, o, o, l, l, l, l, o, o, o, o, o,
    o, o, o, o, o, o, o, l, o, o, l, o, o, o, o, o,
    o, o, o, o, o, o, o, l, o, o, l, o, o, o, o, o,
    o, o, o, o, o, o, l, l, o, l, l, o, o, o, o, o,};

uint16_t heart_0 [256] = {
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,};

uint16_t heart_3 [256] = {
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, l, l, l, l, o, o, o, l, l, l, l, o, o,
    o, o, l, l, l, l, l, l, o, l, l, l, l, l, l, o,
    o, l, l, l, l, l, l, l, l, l, l, l, l, l, l, l,
    o, l, l, l, l, l, l, l, l, l, l, l, l, l, l, l,
    o, l, l, l, l, l, l, l, l, l, l, l, l, l, l, l,
    o, o, l, l, l, l, l, l, l, l, l, l, l, l, l, o,
    o, o, o, l, l, l, l, l, l, l, l, l, l, l, o, o,
    o, o, o, o, l, l, l, l, l, l, l, l, l, o, o, o,
    o, o, o, o, o, l, l, l, l, l, l, l, o, o, o, o,
    o, o, o, o, o, o, l, l, l, l, l, o, o, o, o, o,
    o, o, o, o, o, o, o, l, l, l, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, l, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,};

uint16_t heart_2 [256] = {
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, l, l, l, l, o, o, o, l, l, l, l, o, o,
    o, o, l, l, l, l, l, l, o, l, l, l, l, l, l, o,
    o, o, l, l, l, l, l, l, l, l, l, l, l, l, l, o,
    o, o, l, l, l, l, l, l, l, l, l, l, l, l, l, o,
    o, o, o, l, l, l, l, l, l, l, l, l, l, l, o, o,
    o, o, o, o, l, l, l, l, l, l, l, l, l, o, o, o,
    o, o, o, o, o, l, l, l, l, l, l, l, o, o, o, o,
    o, o, o, o, o, o, l, l, l, l, l, o, o, o, o, o,
    o, o, o, o, o, o, o, l, l, l, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, l, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,};

uint16_t heart_1 [256] = {
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, l, l, l, o, o, o, l, l, l, o, o, o,
    o, o, o, l, l, l, l, l, o, l, l, l, l, l, o, o,
    o, o, o, l, l, l, l, l, l, l, l, l, l, l, o, o,
    o, o, o, o, l, l, l, l, l, l, l, l, l, o, o, o,
    o, o, o, o, o, l, l, l, l, l, l, l, o, o, o, o,
    o, o, o, o, o, o, l, l, l, l, l, o, o, o, o, o,
    o, o, o, o, o, o, o, l, l, l, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, l, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,};
*/
uint16_t test_long_disp_red [512] = {
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,

    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,

    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,

    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l};
     
uint16_t test_long_disp_green [512] = {
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,

    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,

    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,

    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l};
    
uint16_t test_long_disp_blue [512] = {
    l, l, l, l, l, l, l, l,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,

    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,

    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,

    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l,
    l, l, l, l, l, l, l, l,     l, l, l, l, l, l, l, l};

 
uint16_t test_long_disp_black [512] = {
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,

    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,

    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,

    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o}; 


uint16_t hello [512] = {
    l, l, l, l, l, o, o, o,     l, l, l, l, l, o, o, o,
    o, l, o, o, o, o, o, o,     o, o, l, o, o, o, o, o,
    o, o, l, o, o, o, o, o,     o, o, l, o, o, o, o, o,
    o, l, o, o, o, o, o, o,     l, l, l, l, l, o, o, o,
    l, l, l, l, l, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     l, l, l, l, l, o, o, o,
    o, l, l, l, o, o, o, o,     l, o, l, o, l, o, o, o,

    l, o, o, o, l, o, o, o,     l, o, l, o, l, o, o, o,
    l, o, o, o, l, o, o, o,     l, o, o, o, l, o, o, o,
    o, l, l, l, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     l, l, l, l, l, o, o, o,
    l, l, l, l, l, o, o, o,     o, o, o, o, l, o, o, o,
    o, o, l, o, l, o, o, o,     o, o, o, o, l, o, o, o,
    o, l, l, o, l, o, o, o,     o, o, o, o, l, o, o, o,

    l, o, o, l, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     l, l, l, l, l, o, o, o,
    l, l, l, l, l, o, o, o,     o, o, o, o, l, o, o, o,
    l, o, o, o, o, o, o, o,     o, o, o, o, l, o, o, o,
    l, o, o, o, o, o, o, o,     o, o, o, o, l, o, o, o,
    l, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,

    o, o, o, o, o, o, o, o,     o, l, l, l, o, o, o, o,
    l, l, l, l, l, o, o, o,     l, o, o, o, l, o, o, o,
    l, o, o, o, l, o, o, o,     l, o, o, o, l, o, o, o,
    l, o, o, o, l, o, o, o,     o, l, l, l, o, o, o, o,
    o, l, l, l, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    o, o, o, o, o, o, o, o,     o, o, o, o, o, o, o, o,
    l, o, l, l, l, o, o, o,     o, o, o, o, o, o, o, o}; 



static const rmt_item32_t morse_esp[] = 
{
    {{{ 512, 1}}}
};


/*инициализация дисплея*/
void Display_init ()
{
    HC595_gpio_init ();
    MBI_gpio_init();
    soft_reset();
    PreActive();
    mbi_configuration(ghost_elimination_OFF,line_num_32,gray_scale_14,gclk_multiplier_OFF,current_1);
    mbi_configuration(ghost_elimination_OFF,line_num_32,gray_scale_14,gclk_multiplier_OFF,current_1);
    reg1=1;
    mbi_configuration(ghost_elimination_OFF,line_num_32,gray_scale_14,gclk_multiplier_OFF,current_2); 
}

void rmt_tx_init(void)
{
    rmt_config_t config = RMT_DEFAULT_CONFIG_TX (MBI_GCLK, RMT_TX_CHANNEL);
    config.tx_config.carrier_en = true;
    config.tx_config.carrier_duty_percent = 50;
    config.tx_config.carrier_freq_hz = 800000;
    config.clk_div = 100;

    rmt_set_source_clk(RMT_TX_CHANNEL, 1);
    ESP_ERROR_CHECK(rmt_config(&config));
    ESP_ERROR_CHECK(rmt_driver_install(config.channel, 0, 0));
    rmt_register_tx_end_callback (tx_end_callback,&test);
    rmt_write_items(RMT_TX_CHANNEL, morse_esp, sizeof(morse_esp) / sizeof(morse_esp[0]), 0);
}

/*инициализация gpio для HC595*/
void HC595_gpio_init ()
{
    gpio_pad_select_gpio(HC595_SER);
    gpio_pad_select_gpio(HC595_OE);
    gpio_pad_select_gpio(HC595_RCLK);
    gpio_pad_select_gpio(HC595_SRCLR);
    gpio_pad_select_gpio(HC595_SRCLK);

    gpio_set_direction(HC595_SER, GPIO_MODE_OUTPUT);
    gpio_set_direction(HC595_OE, GPIO_MODE_OUTPUT);
    gpio_set_direction(HC595_RCLK, GPIO_MODE_OUTPUT);
    gpio_set_direction(HC595_SRCLR, GPIO_MODE_OUTPUT);
    gpio_set_direction(HC595_SRCLK, GPIO_MODE_OUTPUT);

    gpio_set_level(HC595_SER,1);
    gpio_set_level(HC595_SRCLK,0);
    gpio_set_level(HC595_RCLK,1);

    gpio_set_level(HC595_SRCLR,1);
    gpio_set_level(HC595_OE,0);
}

/*инициализация gpio для MBI5153*/
void MBI_gpio_init()
{
    gpio_pad_select_gpio(MBI_GCLK);
    gpio_pad_select_gpio(MBI_LE);
    gpio_pad_select_gpio(MBI_DCLK);
    gpio_pad_select_gpio(MBI_SDI);

    gpio_set_direction(MBI_GCLK, GPIO_MODE_OUTPUT);
    gpio_set_direction(MBI_LE, GPIO_MODE_OUTPUT);
    gpio_set_direction(MBI_DCLK, GPIO_MODE_OUTPUT);
    gpio_set_direction(MBI_SDI, GPIO_MODE_OUTPUT);

    gpio_set_level(MBI_LE,0);
    gpio_set_level(MBI_DCLK,0);
}

/* тактирование линии данных драйвера MBI5153*/
void mbi_clock (uint8_t clock)
{
    while (clock--)
    {
        gpio_set_level(MBI_DCLK,1);
        gpio_set_level(MBI_GCLK,1);
        //ets_delay_us(clock_delay);
        gpio_set_level(MBI_DCLK,0);
        gpio_set_level(MBI_GCLK,0);
    }
}

/* тактирование линии шкалы серого драйвера MBI5153*/
void mbi_GCLK_clock (uint32_t GCLK_clock)
{
    while (GCLK_clock--)
    {
        gpio_set_level(MBI_GCLK,1);
        ets_delay_us(clock_delay);
        gpio_set_level(MBI_GCLK,0);
        ets_delay_us(clock_delay);
    }

}

/*настройка регистра конфигурации*/
void mbi_configuration(uint8_t ghost_elimination, uint8_t line_num, uint8_t gray_scale, uint8_t gclk_multiplier,uint8_t current)
{
    config_reg = 0;
    config_reg = (config_reg | (ghost_elimination<<15) | (line_num<<8) | (gray_scale<<7) | (gclk_multiplier<<6) | (current));
    mbi_set_config(config_reg);
}

/*отправка регистра конфигурации*/
void mbi_set_config (uint16_t config)
{
    bool config_bit[16] = {0};
    int data_mask = 0x1;
    for (size_t i = 0; i < 16; i++)  //парсит байт в булевый массив побитно
    {
        config_bit[i] = config & (data_mask<<i);
    }
    
    for (size_t i = 16; i > 0; i--)  //отсылает данные на ногу контроллера из массива
    {
        if ((i<5) && (reg1==1)) //защелка данных по последним 4 битам, при отправке последнего байта присвоить reg1=1
        {
            gpio_set_level(MBI_LE,1);
            gpio_set_level(MBI_SDI,config_bit[i-1]);
            mbi_clock(1);           
        }
        else
        {
            gpio_set_level(MBI_SDI,config_bit[i-1]);
            mbi_clock(1);
        } 
    }
    gpio_set_level(MBI_LE,0);
    gpio_set_level(MBI_SDI,0);
    reg1=0;
}

/*передача 2 байт данных драйверу MBI5153*/
void mbi_set_data (uint16_t data)
{
    bool data_bit[16] = {0};
    int data_mask = 0x1;
    for (size_t i = 0; i < 16; i++)  //парсит байт в массив побитно
    {
        data_bit[i] = data & (data_mask<<i);
    }
    for (size_t i = 16; i > 0; i--)  //отсылает данные на ногу контроллера из массива
    {
        if ((i==1) && (latch==1)) //защелка данных по последнему биту, при отправке последнего байта присвоить latch=1
        {
            gpio_set_level(MBI_LE,1);
            gpio_set_level(MBI_SDI,data_bit[i-1]);
            mbi_clock(1);
            gpio_set_level(MBI_LE,0);
            latch = 0;
        }
        else
        {
            gpio_set_level(MBI_SDI,data_bit[i-1]);
            mbi_clock(1);
        } 
    }
}

/*команда предактивации - отправляется перед отправкой данных регистра конфигурации*/
void PreActive ()
{
    gpio_set_level(MBI_LE,1);
    mbi_clock(14);
    gpio_set_level(MBI_LE,0);
}

/*вертикальная синхронизация - обновляет данные кадра на выходах, использовать вместе с вертикальной разверткой*/
void VertSync ()
{
    gpio_set_level(MBI_LE,1);
    mbi_clock(2);
    gpio_set_level(MBI_LE,0);
}

/*программный сброс*/
void soft_reset()
{
    gpio_set_level(MBI_LE,1);
    mbi_clock(10);
    gpio_set_level(MBI_LE,0); 
}

int flag_change_frame = 0;
/*отсылает данные для 1 кадра*/
void mbi_set_frame(uint16_t red [512], uint16_t green [512], uint16_t blue [512])
{
    for (size_t i = 0; i < 512; i++)
    {
        mbi_set_data(blue[i]);
        mbi_set_data(green[i]);
        latch=1;
        mbi_set_data(red[i]);
    }

    mbi_clock(50);
    flag_change_frame = 1;

}

/*прерывание в котором будет переход на другую строку, после 512 тиков GCLK*/
/*
int out=1;
int line_count = 16;    //счетчик линий на дисплее
int frame_count = 0;    //счетчик кадров

bool io2 = 1;

void tx_end_callback (char *test)
{
    gpio_set_level(2, out);
    out=!out;   
    
    line_count--;

    if (line_count==0)//запуск кадра заново с верхней линии
    {
        gpio_set_level(HC595_SER,0);
        line_count=16;
        frame_count++;
        
      if (flag_change_frame == 1)// когда переданы все данные кадра перед началом развертки нового кадра отсылает команду синхронизации
        {
            VertSync();
            flag_change_frame = 0;
        }
    }
            
    gpio_set_level(HC595_SRCLK,1);
    gpio_set_level(HC595_RCLK,0);
    ets_delay_us(5);
    gpio_set_level(HC595_SRCLK,0);
    gpio_set_level(HC595_RCLK,1);
    gpio_set_level(HC595_SER,1);
    
    rmt_write_items(RMT_TX_CHANNEL, morse_esp, sizeof(morse_esp) / sizeof(morse_esp[0]), 0);
}   */

/*прерывание в котором будет переход на другую строку, после 512 тиков GCLK*/
/*длинный дисплей*/

int line_count = 1;    //счетчик линий на дисплее
int frame_count = 0;    //счетчик кадров

bool ICN [32] [7] = {
//   A0 A1 A2  EN1 EN2 EN3 EN4
    { 0, 0, 0,  1,  0,  0,  0}, 
    
    { 1, 1, 1,  0,  0,  0,  1}, 
    { 0, 1, 1,  0,  0,  0,  1}, 
    { 1, 0, 1,  0,  0,  0,  1}, 
    { 0, 0, 1,  0,  0,  0,  1}, 
    { 1, 1, 0,  0,  0,  0,  1}, 
    { 0, 1, 0,  0,  0,  0,  1}, 
    { 1, 0, 0,  0,  0,  0,  1}, 
    { 0, 0, 0,  0,  0,  0,  1}, 

    { 1, 1, 1,  0,  0,  1,  0}, 
    { 0, 1, 1,  0,  0,  1,  0}, 
    { 1, 0, 1,  0,  0,  1,  0}, 
    { 0, 0, 1,  0,  0,  1,  0}, 
    { 1, 1, 0,  0,  0,  1,  0}, 
    { 0, 1, 0,  0,  0,  1,  0}, 
    { 1, 0, 0,  0,  0,  1,  0}, 
    { 0, 0, 0,  0,  0,  1,  0}, 

    { 1, 1, 1,  0,  1,  0,  0}, 
    { 0, 1, 1,  0,  1,  0,  0}, 
    { 1, 0, 1,  0,  1,  0,  0}, 
    { 0, 0, 1,  0,  1,  0,  0}, 
    { 1, 1, 0,  0,  1,  0,  0}, 
    { 0, 1, 0,  0,  1,  0,  0}, 
    { 1, 0, 0,  0,  1,  0,  0}, 
    { 0, 0, 0,  0,  1,  0,  0}, 

    { 1, 1, 1,  1,  0,  0,  0}, 
    { 0, 1, 1,  1,  0,  0,  0}, 
    { 1, 0, 1,  1,  0,  0,  0}, 
    { 0, 0, 1,  1,  0,  0,  0}, 
    { 1, 1, 0,  1,  0,  0,  0}, 
    { 0, 1, 0,  1,  0,  0,  0}, 
    { 1, 0, 0,  1,  0,  0,  0}, 


};

bool io2 = 1;

void tx_end_callback (char *test)
{
    gpio_set_level(EN,1);
    for (size_t i = 7; i > 0; i--)
    {
        //HC595_send_data(ICN [line_count-1] [i-1]);

        gpio_set_level(HC595_SER, ICN [line_count-1] [i-1]);

        gpio_set_level(HC595_SRCLK,1);
        gpio_set_level(HC595_RCLK,0);
    
        gpio_set_level(HC595_SRCLK,0);
        gpio_set_level(HC595_RCLK,1);
    }
    gpio_set_level(EN,0);   
    
    line_count--;

    if (line_count==0)//запуск кадра заново с верхней линии
    {
        line_count=32;
        
      if (flag_change_frame == 1)// когда переданы все данные кадра перед началом развертки нового кадра отсылает команду синхронизации
        {
            VertSync();
            flag_change_frame = 0;
        }
    }
   
    rmt_write_items(RMT_TX_CHANNEL, morse_esp, sizeof(morse_esp) / sizeof(morse_esp[0]), 0);
} 

/*отправляет данные в сдвиговый регистр для горизонтальной развертки*/
void HC595_send_data (uint data)   
{
    gpio_set_level(HC595_SER,data);

    gpio_set_level(HC595_SRCLK,1);
    gpio_set_level(HC595_RCLK,0);
    //ets_delay_us(5);
    gpio_set_level(HC595_SRCLK,0);
    gpio_set_level(HC595_RCLK,1);
    //gpio_set_level(HC595_SER,1);

} 