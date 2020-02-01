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
	DDRB = 0xff;
	//int n = sizeof(arr);
	
    while(1)
    {
		for(int i =0; i<=9; i++)
		{
				PORTA = arr[i];
			for(int j=0; j<=9; j++)
			{
				PORTB = arr[j];
				_delay_ms(1000);
			}
		}							
		 
        //TODO:: Please write your application code 
    }
}