/*
 * lcd_4bit.c
 *
 * Created: 17-01-2020 09:54:13
 *  Author: SHIKHAR RAJPUT
 */ 


#include <avr/io.h>
#include <util/delay.h>
void lcd_string(char *);
void lcd_cmd(char x);
void lcd_data(char x);
void lcd_init();
int main(void)
{
	DDRB=0xff;
	lcd_init();
	lcd_data('A');
	lcd_cmd(0xc0);
	lcd_string("WELCOME TO HMR");
    while(1)
    {
        //TODO:: Please write your application code 
    }
}

void lcd_init()
{
	lcd_cmd(0x02);   // cursr return to home  
	lcd_cmd(0x28);    // init 4 bit mode
	lcd_cmd(0x06);
	lcd_cmd(0x0e);
	lcd_cmd(0x80);
}
void lcd_cmd(char x)
{
	PORTB=x&0xf0;
	PORTB=PORTB&~(1<<0);
	PORTB=PORTB&~(1<<1);
	PORTB=PORTB|1<<2;
	_delay_ms(1);
	PORTB=PORTB&~(1<<2);
	_delay_ms(1);
	
	PORTB=(x<<4)&0xf0;
	PORTB=PORTB&~(1<<0);
	PORTB=PORTB&~(1<<1);
	PORTB=PORTB|1<<2;
	_delay_ms(1);
	PORTB=PORTB&~(1<<2);
	_delay_ms(1);
}

void lcd_data(char x)
{
		PORTB=x&0xf0;
		PORTB=PORTB|(1<<0);
		PORTB=PORTB&~(1<<1);
		PORTB=PORTB|1<<2;
		_delay_ms(1);
		PORTB=PORTB&~(1<<2);
		_delay_ms(1);
		
		PORTB=(x<<4)&0xf0;
		PORTB=PORTB|(1<<0);
		PORTB=PORTB&~(1<<1);
		PORTB=PORTB|1<<2;
		_delay_ms(1);
		PORTB=PORTB&~(1<<2);
		_delay_ms(1);
}

void lcd_string(char *x)
{
	while(*x)
	{
		lcd_data(*x);
		x++;
		_delay_ms(500);
	}
}