/*
 * GccApplication1.c
 *
 * Created: 1/9/2020 8:19:22 AM
 *  Author: AVINASH CHAUDHARY
 */ 


#include <avr/io.h>

int main(void)
{
	DDRA=0x03;
	DDRC=0x00;
    while(1)
    {
       if (PINC&(1<<0))
	   {
		   
		   PORTA=0x03;
		   
	   } 
	   else 
	   PORTA=0x00;
	   
    }
}