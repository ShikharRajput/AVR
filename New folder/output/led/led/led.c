/*
 * led.c
 *
 * Created: 09-01-2020 13:03:39
 *  Author: SHIKHAR RAJPUT
 */ 


#include <avr/io.h>
#include <util/delay.h>

void lcd_cmd_enable(char);
void lcd_data_enable(char);
void lcd_init();
int main(void)
{
	DDRA = DDRA|1<<0|1<<1|1<<2; //rest pins are as it is
	DDRB = 0xFF;//PORTB as output d0-d7
    lcd_init();
	
	lcd_cmd_enable(0x80);
	lcd_data_enable(65);
		while(1)
		{
	 		
		}

}
void lcd_cmd_enable(char x)
{
	PORTB = x;
		
	PORTA = 0b00000000;
	PORTA = PORTA&~(1<<2);
	_delay_ms(1);
	PORTA = PORTA|(1<<2);
	_delay_ms(1);	
	
	
}

void lcd_data_enable(char y)
{
	PORTB = y;
	PORTA = 0b00000001;
	
	PORTA = PORTA&~(1<<2);
	_delay_ms(1);
	PORTA = PORTA|(1<<2);
	_delay_ms(1);
		
}	
	
void lcd_init(void)
{
		lcd_cmd_enable(0x38);
		lcd_cmd_enable(0x0C);
		lcd_cmd_enable(0x06);
}		
