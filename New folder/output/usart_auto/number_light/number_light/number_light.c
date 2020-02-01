/*
 * number_light.c
 *
 * Created: 13-01-2020 14:58:35
 *  Author: SHIKHAR RAJPUT
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
int i;
char arr[] = "0001163045";
char arr2[];
//20002C6F5437

void usart_init();
char rx();

char x;

int main(void)
{
	DDRA=0x01;
	usart_init();
	while(1)
	{
		rx() ;
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
//while((UCSRA&(1<<RXC))==0){}
	
for( i=0; i<=9; i++){
	while((UCSRA&(1<<RXC))==0){}
		arr2[i] = UDR ;
}arr2[i] = '\0'; 


if(strcmp(arr,arr2)==0)
{
	
	PORTA=0x01;
}
else 
{
	PORTA=0x00;
}
}