#include <xc.h>

#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config CP = OFF

#define _XTAL_FREQ 4000000

void main(void) {
    TRISA = 0x00; 
    TRISB = 0xFF; 
    PORTA = 0x00; 

    unsigned char entered_key = 0;
    unsigned char correct_key = 4; 

    while (1) {
        if ((PORTB & 0x01) == 0) { entered_key = 1; __delay_ms(150); } 
        if ((PORTB & 0x02) == 0) { entered_key = 2; __delay_ms(150); } 
        if ((PORTB & 0x04) == 0) { entered_key = 3; __delay_ms(150); } 
        if ((PORTB & 0x08) == 0) { entered_key = 4; __delay_ms(150); } 

        if ((PORTB & 0x20) == 0) {
            entered_key = 0;
            PORTA = 0x00; 
            __delay_ms(150);
        }

        if ((PORTB & 0x10) == 0) {
            if (entered_key == correct_key) {
                PORTA = 0x01; 
            } else {
                PORTA = 0x02; 
            }
            __delay_ms(150);
        }
    }
}