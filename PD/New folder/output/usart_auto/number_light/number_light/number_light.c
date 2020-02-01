/*
 * number_light.c
 *
 * Created: 13-01-2020 14:58:35
 *  Author: SHIKHAR RAJPUT
 */ 


#define F_CPU 8000000UL
#include <avr/io.h>

char arr[] = {0,1,2,3,4,5,6,7,8,9,1,2};
void usart_init();
int a = 0;
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
	
for(int i=0; i<=11; i++){
	while((UCSRA&(1<<RXC))==0){}
		x = UDR;
		if(x != arr[i]){
			break;
		}a++;
	
}if(a==12){
		PORTA = 0x01;
	}a = 0;
}