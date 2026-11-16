#include <pic.h>

__CONFIG(FOSC_XT & WDTE_OFF & PWRTE_OFF & CP_OFF);

void main(void) {
    TRISA0 = 1; 
    TRISA1 = 1;
    
    TRISB = 0x00; 

    while(1) {
        if (RA0 == 0) { 
            if (RA1 == 0) {
                PORTB = 0b00000010; 
            } else {
                PORTB = 129;
            }
        } 
        else { 
            if (RA1 == 0) {
                PORTB = 0xFF;
            } else {
                PORTB = 0x3C;
            }
        }
    }
}