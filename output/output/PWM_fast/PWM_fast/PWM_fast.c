/*
 * PWM_fast.c
 *
 * Created: 17-Jan-20 9:36:11 AM
 *  Author: NIC
 */ 

#define f_cpu 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = DDRB |1<<3;
	TCCR0 = 0x69;
	TCNT0 = 0;
	OCR0 = 191;
	
    while(1)
    {
		for(int i = 0; i<255; i++)
		{
			OCR0=i;
			_delay_ms(30);
		}
		
		for(int j=255 ; j>=0; j--)
		{
			OCR0 = j;
			_delay_ms(30);
		}						
        //TODO:: Please write your application code 
    }
}