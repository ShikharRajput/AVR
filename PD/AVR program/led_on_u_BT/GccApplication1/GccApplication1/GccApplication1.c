#define f_CPU 800000UL
#include <avr/io.h>
#include <util/delay.h>

void usart_init();
void rx();

int main(void)
{
	DDRA=0x01;
	DDRB=0x01;
	DDRC=0x01;

	usart_init();
	
	while(1)
	{
		rx();
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
	char x;
	
while((UCSRA&(1<<RXC))==0){}
x=UDR;

if(x=='A')
{ 
	PORTA=0x01;


}	
else if(x=='B')
{
	PORTB=0x01;
	
}
else if(x=='C')
{
	PORTC=0x01;
	
}
else if(x=='S')
{
	PORTA=0x00;
	PORTB=0x00;
	PORTC=0x00;
}
}
