#include <avr/io.h>
#define f_cpu 8000000UL
#include <util/delay.h>

void lcd_cmd(char x);
void lcd_data(char x);
void adc_init();
void adc_convert( );
void lcd_string(char *x);
void lcd_init();
void ASCII(int x);

int main(void)
{
	DDRC=0x07;
	DDRB=0xff;
	adc_init();
	
	lcd_init();
    while(1)
    {
         adc_convert();
    }
}

void adc_init()
{
	ADMUX=0x40;    //ref 5v channel 
	ADCSRA=ADCSRA|1<<ADEN|1<<ADATE|1<<ADPS0|1<ADPS1|1<<ADPS2;
	
}	
void adc_convert()
{ 
	int x;
	ADCSRA=ADCSRA|1<<ADSC;
	while((ADCSRA&(1<<ADIF))==0){}
	x=ADC;
	ASCII( x);	
}
void lcd_init()
{
	lcd_cmd(0x38);
	lcd_cmd(0x0e);
	lcd_cmd(0x06);
	
	
}	
void lcd_cmd(char x)
{
	    PORTB=x;
		PORTC=PORTC&~(1<<0);
		PORTC=PORTC&~(1<<1);
		PORTC=PORTC|(1<<2);
		_delay_ms(1);
		PORTC=PORTC&~(1<<2);
		_delay_ms(1);
	
}

void lcd_data(char x)
{    
	PORTB=x;
	PORTC=PORTC|(1<<0);
	PORTC=PORTC&~(1<<1);
	PORTC=PORTC|(1<<2);
	_delay_ms(1);
	PORTC=PORTC&~(1<<2);
	_delay_ms(1);
	
}


void lcd_string(char *x)
{
	adc_convert();
	while(*x!='\0')
	{
		lcd_data(*x);
		x++;
			
	}
	
}

void ASCII(int x)
{
	char pos=0x83;
	int i,x1;
	for(i=0;i<=3;i++)
	{
		lcd_cmd(pos);
		x1=x%10;
		x=x/10;
		lcd_data(x1+48);
		pos--;
		
	}		
	
	
}