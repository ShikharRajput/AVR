/*
 * GccApplication1.c
 *
 * Created: 16-01-2020 9:30:04
 *  Author: Swarnima
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void usart_init();
void TX_strig(char *);

void GSM();
void gsm1();
int main(void)
{
	
	 DDRA|=(1<<2);
	 usart_init();
	while(1)
	{
		
		if(PINA&(1<<0)) //calling
		{
		    GSM();
			PORTA|=1<<2;
			
		}
		
		else if (PINA&(1<<1))
		{
			gsm1();
			PORTA&=~1<<2;
		}
					
	}
}

void usart_init()
{
	UCSRB=UCSRB|1<<TXEN|1<<RXEN; //TRANSMITTER ENABLE REGISTER B AND RECEIVER ENABLE REG B
	UCSRC=UCSRC|1<<URSEL|1<<UCSZ0|1<<UCSZ1; //REGC ENABLE ,CHARACTER SIZE FROM UCSZ0 AND UCSZ1
	UBRRL=0X33; //UBRRC LOWER BYTE WITH 51
}

void TX_strig (char *x)
{
  while(*x !='\0')
  {  
	  UDR=*x;
	while((UCSRA&(1<<UDRE))==0);
	     x++;
  }	
  
}

void GSM()
{
	char ctrlz[]={26};
		_delay_ms(500);
	TX_strig("ATD9990480092;\r");
	_delay_ms(2000);
	//TX_strig(ctrlz);
   
}

void gsm1()
{
	char ctrlz[]={26};
		_delay_ms(500);
	 TX_strig("ATH\r");
	 _delay_ms(2000);
	 TX_strig(ctrlz);
}