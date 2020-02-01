/*
 * GccApplication1.c
 *
 * Created: 1/14/2020 9:27:42 AM
 *  Author: AVINASH CHAUDHARY
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA=0x03;
	
    while(1)
    {
		PORTA=0x01;
		_delay_ms(200);
		PORTA=0x00;
		_delay_ms(50);
		PORTA=0x01;
		_delay_ms(100);
		PORTA=0x00;
		_delay_ms(50);
			PORTA=0x01;
			_delay_ms(200);
			PORTA=0x00;
			_delay_ms(50);
			PORTA=0x01;
			_delay_ms(100);
			PORTA=0x00;
			_delay_ms(50);
    }
}