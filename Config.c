//****************************/* ALL includes here */***********************************************************//
#include<p32xxxx.h>
#include<xc.h>
//*************************************************************************************************************//
//****************************/* GLOBAL DEFINITIONS */**********************************************************
#define CS        LATAbits.LATA2
#define RESET     LATCbits.LATC14
#define DEN       LATCbits.LATC4
#define NOP()     asm("NOP")          // inline assembler syntax (note)
#define back_light_on  LATGSET=_LATG_LATG12_MASK
#define back_light_off LATGCLR=_LATG_LATG12_MASK
#define VSYNCL LATDCLR=_LATD_LATD1_MASK
#define VSYNCH LATDSET=_LATD_LATD1_MASK
#define HSYNCL LATDCLR=_LATD_LATD0_MASK
#define HSYNCH LATDSET=_LATD_LATD0_MASK

#define RED 0x001f
#define BLUE 0xf800
#define GREEN 0x07E0
#define MAGENTA 0xF81f
#define CYAN 0xffe0
#define YELLOW 0x07ff



// Global Functions //

/*************************************************************************************************** 
 * FUNCTION NAME: setPBCLK_2
 * DESCRIPTION  : USED TO SET THE PERIPHERAL CLOCK TO 6.6 MHz. 
 *                USED in PMP,I2C and SPI PERIPHERAL CLOCKS.
 * CREATED ON   : 5 OCT, 2017.
 * *************************************************************************************************/
void setPBCLK_2()  
{   
    SYSKEY=0xAA996655;     // UNLOCK SEQUENCE TO CONGIGURE PB2DIV.
    SYSKEY=0x556699AA; 
    PB2DIVbits.ON =0;
    PB2DIVbits.PBDIV=2;
    PB2DIVbits.ON =1;
    SYSKEY=0x33333333;        // LOCK SEQUENCE    
}

/*************************************************************************************************** 
 * FUNCTION NAME: initialize_All_Pins()
 * DESCRIPTION  : USED TO INITIALIZE ALL IO PINS.
 * CREATED ON   : 5 OCT, 2017.
 * *************************************************************************************************/
void initialize_All_Pins()
{
    /*****************Configuring all Output/Input pins here**************/
    
    TRISA=0x8000;
     NOP();
    TRISB=0;
     NOP();
    TRISC=0x9000;      // RC15 & RC 12 oscillator pins
     NOP();
    TRISD=0;      // RD10 INTH pin
     NOP();
    TRISE=0;
     NOP();
    TRISF=0;
     NOP();
    TRISG=0;
     NOP();
    
    // Selecting all PINS as digital PINS.
    ANSELA=0;
    ANSELB=0;
    ANSELC=0;
    ANSELD=0;
    ANSELE=0;
    ANSELF=0;
    ANSELG=0;
    
    // Latching All output pins LOW
    NOP();
    LATA=0;
     NOP();
    LATB=0;
     NOP();
    LATC=0;
     NOP();
    LATD=0;
     NOP();
    LATE=0;
     NOP();
    LATF=0;
     NOP();
     LATG=0;
     NOP();
     //
     Nop();
    /*Configuring all Active LOW signal here*/
    RESET               =    1;                    // Making Reset to LCD high (Active LOW RESET)
    CS                  =    1;                    // Making CS of LCD high (ACTIVE LOW CS)
    /*******************ALL PPS pins set here************/
    
    // PPS for SPI 2 MODULE 
    CFGCONbits.IOLOCK   =      0;                  // UNLOCK IO PPS.
    NOP();
    RPG7R               = 0b0110;                  // Value to be loaded for pin G7 to act as SDA to LCD.
    CFGCONbits.IOLOCK   =      1;                  // LOCK IO PPS.
    // PPS for INTH pin of PCAP Module.
    NOP();
    CFGCONbits.IOLOCK   =      0;
    NOP( );
    U3RXR               =   0b1101;
    CFGCONbits.IOLOCK   =      1;
    NOP( );
    CFGCONbits.IOLOCK   =      0;
    NOP( );
    RPA14R               =   0b0001;
    CFGCONbits.IOLOCK   =      1;
    NOP( );
    
    
    
    
    // Configuring I2C clock in open drain configuration
    NOP();
    ODCAbits.ODCA14     =      1;                  // Configure Pins 14 in open drain configuration to support +5v source through I2C pins
    NOP();
    ODCAbits.ODCA15     =      1;
    NOP();
    back_light_off;
}


