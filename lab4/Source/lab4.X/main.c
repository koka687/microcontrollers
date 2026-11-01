#include <htc.h>
#define _XTAL_FREQ 4000000

const unsigned char MAS[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void main(void) {
    TRISB = 0x00; 
    TRISA = 0b00000000; 
    PORTB = 0x00;
    PORTA = 0x00;

    while(1) {
        PORTB = MAS[1];
        RA2 = 1; 
        __delay_ms(10);
        RA2 = 0; 

        PORTB = MAS[9];
        RA3 = 1; 
        __delay_ms(10);
        RA3 = 0; 
    }
}

