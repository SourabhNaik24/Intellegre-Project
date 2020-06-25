#include<xc.h>


void timer_init(void)
{
   T3CONbits.TON=0;
   PR3=40000;
   TMR3=0;
   T3CONbits.TON=1;
}