/*
 * usart_tx_1.c
 *
 * Created: 14-Jan-20 8:48:28 AM
 *  Author: NIC
 */ 


#include <avr/io.h>
#include <util/delay.h>
#define F_cpu 8000000UL
unsigned char arr[5] = {0,1,2,3,4} ;
	
int i,n=5;

void usart_init()
{
	UCSRB = UCSRB |1<<RXEN;
	UCSRC = UCSRC | 1<<URSEL | 1<< UCSZ0 | 1<< UCSZ1;
	UBRRL = 0x33;
	
	
}

char Rx()
{
	char RD[n];

	for( i =0; i<n ; i++)
		{	
			
			while((UCSRA&(1<< RXC))==0){}
			RD[i] = UDR;
			_delay_ms(1);
			
		}
		
	
	
	
	for(i = 0 ; i<n; i++)	
	{
		if( RD[i]!=arr[i])
			{
				break;
				
			}
	}
	if(i==n)
	{
		PORTA |= 0x01;
			
			
	}
	
}


int main(void)
{ 
	DDRA = 0x01;
	DDRD = 0x00;
	usart_init();
    while(1)
    {
		Rx();
	}		
}