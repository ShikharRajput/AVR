/*
 * GccApplication1.c
 *
 * Created: 1/10/2020 9:00:25 AM
 *  Author: AVINASH CHAUDHARY
 */ 


#include <avr/io.h>
#include <util/delay.h>

void lcd_cmd_enable(char );
void lcd_data_enable(char );

int main(void)
{
	DDRA=0x07;
	DDRB=0xff;
	
	
	lcd_cmd_enable(0x38);
	lcd_cmd_enable(0x06);
	lcd_cmd_enable(0x0e);
	lcd_cmd_enable(0x80);

	lcd_data_enable('A');
	
	
	
    while(1)
    {
      
    }
}

void lcd_cmd_enable(char x)
{
	PORTB=x;
		PORTA=PORTA&~(1<<0);
		PORTA=PORTA&~(1<<1);
		PORTA=PORTA|(1<<2);
		_delay_ms(1);
		PORTA=PORTA&~(1<<2);
		_delay_ms(1);
	
}

void lcd_data_enable(char x)
{    
	PORTB=x;
	PORTA=PORTA|(1<<0);
	PORTA=PORTA&~(1<<1);
	PORTA=PORTA|(1<<2);
	_delay_ms(1);
	PORTA=PORTA&~(1<<2);
	_delay_ms(1);
	
}