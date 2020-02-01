/*
 * adc_lcd.c
 *
 * Created: 15-Jan-20 11:21:19 AM
 *  Author: NIC
 */ 


#include <avr/io.h>
#define F_cpu 8000000UL

void adc_init()
{
	
	ADMUX = 0x40;
	ADCSRA = ADCSRA | 1<< ADEN | 1<< ADATE | 1<< ADPS0 | 1<<ADPS1 | 1<< ADPS2;
	
}

void conversion()
{
	ADCSRA = ADCSRA | 1<<ADSC ;
	while((ADCSRA&(1<<ADIF))==0){}
	PORTB = ADCL;
	//PORTD = (ADCH&(1<<0)&(1<<1));
	PORTD = ADCH;
}
int main(void)
{
	DDRA = 0x00;
	DDRB = 0xff;
	//DDRD = DDRD&(~0x03);
	DDRD = 0xff;
	adc_init();
    while(1)
    {
		conversion();
        //TODO:: Please write your application code 
    }
}