/*
 * GccApplication1.c
 *
 * Created: 1/9/2020 10:41:25 AM
 *  Author: AVINASH CHAUDHARY
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC=0xff;
    while(1)
    {
		
		PORTC=0x3f;
		_delay_ms(1000);
		PORTC=0x06;
		_delay_ms(1000);
		PORTC=0x5b;
		_delay_ms(1000);
		PORTC=0x4f;
		_delay_ms(1000);
		PORTC=0x66;
		_delay_ms(1000);
		PORTC=0x6d;
		_delay_ms(1000);
		PORTC=0x7d;
		_delay_ms(1000);
		PORTC=0x07;
		_delay_ms(1000);
		PORTC=0x7f;
		_delay_ms(1000);
		PORTC=0x6f;
		_delay_ms(1000);
		
        
    }
}