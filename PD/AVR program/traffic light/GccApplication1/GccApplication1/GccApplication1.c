/*
 * GccApplication1.c
 *
 * Created: 1/15/2020 9:37:04 AM
 *  Author: AVINASH CHAUDHARY
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA=0x07;
    while(1)
    {
		PORTA=0x01;
		_delay_ms(1000);
		PORTA=0x02;
		_delay_ms(1000);
		PORTA=0x04;
		_delay_ms(1000);
        
    }
}