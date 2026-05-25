#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;
} GPIO_Def;

#define GPIOA ((GPIO_Def*)0x40020000)
#define GPIOB ((GPIO_Def*)0x40020400)
#define GPIOC ((GPIO_Def*)0x40020800)
#define GPIOD ((GPIO_Def*)0x40020C00)
#define GPIOE ((GPIO_Def*)0x40021000)
#define GPIOH ((GPIO_Def*)0x40021C00)

/*
 * Per project functions/definitions below
 */


// GPIOB things
#define GPIOB6_AF_EN (0x2 << 12);
#define GPIOB6_RES ~(0x3 << 12);
#define GPIOB7_AF_EN (0x2 << 14);
#define GPIOB7_RES ~(0x3 << 12);

// af04 for both i2c1_sda and scl on pb6 and 7  respectivily
#define GPIOB_AFRL_RES (0x00000000)
#define GPIOB6_AFRL_SET_I2C (0x4 << 24);
#define GPIOB7_AFRL_SET_I2C (0x4 << 28);

#define GPIOB_OSPEEDR_RES (0x000000C0);
#define GPIOB6_OSPEEDR_SET_HIGH (0x2 << 12);
#define GPIOB7_OSPEEDR_SET_HIGH (0x2 << 14);

// GPIOC things
#define GPIOC_MODER_RES (0x00000000);

void ss_gpio_i2c_init() {
    /*
     * this function handles setting up the i2c gpio pins
     */

    // setting alternate functions enabled
    GPIOB->MODER &= GPIOB6_RES;
    GPIOB->MODER |= GPIOB6_AF_EN;
    GPIOB->MODER &= GPIOB7_RES;
    GPIOB->MODER |= GPIOB7_AF_EN;

    // setting up actual alternate funcitons
    GPIOB->AFRL &= GPIOB_AFRL_RES;
    GPIOB->AFRL |= GPIOB6_AFRL_SET_I2C;
    GPIOB->AFRL |= GPIOB7_AFRL_SET_I2C;

    // setting speed to high
    GPIOB->OSPEEDR &= GPIOB_OSPEEDR_RES;
    GPIOB->OSPEEDR |= GPIOB6_OSPEEDR_SET_HIGH;
    GPIOB->OSPEEDR |= GPIOB7_OSPEEDR_SET_HIGH;
}

void ss_gpio_button_init() {
   /*
    * need to refine the schematic
    * but going to use pc5, 6, 8
    * they all line up nicely next to eachother on the nucleo
    * i think they need to be configured to sit inline with the resistor
    * basically just be measure high until the button is clicked
    * in which case the line gets pulled to ground (low)
    */

    // reset state is input mode
    GPIOC->MODER &= GPIOC_MODER_RES;
}

#endif /* GPIO_H */
