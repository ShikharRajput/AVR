/*
 * GccApplication1.c
 *
 * Created: 1/15/2020 11:00:51 AM
 *  Author: AVINASH CHAUDHARY
 */ 


#include <avr/io.h>
#define f_cpu 8000000UL

void adc_init();
void adc_convert();
int main(void)
{
	DDRB=0xff;
	DDRD=0xff;

     adc_init();
    while(1)
    {
        adc_convert(); 
    }
}

void adc_init()
{
	ADMUX=0x40;    //ref 5v channel 
	ADCSRA=ADCSRA|1<<ADEN|1<<ADATE|1<<ADPS0|1<<ADPS1|1<<ADPS2;
	
}	

void adc_convert()
{
	ADCSRA=ADCSRA|1<<ADSC;
	while((ADCSRA&(1<<ADIF))==0){}
		PORTB=ADCL;
		PORTD=ADCH;
		
}	
