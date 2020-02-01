/*
 * GccApplication1.c
 *
 * Created: 1/8/2020 8:17:00 PM
 *  Author: AVINASH CHAUDHARY
 */ 


#include <avr/io.h>

int main(void)
{
	DDRA=0x01;
	DDRC=0x00;
    while(1)
    {
		if(PINC&(1<<0))
		{
			PORTA=0x01;
		}
		else
		    PORTA=0x00;
        
    }
}