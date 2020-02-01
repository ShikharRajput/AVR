#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

void usart_init();
void tx(char y);
void usart_string(char *);
void lcd_cmd(char x);
void lcd_data(char x);
void lcd_string(char *);
void lcd_init();

char rx();

char arr[] = "20002C6F5437";
char arr2[];

int i;

int main(void)
{
	DDRA = 0x0F;
	DDRB = 0xFF;
	//DDRD = 0x02;
	usart_init();
	lcd_init();
	//lcd_string("hello");
	
	while(1)
	{
		rx() ;
	}
}

void usart_init()
{
	UCSRB=UCSRB|1<<RXEN|1<<TXEN;
	UCSRC=UCSRC|1<<URSEL|1<<UCSZ0|1<<UCSZ1;
	UBRRL=0x33;
}

char rx()
{
//while((UCSRA&(1<<RXC))==0){}
	
	for( i=0; i<=11; i++)
	{
		while((UCSRA&(1<<RXC))==0){}
			arr2[i] = UDR ;
	}arr2[i] = '\0'; 


	if(strcmp(arr,arr2)==0)
	{
		lcd_string("ALERT !!!");
		lcd_cmd(0xc0);
		lcd_string("EMERGENCY");
		lcd_cmd(0x80);
		usart_string("Lat:28.824, Lon:77.152");
				
		while(1)
		{
			PORTA |= 0x01;
			_delay_ms(200);
			PORTA &= ~(1<<0);
		}
		
		
		//_delay_ms(500);
	}
	else 
	{
		PORTA &= ~(1<<0);
		lcd_cmd(0x01);
	}
}

void usart_string(char *y)
{
	while(*y)
	{
		UDR=*y;
		//tx(*y);
	while((UCSRA&(1<<UDRE))==0){}
	y++;
	_delay_ms(100);
}
}

void tx(char y)
{
	UDR = y ;
	while((UCSRA&(1<<UDRE)) == 0){}   // wait
	
}

void lcd_init()
{
	lcd_cmd(0x38);
	lcd_cmd(0x0e);
	lcd_cmd(0x06);
}

void lcd_cmd(char x)
{
	PORTB = x;
	PORTA=PORTA&~(1<<1);
	PORTA=PORTA&~(1<<2);
	PORTA=PORTA|(1<<3);
	_delay_ms(1);
	PORTA=PORTA&~(1<<3);
	_delay_ms(1);	
}

void lcd_data(char x)
{
	PORTB = x;
	PORTA=PORTA|(1<<1);
	PORTA=PORTA&~(1<<2);
	PORTA=PORTA|(1<<3);
	_delay_ms(1);
	PORTA=PORTA&~(1<<3);
	_delay_ms(1);
}

void lcd_string(char *x)
{
	while(*x)
	{
		lcd_data(*x);
		_delay_ms(50);
		x++;
	}
}