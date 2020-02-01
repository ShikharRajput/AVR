#define f_CPU 800000UL
#include <avr/io.h>

char a[];
char card[]="20002C6F5437";
int i;

void usart_init();
void rx();
void chk();

int main(void)
{
	DDRA=0xff;
	usart_init();
	
	while(1)
	{
	rx();
	chk();
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
	for(i=0;i<12;i++)
	{
		while((UCSRA&(1<<RXC))==0){}
			a[i]=UDR;
			
	}
	a[i]='\0';
}


void chk()
{
	if((strcmp(a,card))==0)
	{
		PORTA=0x01;
	}		
	else
	{
		PORTA=0x00;
			
	}
}