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
	UCSRB = UCSRB |1<<TXEN;
	UCSRC = UCSRC | 1<<URSEL | 1<< UCSZ0 | 1<< UCSZ1;
	UBRRL = 51;
	
	
}

void TX_string(char *x)
{
	while(*x)
	{
		UDR = *x;
		while((UCSRA &(1<< UDRE))==0){}
		x++;
		_delay_ms(100);
	}		
}

void GSM_call()
{
	TX_string("ATD7503169933;\r");
	PORTA = 0x02;
}

void GSM_hang()
{
	TX_string("ATH\r");
	PORTA = 0x00;
}

void GSM_message()
{
	char ctrlz[]= {26};
	TX_string("AT+CMGF=1\r");
	_delay_ms(500);
//	PORTA = 0x04;
	TX_string("AT+CMGS=\"9990480092\"\r");
	_delay_ms(2000);
	TX_string("Pick your phone");
	_delay_ms(200);
	TX_string(ctrlz);
	//PORTA = 0x00;
}


int main(void)
{ 
	DDRA = 0x07;
	DDRD = 0x02;
	DDRB= 0x00;
	usart_init();
	//GSM_call();
	//GSM_hang();
	//GSM_message();
	
		
    while(1)
    {
		if(PINB&(1<<0))
		{
			TX_string("AT\r");
			PORTA = 0x01;
			while(PINB&(1<<0)){}
			PORTA = 0x00;
		}
		else if(PINB&(1<<1))
       {
	       GSM_call();
		   while(PINB&(1<<1)){}
       }
	   else if(PINB&(1<<2))
       {
	       GSM_hang();
		   while(PINB&(1<<2)){}
       }
	   else if(PINB&(1<<3))
       {
	       GSM_message();
		   PORTA=0x04;
		   while(PINB&(1<<3)){}
       }
    }
}