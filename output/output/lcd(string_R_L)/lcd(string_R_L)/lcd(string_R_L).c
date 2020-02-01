/*
 * lcd_pro_1.c
 *
 * Created: 09-Jan-20 2:38:45 PM
 *  Author: NIC
 */ 


#include <avr/io.h>
#include <util/delay.h>
void lcd_cmd_enable(char );
void lcd_data_enable(char );
void lcd_init(void);
void lcd_string(char *);
int main(void)
{
	DDRA = 0x07;
	DDRB = 0xff;
	
	lcd_init();
	lcd_cmd_enable(0x80);
	
	lcd_string("EKta Sharma");
    while(1)
    {
		for(int i=0; i<=15; i++)
		{
			lcd_cmd_enable(0x18);
			_delay_ms(100);
			
		}
		
        //TODO:: Please write your application code 
    }
}


void lcd_cmd_enable(char x)
{
	PORTB  = x;
	PORTA = PORTA &~ (1<<0);
	PORTA = PORTA &~ (1<<1);
	PORTA = PORTA | 1<<2;
	_delay_ms(1);
	PORTA = PORTA &~ (1<<2);
	_delay_ms(1);

}
void lcd_data_enable(char y)
{
	PORTB = y;
	PORTA = PORTA | (1<<0);
	PORTA = PORTA &~ (1<<1);
	PORTA = PORTA | 1<<2;
	_delay_ms(1);
	PORTA = PORTA &~ (1<<2);
	_delay_ms(1);
	
}

void lcd_init()
{
	lcd_cmd_enable(0x38);
	
	lcd_cmd_enable(0x0e);

	lcd_cmd_enable(0x06);
	
}

void lcd_string(char *x)
{
	
	while(*x!=0)
	{
		
		lcd_data_enable(*x);
		x++;
		_delay_ms(100);
	}
}