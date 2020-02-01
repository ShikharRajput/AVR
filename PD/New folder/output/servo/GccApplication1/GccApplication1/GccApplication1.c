/*
 * GccApplication1.c
 *
 * Created: 10-01-2020 14:52:25
 *  Author: SHIKHAR RAJPUT
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	int i;
	DDRB=DDRB|1<<3;
	TCCR0=0x6d;
	TCNT0=0;
	OCR0=0;
    while(1)
    {
		for (i=0;i<4;i++)
		{
			OCR0=i;
		}
		_delay_ms(1000);
		
		
		for (i=4;i<16;i++)
		{
			OCR0=i;
		}
		_delay_ms(1000);
		
		for (i=18;i<27;i++)
		{
			OCR0=i;
		}
		_delay_ms(1000);
		
        //TODO:: Please write your application code 
    }
}