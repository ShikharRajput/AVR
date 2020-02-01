/*
 * GccApplication1.c
 *
 * Created: 1/9/2020 9:22:46 AM
 *  Author: AVINASH CHAUDHARY
 */ 


#include <avr/io.h>

int main(void)
{
	DDRA=0x03;
	DDRC=0x00;
    while(1)
    {
       if(PINC&(1<<0))
	   {
		    PORTA=0x01;   
	   }
	   else if (PINC&(1<<1))
		{
			PORTA=0x02;
			   
		 }
	    else
		    PORTA=0x00;
			
    }
}