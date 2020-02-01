/*
 * lcd_pro_1.c
 *
 * Created: 09-Jan-20 2:38:45 PM
 *  Author: NIC
 */ 


#include <avr/io.h>
#include <util/delay.h>
void lcd_cmd_enable(void);
void lcd_data_enable(void);

int main(void)
{
	DDRA = 0x07;
	DDRB = 0xff;
	
	PORTB = 0x38;
	lcd_cmd_enable();
	
	PORTB = 0x0e;
	lcd_cmd_enable();
	
	PORTB = 0x06;
	lcd_cmd_enable();

	
    PORTB = 0x80;
	lcd_cmd_enable();
	
	PORTB = 'A';
	lcd_data_enable();
    while(1)
    {
        //TODO:: Please write your application code 
    }
}


void lcd_cmd_enable()
{
	
	PORTA = PORTA &~ (1<<0);
	PORTA = PORTA &~ (1<<1);
	PORTA = PORTA | 1<<2;
	_delay_ms(1);
	PORTA = PORTA &~ (1<<2);
	_delay_ms(1);

}
void lcd_data_enable()
{
	PORTA = PORTA | (1<<0);
	PORTA = PORTA &~ (1<<1);
	PORTA = PORTA | 1<<2;
	_delay_ms(1);
	PORTA = PORTA &~ (1<<2);
	_delay_ms(1);
	
}