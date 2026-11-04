#include <htc.h>

#define _XTAL_FREQ 4000000

void adc_convert(void) {
    ADON = 1;            
    __delay_us(40);      
    GO_DONE = 1;         
    while (GO_DONE);     
    ADIF = 0;           
    ADON = 0;            
}

void main(void) {
   
    TRISA = 0b00000001;  
    TRISB = 0b00000000;  
    TRISC = 0b00000000;  

    PORTB = 0x00;
    PORTC = 0x00;

    ADCON1 = 0b10001110;

    ADCON0 = 0b01000000;
    ADIF = 0;
    GIE = 0;             


    while (1) {
        adc_convert();       
        PORTB = ADRESH;      
        PORTC = ADRESL;      
        __delay_us(40);      
    }
}