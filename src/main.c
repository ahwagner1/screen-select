#include "include/gpio.h"
#include "include/rcc.h"
#include "include/i2c.h"
#include "include/dma.h"

/*
* i2c is on apb1
*
* i2c scl and sda are on pb6 and pb7
*
* buttons are on pc5, 6, 8
*/

#include <stdio.h>

#define HSI_FREQ 16000000

int main() {
    // extra setup
    ss_clock_init();
    ss_gpio_button_init();
    ss_gpio_i2c_init();




    // i2c settings setup

    return 0;

}
