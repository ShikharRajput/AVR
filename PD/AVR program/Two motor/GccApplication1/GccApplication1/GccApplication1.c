/*
 * GccApplication1.c
 *
 * Created: 1/9/2020 10:44:14 PM
 *  Author: AVINASH CHAUDHARY
 */ 


#include <avr/io.h>

int main(void)
{
	DDRC=0xff;
	
    while(1)
    {
	  PORTC=0x05;	
	}       
}