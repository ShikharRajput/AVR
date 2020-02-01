/*
 * GccApplication1.c
 *
 * Created: 13-01-2020 14:33:40
 *  Author: SHIKHAR RAJPUT
 */ 


#define F_CPU 8000000UL
#include <avr/io.h>

void usart_init();
char rx();
int main(void)
{
	char x;
	DDRA=0x07;
	usart_init();
    while(1)
    {
		x=rx();
        if (rx()=='A')
        {
			PORTA|=0x01;
        }
		
		else if (rx()=='B')
		{
			PORTA|=0x02;
		}
		
		else if (rx()=='C')
		{
			PORTA|=0x04;
		}
		
		else if (rx()=='S')
		{
			PORTA=0x00;
		}
    }
}

void usart_init()
{
	UCSRB=UCSRB|1<<RXEN;
	UCSRC=UCSRC|1<<URSEL|1<<UCSZ0|1<<UCSZ1;
	UBRRL=0x33;
}

char rx()
{
	while((UCSRA&(1<<RXC))==0){}
		return UDR;
}