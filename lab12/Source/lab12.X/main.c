#include <htc.h>
#include <stdio.h>

#define _XTAL_FREQ 4000000

void putch(unsigned char byte) {
    while (!TXIF) {}
    TXREG = byte;
}

unsigned char getch(void) {
    if (OERR) { CREN = 0; CREN = 1; }
    while (!RCIF) {}
    return RCREG;
}

void uart_init(void) {
    TRISC6 = 1;
    TRISC7 = 1;
    SPBRG = 25; // 9600 ??? ??? 4 ???
    TX9 = 0; SYNC = 0; BRGH = 1; TXEN = 1;
    RX9 = 0; CREN = 1; SPEN = 1;
}

void adc_init(void) {
    ADCON1 = 0b10001110;
    ADCON0 = 0b01000000;
}

unsigned int read_adc(void) {
    unsigned int res;
    ADON = 1;
    __delay_us(40);
    GO_DONE = 1;
    while (GO_DONE);
    res = ((unsigned int)ADRESH << 8) | ADRESL;
    ADIF = 0;
    ADON = 0;
    return res;
}

void main(void) {
    unsigned int adc_code;
    unsigned int prev_adc = 9999; // ??? ????????? ????? ???????
    float U;

    TRISA = 0b00000001;
    TRISB = 0x00;
    TRISD = 0x00;
    PORTB = 0x00;
    PORTD = 0x00;

    uart_init();
    adc_init();
    __delay_ms(50);

    while (1) {
        adc_code = read_adc();
        PORTB = ADRESH;
        PORTD = ADRESL;

        // ????????? ????? ????????? ?????? ???? ????????? ??????? ?? ?????????????!
        if (adc_code != prev_adc) {
            prev_adc = adc_code;
            U = adc_code * ((float)5.0 / 1023.0);

            putch(0x0C); // ???????? ????? Virtual Terminal (Form Feed \f ? ??????? 4)
            printf("-----------------\r\n");
            printf("|  DC-VOLTMETR  |\r\n");
            printf("-------- --------\r\n");
            printf("| Uin  || %1.2fV |\r\n", U);
            printf("-------- --------\r\n");
            printf("| ADC  ||  %04u |\r\n", adc_code);
            printf("-----------------\r\n");
        }
        __delay_ms(100);
    }
}