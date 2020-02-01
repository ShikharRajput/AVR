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
	UCSRB = UCSRB |1<<RXEN;
	UCSRC = UCSRC | 1<<URSEL | 1<< UCSZ0 | 1<< UCSZ1;
	UBRRL = 51;
	
	
}

char Rx()
{
	
	while((UCSRA&(1<< RXC))==0){}
	return UDR;

}


int main(void)
{ 
	DDRA = 0x07;
	DDRD = 0x00;
	usart_init();
    while(1)
    {
		if (Rx()=='A')
		{
			PORTA |= 0x01;          //A
			
		}
		
		else if (Rx()=='B')
		{
			PORTA |= 0x02;           //BB
			
		}
		
		else if (Rx()=='C') 
		{
			PORTA |= 0x04;             //CCC
			
		}
		
		else if (Rx()=='S')
		{
			PORTA = 0x00;            //SSSS
			
		}
		//TODO:: Please write your application code
	}
		
	
	 
}