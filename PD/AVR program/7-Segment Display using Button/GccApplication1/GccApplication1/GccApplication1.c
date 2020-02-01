/*
 * GccApplication1.c
 *
 * Created: 1/9/2020 12:34:14 PM
 *  Author: AVINASH CHAUDHARY
 */ 


#include <avr/io.h>
#include <util/delay.h>
unsigned char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int main(void)
{
	DDRC=0xff;
	DDRA=0x00;
    while(1)
    {
		if(PINA&(1<<0))
		
		{	
		for(int i=0;i<=9;i++)
		{
			PORTC=arr[i];
			_delay_ms(1000);
		}
		}
		else
		    PORTC=0x00;		
        
    }
}