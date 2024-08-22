/*
 * ProgramCount.c
 *
 * Created: 2/6/2024 3:19:52 PM
 * Author : Afzal Hossan
 */ 

#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>

#define JUMP 7
#define BNEQ 6
#define	BEQ	 5
#define ZF	 4
#define OFFSET_SIGN 3

void initialize() {
	MCUCSR|=(1<<JTD);
	MCUCSR|=(1<<JTD);
	
	DDRA = 0xFF;	// Next address
	DDRB = 0x00;	// Clock at pin 0
	DDRC = 0x00;	// Branch Offset: 3-0, jump: 7, bneq: 6, beq:5, zeroFlag: 4
	DDRD = 0x00;	// Jump address
	
	PORTA = 0x00;	// Initial PC=0
}

int main(void)
{
    initialize();
	
	unsigned char prevCLK = 0;
	unsigned char Clock = 0;
	unsigned char nextIns = 0;
		
	unsigned char beq = 0;
	unsigned char bneq = 0;
	unsigned char jump = 0;
	unsigned char zeroFlag = 0;
	
	unsigned char branchOffset = 0;
	unsigned char offsetSign = 0;
	
	unsigned char jumpAddress = 0;
		
    while (1) 
    {
		Clock = PINB;
				
		if(!prevCLK && Clock)
		{
			jump = PINC & (1 << JUMP);
			beq = PINC & (1 << BEQ);
			bneq = PINC & (1 << BNEQ);
			zeroFlag = PINC & (1 << ZF);
			
			branchOffset = PINC & (0x0F);
			offsetSign = branchOffset & (1 << OFFSET_SIGN);
			
			jumpAddress = PIND;
			
			nextIns += 1;
			
			if(jump)
			{
				nextIns = jumpAddress;
			}
			else if((beq && zeroFlag) || (bneq && !zeroFlag))
			{
				if(offsetSign)
				{
					branchOffset |= 0xF0;
				}
				nextIns += branchOffset;
			}
			_delay_ms(100);
		}
		else if(prevCLK && !Clock){
			_delay_ms(100);
		}
		PORTA = nextIns;
		prevCLK = Clock;
    }
}

