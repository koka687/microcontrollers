#include <xc.h>

#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config CP = OFF

void main(void) {

    TRISA = 0xFF; 
    TRISB = 0x00; 
    PORTB = 0x00; 

    while (1) {
        if (PORTAbits.RA0 == 1) {        
            if (PORTAbits.RA1 == 1) {    
                PORTB = 0xFF;            
            } else {                      
                PORTB = 129;              
            }
        } else {                         
            if (PORTAbits.RA1 == 0) {     
                PORTB = 0x02;             
            } else {                      
                PORTB = 0x3C;             
            }
        }
    }
}
