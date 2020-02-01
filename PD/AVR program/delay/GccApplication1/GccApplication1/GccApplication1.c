/*
 * GccApplication1.c
 *
 * Created: 1/10/2020 1:27:06 PM
 *  Author: AVINASH CHAUDHARY
 */ 

#define F_CPU 800000
#include <avr/io.h>

void delay();
int main(void)
{
	DDRA=0X01;
    while(1)
    {
		PORTA=0x01;
		delay();
		PORTA=0x00;
		delay();
    }
}
void delay()
{
	TCCR0=0x02;   ///0b00000010
	TCNT0=186;
	
	while((TIFR&(1<<0))==0){}
		TIFR=TIFR|(1<<0);
		
	
}