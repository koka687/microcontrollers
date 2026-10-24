#include <htc.h>
#define _XTAL_FREQ 4000000

void main(void) {
    TRISB = 0b11111110; 
    TRISA = 0b00000011; 
    PORTB = 0x00;

    unsigned int t1 = 5;   
    unsigned int t2 = 195; 
    unsigned int i;

    while(1) {
        if (RA0 == 0) { 
            if (t1 < 199) { t1++; t2--; }
        }
        if (RA1 == 0) { 
            if (t1 > 1) { t1--; t2++; }
        }

        RB0 = 1;
        for(i = 0; i < t1; i++) { __delay_us(1); }
        RB0 = 0;
        for(i = 0; i < t2; i++) { __delay_us(1); }
    }
}
