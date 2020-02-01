/*
 * gsm__1.c
 *
 * Created: 16-01-2020 11:27:34
 *  Author: SHIKHAR RAJPUT
 */ 


#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

void usart_init()
{
	UCSRB = UCSRB|1<<TXEN|1<<RXEN ;
	UCSRC = UCSRC|1<<URSEL|1<<UCSZ0|1<<UCSZ1 ;
	UBRRL = 51 ;
}

void tx_string(char *x)
{
	while(*x)
	{
		UDR=*x;
	while((UCSRA&(1<<UDRE))==0){}
	x++;
	//_delay_ms(500);
}
}
void tx(char x)
{
	UDR = x ;
	while((UCSRA&(1<<UDRE)) == 0){}   // wait 
	
}

void GSM_CALL()
{
	char ctrlz[]={26};
		_delay_ms(500);
	tx_string("ATD9990480092;\r");
	_delay_ms(2000);
	tx_string(ctrlz);
	
}
void GSM_HANG()
{
	char ctrlz[]={26};
	_delay_ms(500);
	tx_string("ATH;\r");
	_delay_ms(2000);
	tx_string(ctrlz);
}
void msg()
{
	
	char ctrlz[]={26};
	tx_string("AT+CMGF=1;/r");
	_delay_ms(500);
	//tx_string("AT+CMGS="/9582369856;/"/r");
	_delay_ms(2000);
	tx_string("hello shriya");
	tx_string(ctrlz);
}

int main(void)
{
	DDRA=0x00;
	usart_init() ;
	
    while(1)
	{
       if(PINA&(1<<0))
	   {
		   GSM_CALL();
		   while(PINA&(1<<0));
      }
	   else if (PINA&(1<<1))
	   {
		   GSM_HANG();
		   while(PINA&(1<<1));
	   }
	 
	}	
	
  }