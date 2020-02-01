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

void Rx()
{
	
	while((UCSRA &(1<< RXC))==0);
	PORTA = UDR;
	
	
}


int main(void)
{ 
	DDRA = 0xff;
	usart_init();
    while(1)
    {
		Rx();
        //TODO:: Please write your application code 
    }
}