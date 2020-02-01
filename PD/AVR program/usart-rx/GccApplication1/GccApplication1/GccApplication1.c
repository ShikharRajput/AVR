#define f_CPU 800000UL
#include <avr/io.h>

void usart_init();
void rx();

int main(void)
{
	DDRA=0xff;
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
	PORTA=x; //porta=udr
}

