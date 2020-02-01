/*
 * GccApplication1.c
 *
 * Created: 1/8/2020 7:29:35 PM
 *  Author: AVINASH CHAUDHARY
 */ 


#include <avr/io.h>

int main(void)
{    
	DDRA=0x01;
	
    while(1)
    {
		PORTA=0x01;
       
    }
}