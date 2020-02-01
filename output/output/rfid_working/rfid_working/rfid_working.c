


/*
 * usart_tx_1.c
 *
 * Created: 14-Jan-20 8:48:28 AM
 *  Author: NIC
 */ 

#define F_cpu 8000000UL
#include <avr/io.h>
#include <string.h>
#include <util/delay.h>

char card[] = "27001309DBE6" ;
char a[];
	
int i;

void usart_init()
{
	UCSRB = UCSRB |1<<RXEN;
	UCSRC = UCSRC | 1<<URSEL | 1<< UCSZ0 | 1<< UCSZ1;
	UBRRL = 0x33;
	
	
}

char Rx()
{

	for( i =0; i<12 ; i++)
		{	
			
			while((UCSRA&(1<< RXC))==0){}
			a[i] = UDR;
			
		}
	a[i]='\0';
	if(strcmp(card,a)==0)
	{
		PORTA=0x01;
	}
	
	else
	{
		PORTA = 0x00;
	}
		}	
	
	
/*void chk()
{
	if(strcmp(a,card)==0)
	{
		PORTA=0x01;
	}
	
	else
	{
		PORTA = 0x00;
	}
	
		
	
	
}*/


int main(void)
{ 
	DDRA = 0x01;
	DDRD = 0x00;
	usart_init();
    while(1)
    {
		Rx();
		
		//while((UCSRA&(1<< RXC))==0){}
		//i= UDR;
		/*if(i=='a')
		{
			PORTA = 0x01;
		}*/
	}		
}