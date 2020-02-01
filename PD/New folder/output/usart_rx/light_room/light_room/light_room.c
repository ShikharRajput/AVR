/*
 * light_room.c
 *
 * Created: 13-01-2020 13:50:18
 *  Author: SHIKHAR RAJPUT
 */ 


#define f_CPU 8000000UL
#include <avr/io.h>


void usart_init();
void rx();
int main(void)
{
	DDRA=0xff;
	DDRB=0xff;
	DDRC=0xff;
	
	usart_init();
	
	while(1)
	{
		rx();
		//TODO:: Please write your application code
	}
}

void usart_init()
{
	UCSRB=UCSRB|1<<RXEN;
	UCSRC=UCSRC|1<<URSEL|1<<UCSZ0|1<<UCSZ1;
	UBRRL=0x33;
}

void rx()
{
	
while((UCSRA&(1<<RXC))==0){}
//PORTA=UDR;
if(UDR == 'A')
{
	PORTA = PORTA|0x01;
}
else if(UDR == 'B')
{
	PORTA = PORTA|0x02;
}
else if(UDR == 'C')
{
	PORTC = PORTC|0x01;
}
else if(UDR == 'S')
{
	PORTA=PORTA|0x00;
	PORTB=PORTB|0x00;
	PORTC=PORTC|0x00;
}

}