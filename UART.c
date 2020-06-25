#include <p32xxxx.h>
#include <xc.h>
#include<sys/attribs.h>
#include<math.h>
#include "Config.h"
#include "PCAP.h"





void UART_init()
{
    U3MODE  =  0x0;
    NOP();
    
    U3MODECLR  = _U3MODE_BRGH_MASK;
    NOP();
    U3BRG   = 44;                         
    NOP();
    U3MODECLR  = _U3MODE_SIDL_MASK;
    NOP();
    U3MODECLR  = _U3MODE_IREN_MASK;
    NOP();
    U3MODECLR  = _U3MODE_RTSMD_MASK;
    NOP();
    U3MODECLR  = _U3MODE_UEN0_MASK;
    NOP();
    U3MODECLR  = _U3MODE_UEN1_MASK;
    NOP();
    U3MODECLR  = _U3MODE_WAKE_MASK;
    NOP();
    U3MODECLR  = _U3MODE_LPBACK_MASK;
    NOP();
    U3MODECLR  = _U3MODE_ABAUD_MASK;
    NOP();
    U3MODECLR  = _U3MODE_RXINV_MASK;
    NOP();
    U3MODECLR  = _U3MODE_PDSEL1_MASK;
    NOP();
    U3MODECLR  = _U3MODE_PDSEL0_MASK;
    NOP();
    U3MODECLR  = _U3MODE_STSEL_MASK;
    NOP();
   
    IFS4CLR    = _IFS4_U3RXIF_MASK;
    NOP();
    IEC4SET    =_IEC4_U3RXIE_MASK;
    NOP();
    IPC39bits.U3RXIP = 7;
    NOP();
    INTCONSET  =_INTCON_MVEC_MASK;
    NOP();
    PRISS      =0x76543210;
    NOP();
    __builtin_enable_interrupts();
    NOP();
    
 
    U3STACLR   = _U3STA_URXISEL0_MASK;
    NOP();
    U3STASET   = _U3STA_URXISEL1_MASK;
    NOP();
    U3STASET   = _U3STA_URXEN_MASK;
    NOP( );
    U3STASET   = _U3STA_URXEN_MASK;
    NOP( );
   
    U3MODESET  = _U3MODE_ON_MASK;
    NOP();
    
}

    

void UART_RX()
{
    int count5;
    if(U3STAbits.OERR)
    {
        U3STACLR   = _U3STA_OERR_MASK;
    }
    for(count5=0;count5<6;count5++)
    {
      //  while(!U3STAbits.URXDA);
        Buffer[count5] = U3RXREG;
    }                                  
}
 