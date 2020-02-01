/*
 * GccApplication1.c
 *
 * Created: 07-01-2020 15:08:36
 *  Author: SHIKHAR RAJPUT
 */ 


#include <avr/io.h>

int main(void)
{
    DDRD = DDRD & ~(1<<0) ;
    DDRB = DDRB | 1<<0 ;
    while(1)
    {
		if( PIND & 1<<0 ){
			PORTB = PORTB | 1<<0 ;
		}else{
			PORTB = PORTB & ~(1<<0);
		}		
    }
}