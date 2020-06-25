/************************************Include_Files*****************************************/

#include<p32xxxx.h>
#include<xc.h>
#include <sys/attribs.h>
 



/************************************End_Of_Include_files********************************/

unsigned short Coordinate_Extraction(unsigned char , unsigned char);

unsigned short Coordinate_Extraction(unsigned char L_byte , unsigned char H_byte)
{
   unsigned short decimal0,decimal1,decimal2,result;

    decimal0=(L_byte&0x0F);                   //Extracting lower nibble and assigning to integer
    decimal1=(L_byte&0xF0);                   //Extracting higher nibble and assigning to integer
    decimal2= (H_byte&0x0F)*256;             //the lower nibble of higher byte and assigning to integer
    result = decimal0+decimal1+decimal2;                // adding all will give a decimal value which will be the coordinate.
    return(result);
}
