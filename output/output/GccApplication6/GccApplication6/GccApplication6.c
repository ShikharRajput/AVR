/*
 * GccApplication5.c
 *
 * Created: 08-Jan-20 1:50:07 PM
 *  Author: NIC
 */ 


#include <avr/io.h>
#include <util/delay.h>
unsigned char arr[4]={0x09,0x06};
void main(void)
{ int j =0;
	DDRD = 0xff;
	DDRA = 0x00;
    while(1)
    {
		if(PINA & (1<<0))
		{
			
			PORTD = arr[j++];
			_delay_ms(1000);
			PORTD = 0x00;
			_delay_ms(1000);
			while((PINB & (1<<0)));
		}
	}		
}