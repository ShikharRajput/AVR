#include <avr/io.h>
#include <util/delay.h>
int main()
{
	unsigned char arr[] = [0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7d, 0x07, 0x7F, 0x6F];
	
	DDRA = 0x01;
	while(1){
		for(int i=0 ; i<=9 ; i++){
			PORTA = arr[i];
			_delay_ms(1000);
		}
		
	}
	
}