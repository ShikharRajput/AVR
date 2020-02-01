#define f_CPU 800000UL
#include <avr/io.h>

void usart_init();
void tx();

int main(void)
{
	usart_init();
	tx();
    while(1)
    {
    }
}
void usart_init()
{
	UCSRB=UCSRB|1<<TXEN|1<<RXEN;
	UCSRC=UCSRC|1<<URSEL|1<<UCSZ0|1<<UCSZ1;
	UBRRL=51;
}
void tx()
{
	UDR='B';
	
while((UCSRA&(1<<UDRE))==0){}

}
