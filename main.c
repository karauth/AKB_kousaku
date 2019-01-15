#include <xc.h>

#pragma config FOSC = HS
#pragma config PLLEN  = ON
#pragma config CPUDIV = NOCLKDIV
#pragma config HFOFST = OFF
#pragma config STVREN = ON
#pragma config LVP = OFF

#define _XTAL_FREQ 48000000         // クロック48MHz

void init(void) {
    TRISCbits.RC0 = 0;            // RC0：output
    ANSELbits.ANS4 = 0;           // RC0：digital
}

void main(void) {
    init();
    while (1) {
        PORTCbits.RC0 = !PORTCbits.RC0; // RC0のビットを0/1交互に反転させる
        __delay_ms(400);                // Wait 400msec
    }
}
