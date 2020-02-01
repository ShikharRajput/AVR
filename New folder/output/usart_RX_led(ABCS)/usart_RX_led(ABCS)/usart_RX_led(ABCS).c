/*
 * usart_tx_1.c
 *
 * Created: 14-Jan-20 8:48:28 AM
 *  Author: NIC
 */ 

#define F_cpu 8000000UL
#include <avr/io.h>
#include <util/delay.h>


void usart_init()
{
	UCSRB = UCSRB |1<<RXEN;
	UCSRC = UCSRC | 1<<URSEL | 1<< UCSZ0 | 1<< UCSZ1;
	UBRRL = 51;
	
	
}

void Rx()
{
	char y;
	while((UCSRA&(1<< RXC))==0){}
	y = UDR;
	if (y=='A')
	{
		PORTA |= 0x01;
		
	}
	
	else if (y=='B')
	{
		PORTB |= 0x01;
		
	}
	
	else if (y=='C')
	{
		PORTC |= 0x01;
		
	}
	
	else if (y=='S')
	{
		PORTA = 0x00;
		PORTB = 0x00;
		PORTC = 0x00;
		
	}
	
}


int main(void)
{ 
	DDRA = 0xff;
	DDRB = 0xff;
	DDRC = 0xff;
	//DDRD = 0x00;
	usart_init();
    while(1)
    {
		Rx();
        //TODO:: Please write your application code 
    }
}