/*
 * GccApplication1.c
 *
 * Created: 10-01-2020 14:32:28
 *  Author: SHIKHAR RAJPUT
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	int i;
	DDRB=DDRB|1<<3;
	TCCR0=0x69;
	TCNT0=0;
	OCR0=0;
    while(1)
    {
        for (i=0;i<=255;i++)
        {
			OCR0=i;
			_delay_ms(20);
        }
		
		
		for (i=255;i>=0;i--)
		{
			OCR0=i;
			_delay_ms(20);
		}
    }
}