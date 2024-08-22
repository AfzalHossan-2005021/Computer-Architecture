/*
 * RegisterFile.c
 *
 * Created: 2/6/2024 5:51:32 PM
 * Author : Afzal Hossan
 */ 

#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>

#define REG_WRITE 4
#define CLOCK 5

unsigned char RegFile[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void initialize() {
	MCUCSR |= (1 << JTD);
	MCUCSR |= (1 << JTD);
	
	DDRA = 0xFF;	// 7-4 Data1, 3-0 Data2
	DDRB = 0x00;	// 7-4 RegSrc1, 3-0 RegSrc2
	DDRC = 0x00;	// 5 Clock, 4 RegWrite, 3-0 DataIn
	DDRD = 0x00;	// 3-0 RegDst
	
	PORTD = 0x00;	// just initialize the output
}

int main(void)
{
    initialize();
	
	unsigned char curCLK = 0;
	unsigned char prevCLK = 0;
	unsigned char dataOut_1 = 0;
	unsigned char dataOut_2 = 0;
	
    while (1) 
    {
		curCLK = PINC & (1 << CLOCK);
		
		dataOut_1 = RegFile[(PINB >> 4)] << 4;
		dataOut_2 = RegFile[(PINB & 0x0F)] & 0x0F;
		PORTA = dataOut_1 | dataOut_2;
		
		if(!prevCLK && curCLK)
		{
			if(PINC & (1 << REG_WRITE)){
				RegFile[PIND] = PINC;
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

