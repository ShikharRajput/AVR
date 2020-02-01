/*
 * GccApplication1.c
 *
 * Created: 1/9/2020 2:48:24 PM
 *  Author: AVINASH CHAUDHARY
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA=0x07;
	DDRB=0xff;
	
	PORTB=0x38;
	PORTA=PORTA&~(1<<0);
    PORTA=PORTA&~(1<<1);
	PORTA=PORTA|(1<<2);
	_delay_ms(1);
	PORTA=PORTA&~(1<<2);
	_delay_ms(1);
	
	PORTB=0x0e;
	PORTA=PORTA&~(1<<0);
    PORTA=PORTA&~(1<<1);
	PORTA=PORTA|(1<<2);
	_delay_ms(1);
	PORTA=PORTA&~(1<<2);
	_delay_ms(1);
	
	PORTB=66;
	PORTA=PORTA|(1<<0);
	PORTA=PORTA&~(1<<1);
	PORTA=PORTA|(1<<2);
	_delay_ms(1);
	PORTA=PORTA&~(1<<2);
	_delay_ms(1);
	
	
	
	

	
	
	
	
	
    while(1)
    {
      
    }
}