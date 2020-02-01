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

void counter_init()
{
	TCCR0 = 0x06;
	TCNT0 = 0x00;

}

void count()
{
	int a;
	do{
		a=TCNT0;
		ascii_conversion(a);
		
		}while((TIFR & (1<<TOV0))==0);
	
}


void ascii_conversion(int a)
{
	char pos= 0xc2;
	int i, a1;
	for (i=0; i<3; i++)
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
	PORTA  = x & 0xf0;
	PORTA = PORTA &~ (1<<0);
	PORTA = PORTA &~ (1<<1);
	PORTA = PORTA | 1<<2;
	_delay_ms(1);
	PORTA = PORTA &~ (1<<2);
	_delay_ms(1);
	
	PORTA = (x<<4) & 0xf0;
	PORTA = PORTA &~ (1<<0);
	PORTA = PORTA &~ (1<<1);
	PORTA = PORTA | 1<<2;
	_delay_ms(1);
	PORTA = PORTA &~ (1<<2);
	_delay_ms(1);

}
void lcd_data_enable(char y)                 //to activate data register
{
	char x;
	PORTA= y & 0xf0;
	PORTA = PORTA | (1<<0);
	PORTA = PORTA &~ (1<<1);
	PORTA = PORTA | 1<<2;
	_delay_ms(1);
	PORTA = PORTA &~ (1<<2);
	_delay_ms(1);
	
	x = y<<4;
	PORTA = x & 0xf0;
	PORTA = PORTA | (1<<0);
	PORTA = PORTA &~ (1<<1);
	PORTA = PORTA | 1<<2;
	_delay_ms(1);
	PORTA = PORTA &~ (1<<2);
	_delay_ms(1);
}

void lcd_init()
{
	lcd_cmd_enable(0x02);                   /* cursor return to home */
	lcd_cmd_enable(0x28);                     /* Initialization of 16X2 LCD in 4bit mode */
	lcd_cmd_enable(0x0e);                    /* Display ON Cursor OFF */

	lcd_cmd_enable(0x06);                     /* Auto Increment cursor */
	
}

void lcd_string(char *x)
{
	
	while(*x!=0)
	{
		
		lcd_data_enable(*x);
		x++;
		_delay_ms(500);
	}
}	


int main(void)
{
	DDRA = 0x00;
	DDRA = 0xff;
	counter_init();
	
	lcd_init();
	//adc_init();
	lcd_cmd_enable(0x10);                         /* clear display */
	
	lcd_cmd_enable(0x80);                          /* cursor at home position */
	
	
	while(1)
	{
		count();
	
	}
}