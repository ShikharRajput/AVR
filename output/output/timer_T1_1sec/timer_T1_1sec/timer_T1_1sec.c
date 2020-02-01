/*
 * timer_0.c
 *
 * Created: 16-Jan-20 10:12:34 PM
 *  Author: NIC
 */ 
//here delay of 70 micro second is generated with f_cpu 8Mhz and prescaler = 8
#define F_cpu 1000000UL
#include <avr/io.h>



void delay()
{
	

	TCCR1B = TCCR1B| 1<< CS12| 1<< CS10;     //nomal cpu frequency with prescaler =1024
	TCNT1 = 64560;
	while((TIFR & (1<<2))==0){}   //while overflow flag bit of timer0 is 0 i.e is not filled...counting continue
	TIFR= TIFR|1<<2;
		
	
	//TCCR0 = 0x05;     //nomal cpu frequency with prescaler =1024
	//TCNT0 = 0x00;
	//while((TIFR & (1<<0))==0){}   //while overflow flag bit of timer0 is 0 i.e is not filled...counting continue
	//TIFR= TIFR|1<<0;
}
int main(void)
{
	
	DDRA = 0x01;
    while(1)
    {
		delay();
		PORTA = 0x01;
		delay();
		PORTA = 0x00;
		delay();
        //TODO:: Please write your application code 
    }
}