/*
 * lcd_pro_1.c
 *
 * Created: 09-Jan-20 2:38:45 PM
 *  Author: NIC
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
void lcd_cmd_enable(char );
void lcd_data_enable(char );
void lcd_init(void);
void lcd_string(char *);
int main(void)
{
	DDRA = 0xf7;
	
	lcd_init();
	lcd_cmd_enable(0x10);                         /* clear display */
	
	lcd_cmd_enable(0x80);                          /* cursor at home position */
	
	lcd_string("Ekta Sharma");
    while(1)
    {
		for(int i=0; i<=15; i++)
		{                                             //for scrawling
			lcd_cmd_enable(0x18);
			_delay_ms(1000);
			
		}
		
        //TODO:: Please write your application code 
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