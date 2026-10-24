#include <htc.h>
#define _XTAL_FREQ 4000000 

void main(void) {
    TRISB = 0b11101111; 
    PORTB = 0x00;

    while(1) {
        RB4 = 1;
        __delay_us(20);  
        RB4 = 0;
        __delay_us(180); 
    }
}