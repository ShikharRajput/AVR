/*
 * counter.c
 *
 * Created: 17-01-2020 13:07:41
 *  Author: SHIKHAR RAJPUT
 */ 
#define F_CPU 8000000UL
#define rs 0
#define rw 1
#define en 2

#include <avr/io.h>
#include <util/delay.h>

void counter_init();
void count();
void lcd_cmd(char);
void lcd_data(char);
void lcd_init();
void lcd_string(char *);
void ascii(int);

int x;
int main(void)
{
	DDRA = 0x07;
	DDRC = 0xff;
	DDRD = 0xff;
	counter_init();
	lcd_init();
    while(1)
    {
		count();
    }
}

void counter_init()
{
	TCCR0 = 0x06;
	TCNT0 = 0x00;
}

void count()
{
	do{
		x = TCNT0;
		ascii(x);
	}while((TIFR&(1<<TOV0)) == 0);
}

void ascii(int a)
{
	char pos = 0x83;
	int b;
	for(int i=0; i<3; i++)
	{
		lcd_cmd(pos);
		b = a%10;
		a = a/10;
		lcd_data(b+48);
		pos-- ;
	}
}

void lcd_cmd(char x)
{
	PORTD=x;
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



void lcd_init()
{
	lcd_cmd(0x38);
	lcd_cmd(0x0e);
	lcd_cmd(0x06);
	
}

void lcd_data(char x)
{
	PORTD=x;
	PORTA=PORTA|1<<rs;
	PORTA=PORTA&~(1<<rw);
	PORTA=PORTA|1<<en;
	_delay_ms(1);
	PORTA=PORTA&~(1<<en);

	_delay_ms(1);
}


/*void adc_init()
{
	ADMUX=0x40;  // ref 5v channel adc0
	ADCSRA=ADCSRA|1<<ADEN|1<<ADATE|1<<ADPS0|1<ADPS1|1<<ADPS2;
}

void adc_convert()
{
	float a;
	float v;
	ADCSRA=ADCSRA|1<<ADSC;
while((ADCSRA&(1<<ADIF))==0){}
a = ADC;
v = (((a*5)/1023)*100);
}*/
