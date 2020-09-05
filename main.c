#include "msp.h"


/**
 * main.c
 */

//STRUCT for the POUT register
typedef struct{

    uint32_t p0: 1;
    uint32_t p1: 1;
    uint32_t p2: 1;
    uint32_t p3: 1;
    uint32_t p4: 1;
    uint32_t p5: 1;
    uint32_t p6: 1;
    uint32_t p7: 1;

}PxOUT_MODE_t;

//STRUCT for PORTX register
typedef struct{

    uint32_t PIN:   16;
    uint32_t POUT:  16;
    uint32_t PDIR:  16;
    uint32_t PREN:  16;
    uint32_t PDS:   16;
    uint32_t PSEL0: 16;
    uint32_t PSEL1: 16;
    uint32_t PSELC: 16;
    uint32_t PIES:  16;
    uint32_t PIE:   16;
    uint32_t PIFG:  16;

}PORTX_MODE_t;

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	PxOUT_MODE_t *pP1OUT = (PxOUT_MODE_t*)0x40004C02;//Pointer to P1OUT adress

	PxOUT_MODE_t *pP2OUT = (PxOUT_MODE_t*)0x40004C03;//Pointer to P2OUT adress

	PORTX_MODE_t *pPORT1 = (PORTX_MODE_t*)0x40004C00;//Pointer to PORT1 adress

	pP1OUT->p1 = 0;
	pP1OUT->p3 = 0;
	pP1OUT->p4 = 0;
	pP1OUT->p5 = 0;
	pP1OUT->p7 = 0;

	pP2OUT->p0 = 1;
	pP2OUT->p1 = 1;
	pP2OUT->p2 = 1;
	pP2OUT->p3 = 1;
	pP2OUT->p6 = 1;
	pP2OUT->p7 = 1;


	pPORT1->POUT = 0b00000000;
	pPORT1->PDIR = 0b00000001;
	pPORT1->POUT = 0b00000001;
}
