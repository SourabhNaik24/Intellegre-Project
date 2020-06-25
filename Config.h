#define config
#define CS        LATAbits.LATA2
#define RESET     LATCbits.LATC14
#define DEN       LATCbits.LATC4
#define NOP()     asm("NOP")          // inline assembler syntax (note)
#define INTH      LATDbits.LATD10
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


void setPBCLK_2();
void initialize_All_Pins();





