/*
 * GccApplication3.c
 *
 * Created: 08-Jan-20 11:04:33 AM
 *  Author: NIC
 */ 


#include <avr/io.h>
#include <util/delay.h>
unsigned char arr[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};

void main(void)
{   
	DDRA = 0xff;
	DDRD = 0x00;
	
	int j = 0;
    while(1)
    {
		if( PIND &(1<<0))
		{
			PORTA = arr[j++];
			while((PIND &(1<<0)));	//debouncing	
		}		 
		if(j==10)
		{ j=0;
		}			
        //TODO:: Please write your application code 
    }
}