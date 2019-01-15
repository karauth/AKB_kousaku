#include <xc.h>
#include <stdint.h>

#pragma config FOSC   = HS,  PLLEN  = ON
#pragma config CPUDIV = NOCLKDIV
#pragma config HFOFST = OFF
#pragma config STVREN = ON,  LVP    = OFF

#define _XTAL_FREQ 12000000         // クロック12MHz

volatile unsigned char out = 0;

void init(void)
{
    TRISC  = 0b00000000;            // All output
    ANSEL  = 0b00000000;            // All digital
    ANSELH = 0b00000000;            // All digital
}

void main(void)
{
    init();

    for (uint16_t i = 0; i < 24 * 30; ++i) {
        PORTC = 1;                 // High
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");

        PORTC = 0;                 // Low
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
    }
}
