/*
 * lcd_pro_1.c
 *
 * Created: 09-Jan-20 2:38:45 PM
 *  Author: NIC
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>

unsigned int y,z;

int voltage(int a)
{
	
	int v;
	
	v= ((5*a)/1023);
	return v;
		             
		
}

void ascii_conversion(int a,char pos)
{
	
	int i, a1;
	for (i=0; i<4; i++)
	{
		lcd_cmd_enable(pos);
		a1= a%10;
		a = a/10;
		lcd_data_enable(a1+48);                //asci value of zero is 48
		pos--;
		
	}
}

	
void lcd_cmd_enable(char x)                  //to activate command register i.e to use data pins(7-14) as command pins
{
	PORTB  = x;
	PORTD = PORTD &~ (1<<0);
	PORTD = PORTD &~ (1<<1);
	PORTD = PORTD | 1<<2;
	_delay_ms(1);
	PORTD = PORTD &~ (1<<2);
	_delay_ms(1);

}
void lcd_data_enable(char y)                 //to activate data register
{
	PORTB = y;
	PORTD = PORTD | (1<<0);
	PORTD = PORTD &~ (1<<1);
	PORTD = PORTD | 1<<2;
	_delay_ms(1);
	PORTD = PORTD &~ (1<<2);
	_delay_ms(1);
	
}

void adc_init()
{
	
	ADMUX = 0x40;
	ADCSRA = ADCSRA | 1<< ADEN | 1<< ADATE | 1<< ADPS0 | 1<<ADPS1 | 1<< ADPS2;
	
}

int conversion()
{   int k;
	ADCSRA = ADCSRA | 1<<ADSC ;
	while((ADCSRA&(1<<ADIF))==0){}
	k = ADC;
	return k;
      
//PORTD = (ADCH&(1<<0)&(1<<1));
}

void lcd_init()
{
	lcd_cmd_enable(0x38);                   /* Initialization of 16X2 LCD in 8bit mode */
	
	lcd_cmd_enable(0x0e);                    /* Display ON Cursor OFF */

	lcd_cmd_enable(0x06);                     /* Auto Increment cursor */
	
}



int main(void)
{
	DDRA = 0x00;
	DDRD = 0x07;
	DDRB = 0xff;
	
	lcd_init();
	adc_init();
	lcd_cmd_enable(0x10);                         /* clear display */
	
	lcd_cmd_enable(0x80);                          /* cursor at home position */
	
	
	while(1)
	{
		y= conversion();
		ascii_conversion(y,0x83);
		z = voltage(y);
		ascii_conversion(z,0xc3);
	
	}
}