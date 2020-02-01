/*
 * USARTTX.c
 *
 * Created: 13-01-2020 13:04:43
 *  Author: SHIKHAR RAJPUT
 */ 

#define f_cpu 8000000UL
#include <avr/io.h>
#include <util/delay.h>

void usart_init()
{
	UCSRB = UCSRB|1<<TXEN|1<<RXEN ;
	UCSRC = UCSRC|1<<URSEL|1<<UCSZ0|1<<UCSZ1 ;
	UBRRL = 51 ;
}

void usart_string(char *x)
{
	while(*x)
	{
		UDR=*x;
		while((UCSRA&(1<<UDRE))==0){}
			x++;
			_delay_ms(500);
	}
}
void tx(char x)
{
	UDR = x ;
	while((UCSRA&(1<<UDRE)) == 0){}   // wait 
	
}

int main(void)
{
	usart_init() ;
	//tx('A');
	//tx('B');
	//tx('C');
	usart_string("HMRITM DELHI");
    while(1)
    {
         
    }
}