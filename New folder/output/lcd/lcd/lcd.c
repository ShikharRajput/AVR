/*
 * lcd.c
 *
 * Created: 10-01-2020 09:42:30
 *  Author: SHIKHAR RAJPUT
 */ 


#include <avr/io.h>
#include <util/delay.h>

#define rs 2
#define rw 6
#define en 0
void lcd_string(char *);
void lcd_cmd(char );
void lcd_data(char );
void lcd_init();

int main(void)
{
	DDRA=DDRA|1<<0|1<<2|1<<6;
	DDRB=0xff;
	
	lcd_init();
	//lcd_data('A');
	lcd_string("SHIKHAR SINGH TONDAK");
	
    while(1)
    {
		lcd_cmd(0x18);  //left
		//lcd_cmd(0x1c); //right
		_delay_ms(500);
        //TODO:: Please write your application code 
    }
}

void lcd_init()
{
	lcd_cmd(0x38);
	lcd_cmd(0x0e);
	lcd_cmd(0x06);
	lcd_cmd(0xc0);
}

void lcd_data(char x)
{
	PORTB=x;
	PORTA=PORTA|1<<rs;
	PORTA=PORTA&~(1<<rw);
	PORTA=PORTA|1<<en;
	_delay_ms(1);
	PORTA=PORTA&~(1<<en);
	_delay_ms(1);
}

void lcd_cmd(char x)
{
	PORTB=x;
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
		_delay_ms(100);
	}
}