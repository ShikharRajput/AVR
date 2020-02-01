/*
 * GccApplication1.c
 *
 * Created: 10-01-2020 13:25:55
 *  Author: SHIKHAR RAJPUT
 */ 

#define F_CPU 8000000
#include <avr/io.h>

int main(void)
{
	DDRA=0x01;
    while(1)
    {
		PORTA=0x01;
		delay();
		PORTA=0x00;
		delay();
        //TODO:: Please write your application code 
    }
}

void delay()
{
	TCCR0=0x03;   //0b00000010
	TCNT0=131;
	
	while((TIFR&(1<<TOV0))==0){}
		TIFR=TIFR|1<<TOV0;
}