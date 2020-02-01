/*
 * GccApplication1.c
 *
 * Created: 1/8/2020 7:52:56 PM
 *  Author: AVINASH CHAUDHARY
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{    
	DDRA=0x01;
	
    while(1)
    {
		PORTA=0x01;
		_delay_ms(1000);
		PORTA=0x00;
		_delay_ms(1000);
        
    }
}