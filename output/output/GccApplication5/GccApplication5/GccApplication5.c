/*
 * GccApplication5.c
 *
 * Created: 08-Jan-20 1:50:07 PM
 *  Author: NIC
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD = 0xff;
    while(1)
    {
		PORTD = 0x09;
		_delay_ms(1000);
		PORTD = 0x00;
		_delay_ms(1000);
		PORTD = 0x06;
		_delay_ms(1000);
		PORTD = 0x00;
		_delay_ms(1000);
	}		
}