#ifndef I2C_H
#define I2C_H

#include <stdint.h>

typedef struct {
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t OAR1;
    volatile uint32_t OAR2;
    volatile uint32_t DR;
    volatile uint32_t SR1;
    volatile uint32_t SR2;
    volatile uint32_t CCR;
    volatile uint32_t TRISE;
    volatile uint32_t FLTR;
} I2C_Def;

#define I2C1 ((I2C_Def*)0x40005400)
#define I2C2 ((I2C_Def*)0x40005400)
#define I2C3 ((I2C_Def*)0x40005400)

/*
 * Per project functions/definitions below
 */

// using pb6 and pb7 for the clock and data lines
// need to configure i2c to be controller (master)
// probably configure it to use DMA cus why not

#endif
