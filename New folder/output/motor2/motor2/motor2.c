/*
 * motor2.c
 *
 * Created: 14-01-2020 13:01:16
 *  Author: SHIKHAR RAJPUT
 */ 


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
		
		if ((PINB&(1<<0))&&((PINB&(1<<3))==0))
		{
			PORTD=0x06;
		}
		
		
		
		
		if (((PINB&(1<<0))==0)&&((PINB&(1<<3))))
		{
			PORTD=0x09;
		}
		
		
		
		if (((PINB&(1<<0))==0)&&((PINB&(1<<3))==0))
		{
			PORTD=0x0a;
		}
		
		
		if (((PINB&(1<<0)))&&((PINB&(1<<3))))
		{
			PORTD=0x05;
		}
    }
}