/*
 * motor.c
 *
 * Created: 08-01-2020 13:50:08
 *  Author: SHIKHAR RAJPUT
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD = 0xFF;
	DDRB = 0x00;
	
    while(1)
	{
		if(PORTB&(1<<0)==1 && PORTB&(1<<3)==1){
			PORTD = 0x06;
			//_delay_ms(1000);
		}else if(PORTB&(1<<0)==0 && PORTB&(1<<3)==1){
			PORTD = 0x0A;
			//_delay_ms(1000);
		}else if(PORTB&(1<<0)==1 && PORTB&(1<<3)==0){
			PORTD = 0x09;
			//_delay_ms(1000);
		}else{
			PORTD = 0x05;
			//_delay_ms(1000);
		}
		//_delay_ms(1000);
    }
}