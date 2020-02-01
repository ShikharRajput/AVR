/*
 * GccApplication1.c
 *
 * Created: 1/9/2020 11:14:48 AM
 *  Author: AVINASH CHAUDHARY
 */ 


#include <avr/io.h>
#include <util/delay.h>
unsigned char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int main(void)
{
	DDRA=0xff;
	
    while(1)
    {
		for(int i=0;i<=9;i++)
		{
			PORTA=arr[i];
			_delay_ms(1000);
		}
        
    }
}