/*
 * exer.c
 *
 * Created: 1/13/2020 2:05:40 PM
 *  Author: Hp
 */ 


#include <avr/io.h>
//#include <delay.h>


void usart_init()
{
	UCSRB=UCSRB|1<<TXEN|1<<RXEN;
	UCSRC=UCSRC|1<<URSEL|1<<UCSZ0|1<<UCSZ1;
	UBRRL=51;
}
void Rx()
{
	UDR='A';
	while((UCSRA&(1<<UDRE))==0)
	{
		PORTA=PORTA&1<<0X01;
	}
	UDR='B';
	while((UCSRA&(1<<UDRE))==0)
	
	{
		PORTA=PORTA&1<<0X02;
	}
	UDR='C';
	while((UCSRA&(1<<UDRE))==0)
	
	{
		PORTA=PORTA&1<<0X03;
	}
	
	
}

void usart_string(char *x)
{
	while(*x !='\0')
	{
		UDR=*x;
	while((UCSRA&(1<<UDRE))==0){}
	x++;
//	_delay_ms(1000);
}
}

int main(void)
{
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}