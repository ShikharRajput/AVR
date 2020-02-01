/*
 * usart_tx_1.c
 *
 * Created: 14-Jan-20 8:48:28 AM
 *  Author: NIC
 */ 


#include <avr/io.h>
#include <util/delay.h>
#define F_cpu 8000000UL

void usart_init()
{
	UCSRB = UCSRB |1<<TXEN;
	UCSRC = UCSRC | 1<<URSEL | 1<< UCSZ0 | 1<< UCSZ1;
	UBRRL = 51;
	
	
}

void Tx(char x)
{
	
	UDR = x;
	while((UCSRA &(1<< UDRE))==0);
	_delay_ms(1000);
	
	
}

int main(void)
{
	usart_init();
	Tx('t');
	Tx('a');
    while(1)
    {
        //TODO:: Please write your application code 
    }
}