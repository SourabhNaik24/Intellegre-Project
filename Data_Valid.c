/************************************Include_Files*****************************************/

#include<p32xxxx.h>
#include<xc.h>
#include <sys/attribs.h>
 


/************************************End_Of_Include_files********************************/



int Data_Valid_Byte(unsigned char[]);



int Data_Valid_Byte(unsigned char Current_data[6])              //for checking the checksum byte
{       
     
    unsigned char sum1 = 0x00;                     
    int count3;
    for (count3 =0 ; count3 <5; count3++ ){                     
    sum1 = sum1  + Current_data[count3];                          // Adding the bytes  
    }
    sum1 = ~(sum1&0xFF);                                         // Anding with 0xFF and inverting it
                                                 
    if(sum1 == Current_data[5])                                 // Checking with the Checksum byte for verifying data
    {
        return 1;
    }
} 
