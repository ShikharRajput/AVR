/*
 * GccApplication1.c
 *
 * Created: 15-01-2020 11:00:37
 *  Author: SHIKHAR RAJPUT
 */ 

#define F_CPU 8000000UL
#define rs 1
#define rw 2
#define en 3

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>


void lcd_string(char *);
void lcd_cmd(char x);
void lcd_data(char x);
void lcd_init();
void adc_convert();
void adc_init();
int main(void)
{
	//float t;
	//float a;
	
	DDRD=0xff;
	DDRB=0xff;
	DDRA=DDRA|1<<1|1<<2|1<<3;
	
	lcd_init();
	
	
	
	adc_init();
    while(1)
    {
		adc_convert();
		
		//ADCSRA=ADCSRA|1<<ADSC;
		//while((ADCSRA&(1<<ADIF))==0){}
			//a=ADC;
			//t=((a*5)/1023)*100;
			//ascii(t);
    }
	
}

void adc_init()
{
	ADMUX=0x40;  // ref 5v channel adc0
	ADCSRA=ADCSRA|1<<ADEN|1<<ADATE|1<<ADPS0|1<ADPS1|1<<ADPS2;
}

void adc_convert()
{
	
	float a, v;
	ADCSRA=ADCSRA|1<<ADSC;
	while((ADCSRA&(1<<ADIF))==0){}
	//PORTB=ADCL;
	//PORTD=ADCH;
    a = ADC;
	v = (((a*5)/1023)*100);
	//t = v*100;
	//ascii(a);
	ascii(v);
	//ascii(t);
}


void lcd_init()
{
	lcd_cmd(0x38);
	lcd_cmd(0x0e);
	lcd_cmd(0x06);
	
}

void lcd_data(char x)
{
	PORTB=x;
	PORTA=PORTA|1<<rs;
	PORTA=PORTA&~(1<<rw);
	PORTA=PORTA|1<<en;
	_delay_ms(1);
	PORTA=PORTA&~(1<<en);
	_delay_ms(1);
}
void ascii(int a){
	char pos = 0xc3;
	int i, a1;
	for(i=0; i<=3; i++){
		lcd_cmd(pos);
		a1 = a%10;
		a /= 10;
		lcd_data(a1+48);
		pos-- ;
	}
}

void lcd_cmd(char x)
{
	PORTB=x;
	PORTA=PORTA&~(1<<rs);
	PORTA=PORTA&~(1<<rw);
	PORTA=PORTA|(1<<en);
	_delay_ms(1);
	PORTA=PORTA&~(1<<en);
	_delay_ms(1);
	
}

void lcd_string(char *x)
{
	while(*x !='\0')
	{
		lcd_data(*x);
		x++;
	}
}