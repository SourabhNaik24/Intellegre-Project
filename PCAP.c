#include <p32xxxx.h>
#include <xc.h>
#include<sys/attribs.h>
#include<math.h>
#include "config.h"
#include "UART.h"
#include "LCD_driver.h"
#include "PMP.h"

#define min_SwipeDistance 1600

    unsigned char rx_byte;
    unsigned char Buffer[6];

    unsigned short  X1_Coordinate,X2_Coordinate, X_Distance , Y_Distance;
    unsigned short  Y1_Coordinate,Y2_Coordinate;
    int fingerdown = 1;
    int fingerup = 0;
    unsigned int flag=0;
   

 

void PCAP_run(void)
{
   
    flag = Data_Valid_Byte(Buffer);
        
    
        if(Buffer[0] == 0x70 && fingerdown==1 && flag==1)
        {
            X1_Coordinate = Coordinate_Extraction(Buffer[1], Buffer[2]);              // Getting Decimal value of X_Coordiante
            Y1_Coordinate = Coordinate_Extraction(Buffer[3], Buffer[4]);              // Getting Decimal value of Y_Coordinate
            fingerdown=0;
        }
        if (Buffer[0] == 0x40 && flag==1)
        {
            X2_Coordinate = Coordinate_Extraction(Buffer[1], Buffer[2]);              // Getting Decimal value of X_Coordiante
            Y2_Coordinate = Coordinate_Extraction(Buffer[3], Buffer[4]);              // Getting Decimal value of Y_Coordinate
            fingerup=1;
            X_Distance  = abs(X2_Coordinate-X1_Coordinate);
            Y_Distance  = abs(Y2_Coordinate-Y1_Coordinate);
            Buffer[0] = 0x0;
        }
       
   
    
    if(fingerup==1)
    {
        if(X_Distance>Y_Distance&&X_Distance>min_SwipeDistance)                
        {
            if(X2_Coordinate>X1_Coordinate)
            {
                CHANGE_color(BLUE);
                fingerdown=1;
                fingerup=0;
               
                    //Swipe right if distance between x coordinate is greater then minimum distance and difference is negative
            }
            else if(X2_Coordinate<X1_Coordinate)
            {
                CHANGE_color(GREEN);
                fingerdown=1;
                fingerup=0;
                 
                    //Swipe left if distance between x coordinate is greater then minimum distance and difference is negative
            }
        }
        else if(Y_Distance>X_Distance&&Y_Distance>min_SwipeDistance)                
        {
            if(Y2_Coordinate>Y1_Coordinate)
            {
                CHANGE_color(MAGENTA);
                fingerdown=1;
                fingerup=0;
                 
                //Swipe DOWN if distance between x coordinate is greater then minimum distance and difference is negative
            }
            else if(Y2_Coordinate<Y1_Coordinate)
            {
                CHANGE_color(YELLOW);
                fingerdown=1;
                fingerup=0;
               
                    //Swipe left if distance between x coordinate is greater then minimum distance and difference is negative
            }
        }
    }
}
            
        
        
            
    
        
 
