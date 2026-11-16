#include <pic.h>

__CONFIG(FOSC_XT & WDTE_ON & PWRTE_ON & CP_OFF);

unsigned char TMP1;
unsigned char TMP2;

unsigned char SUM(void);

unsigned char SUM(void) {
    return (TMP1 + TMP2);
}

void main(void) {
    TMP1 = 10;
    TMP2 = 20;
    
    while(1) {
        SUM();
    }
}