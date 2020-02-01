/*
 * GccApplication1.c
 *
 * Created: 1/9/2020 10:53:44 PM
 *  Author: AVINASH CHAUDHARY
 */ 


#include <avr/io.h>

int main(void)
{
	DDRC=0xff;
	DDRA=0x00;
    while(1)
    {
	  if(PINA&(1<<0))
	  {
		  PORTC=0x01;
	  }
	  else if(PINA&(1<<1))
	  {
		  PORTC=0x04;
	  }	
	  else if(PINA&(0x05))
	  {
	     PORTC=0x05;		  
	  }  
	  
	  else
	      PORTC=0x00;
	  }    
}