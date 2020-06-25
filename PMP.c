#include <xc.h>
#include <p32xxxx.h>
#include "config.h"

void PMP_init()
{
    PMCON       =        0x00000000;                // TURN OFF MODULE
    Nop();
    PMMODE      =        0x0604;     
    PMCON       =        0x8202;               
}
void PMP_write(unsigned short temp)
{
   // while(PMMODEbits.BUSY);
    PMDIN = temp;
}
