


#include <p32xxxx.h>
#include <xc.h>
#include "config.h"
#include "PMP.h"


unsigned short horizontal=0,vertical=0;
unsigned short array2[240][320];
unsigned short change;

void LCD_init()
{
    setPBCLK_2();                                                                 
    initialize_All_Pins(); 
    PMP_init();
    back_light_on;   
}

// function below takes care of all hsync and vsync's
void LCD_run(void)
{
  
    VSYNCL;               
    
//<editor-fold defaultstate="collapsed" desc="BACK_porch">
         for(vertical=0;vertical<13;vertical++)
         {
            HSYNCL;
             
             for(horizontal=0;horizontal<70;horizontal++)
             {
                 PMP_write(0);
                 VSYNCH;
                 HSYNCH;
             }
             
             for(horizontal=0;horizontal<320;horizontal++)
             {
                 PMP_write(0);
             }
             
             for(horizontal=0;horizontal<18;horizontal++)
             {
                 PMP_write(0);
                 HSYNCH;
             }
             
         }
//<editor-fold>
    
         
                                                                                    // MAIN DATA
         for(vertical=0;vertical<240;vertical++)
            {
             
             HSYNCL;
             
             for(horizontal=0;horizontal<70;horizontal++)
             {
                 PMP_write(0);
                 VSYNCH;
                 HSYNCH;
             }
             
             for(horizontal=0;horizontal<320;horizontal++)
             {
                 PMP_write(array2[vertical][horizontal]);
             }
             
             for(horizontal=0;horizontal<18;horizontal++)
             {
                 PMP_write(0);
                 HSYNCH;
             }
            }
         
         
                                                                                     // FRONT PORCH HSYNC
         
         for(vertical=0;vertical<10;vertical++)
         {
             HSYNCL;
             
             for(horizontal=0;horizontal<70;horizontal++)
             {
                 PMP_write(0);
                 VSYNCH;
                 HSYNCH;
             }
             
             for(horizontal=0;horizontal<320;horizontal++)
             {
                 PMP_write(0);
             }
             
             for(horizontal=0;horizontal<18;horizontal++)
             {
                 PMP_write(0);
                 HSYNCH;
             }
             
         }
}

void CHANGE_color(unsigned short cc)
{
    change = cc;
}
// Function below will change the image on screen
 void CHANGE_image(const unsigned short image[])
 {
     int count=0,row,column;
     for(row=0;row<240;row++)
        {
			for(column=0;column<320;column++)
				{
					array2[row][column] = image[count];
					count++;
				}
        }
 }
