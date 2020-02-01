/*
 * GccApplication2.c
 *
 * Created: 1/8/2020 7:36:29 PM
 *  Author: AVINASH CHAUDHARY
 */ 


#include <avr/io.h>

void delay(int);

int main(void)
{
	DDRA=0x01;
    while(1)
    {
		PORTA=0x01;
		delay(5000);
		PORTA=0x00;
		delay(5000);
		
    }
}
void delay(int n)
{
	for(int i;i<=n;i++)
	{
	}
			
	}