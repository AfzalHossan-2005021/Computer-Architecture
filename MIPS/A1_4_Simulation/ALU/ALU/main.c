/*
 * ALU.c
 *
 * Created: 2/7/2024 12:25:12 AM
 * Author : Afzal Hossan
 */ 

#include <avr/io.h>

#define ADD	0b00000000
#define SRL	0b00000001
#define OR	0b00000010
#define SLL	0b00000100
#define AND	0b00000101
#define NOR	0b00000110
#define SUB	0b00000111

void initialize(){
	MCUCSR |= (1 << JTD);
	MCUCSR |= (1 << JTD);
	
	DDRA = 0xFF;	// ALU result
	DDRB = 0x00;	// OpCode: 7-4, operand_1: 3-0
	DDRC = 0xFF;	// ZF: 0
	DDRD = 0x00;	// operand_2: 3-0
	
	PORTA = 0x00;	// Just initialize output
	PORTC = 0x00;	// Just initialize output
}

int main(void)
{
	initialize();
	
    unsigned char OpCode;
	unsigned char operand_1;
	unsigned char operand_2;
	unsigned char result;
    while (1) 
    {
		OpCode = PINB >> 4;
		operand_1 = PINB & 0x0F;
		operand_2 = PIND;
		result = -1;
		
		switch(OpCode)
		{
			case ADD :
				result = operand_1 + operand_2;
				break;
			case SRL :
				result = operand_1 >> operand_2; 
				break;
			case OR :
				result = operand_1 | operand_2;
				break;
			case SLL :
				result = operand_1 << operand_2;
				break;
			case AND :
				result = operand_1 & operand_2;
				break;
			case NOR :
				result = ~ (operand_1 | operand_2);
				break;
			case SUB :
				result = operand_1 - operand_2;
				break;
			default:
				break;
		}
		PORTA = result;
		PORTC = result == 0 ? 1 : 0;
    }
}

