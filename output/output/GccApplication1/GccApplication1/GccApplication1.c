/*
 * GccApplication1.c
 *
 * Created: 08-Jan-20 9:56:11 AM
 *  Author: NIC
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD = DDRD |~(1<<0) ;
	DDRB = DDRB | 1<<0 ;

	
    while(1)
    {
		if( PIND & 1<<0)
		{
			PORTB = PORTB | 1<<0;
			//_delay_ms(1000);
			
		}
		else
		{
			PORTB = PORTB &(~1<<0);
			//_delay_ms(1000);
					
        //TODO:: Please write your application code 
    }
}}