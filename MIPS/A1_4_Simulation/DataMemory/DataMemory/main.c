/*
 * DataMemory.c
 *
 * Created: 2/7/2024 1:17:39 AM
 * Author : Afzal Hossan
 */ 

#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>

#define MEM_WRITE 0
#define CLK 1

unsigned char DataMem[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void initialize(){
	MCUCSR |= (1 << JTD);
	MCUCSR |= (1 << JTD);
	
	DDRA = 0xFF;	// DataOut: 3-0
	DDRB = 0x00;	// Address: 3-0
	DDRC = 0x00;	// MemWrite: 0, Clock: 1
	DDRD = 0x00;	// DataIn: 3-0
	
	PORTD = 0x00;	// Just initialize output
}

int main(void)
{
	initialize();
	
    unsigned char curCLK = 0;
	unsigned char prevCLK = 0;
	unsigned char memWrite = 0;
	
	PORTA = DataMem[PINB];
	
    while (1) 
    {
		curCLK = PINC & (1 << CLK);
		
		memWrite = PINC & (1 << MEM_WRITE);
		
		PORTA = DataMem[PINB];
		
		if(!prevCLK && curCLK)
		{
			if(memWrite){
				DataMem[PINB] = PIND;
			}
			_delay_ms(100);
		}
		else if(prevCLK && !curCLK)
		{
			_delay_ms(100);
		}
		prevCLK = curCLK;
    }
}

