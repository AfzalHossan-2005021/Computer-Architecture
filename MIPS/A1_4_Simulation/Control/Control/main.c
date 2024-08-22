/*
 * Control.c
 *
 * Created: 2/6/2024 9:17:50 PM
 * Author : Afzal Hossan
 */ 

#include <avr/io.h>

#define or      0b00000000
#define ori     0b00000001
#define sub     0b00000010
#define sll     0b00000011
#define add     0b00000100
#define andi    0b00000101
#define and     0b00000110
#define addi    0b00000111
#define srl     0b00001000
#define nor     0b00001001
#define subi    0b00001010
#define j       0b00001011
#define sw      0b00001100
#define Beq     0b00001101
#define Bneq    0b00001110
#define lw      0b00001111

#define or_ctrl  	0b00001100
#define ori_ctrl 	0b00010100
#define sub_ctrl 	0b00001100
#define sll_ctrl 	0b00010100
#define add_ctrl 	0b00001100
#define andi_ctrl   0b00010100
#define and_ctrl 	0b00001100
#define addi_ctrl   0b00010100
#define srl_ctrl 	0b00010100
#define nor_ctrl 	0b00001100
#define subi_ctrl   0b00010100
#define j_ctrl   	0b10010000
#define sw_ctrl  	0b00010010
#define Beq_ctrl 	0b00100000
#define Bneq_ctrl   0b01000000
#define lw_ctrl  	0b00010101

#define ADD	0b00000000
#define SRL	0b00000001
#define OR	0b00000010
#define SLL	0b00000100
#define AND	0b00000101
#define NOR	0b00000110
#define SUB	0b00000111

void initialize()
{
	MCUCSR |= (1 << JTD);
	MCUCSR |= (1 << JTD);
	
	DDRA=0XFF; // jump:7	bneq:6	beq:5	ALUSrc:4	RegDst:3	RegWrite:2	MenWrite:1	MemToReg:0
	DDRB=0X00; // Input opcode: 3-0
	DDRC=0XFF; // ALU OpCode 2-0
	
	PORTA = 0x00;
	PORTC = 0x00;
}

int main(void)
{
    initialize();
    while (1) 
    {
		switch(PINB)
		{
            case or :
				PORTA = or_ctrl;
				PORTC = OR;
				break;
            case ori :
				PORTA = ori_ctrl;
				PORTC = OR;
				break;
            case sub :
				PORTA = sub_ctrl;
				PORTC = SUB;
				break;
            case sll :
				PORTA = sll_ctrl;
				PORTC = SLL;
				break;
            case add :
				PORTA = add_ctrl;
				PORTC = ADD;
				break;
            case andi :
				PORTA = andi_ctrl;
				PORTC = AND;
				break;
            case and :
				PORTA = and_ctrl;
				PORTC = AND;
				break;
            case addi :
				PORTA = addi_ctrl;
				PORTC = ADD;
				break;
            case srl :
				PORTA = srl_ctrl;
				PORTC = SRL;
				break;
            case nor :
				PORTA = nor_ctrl;
				PORTC = NOR;
				break;
            case subi :
				PORTA = subi_ctrl;
				PORTC = SUB;
				break;
            case j :
				PORTA = j_ctrl;
				PORTC = ADD;
				break;
            case sw :
				PORTA = sw_ctrl;
				PORTC = ADD;
				break;
            case Beq :
				PORTA = Beq_ctrl;
				PORTC = SUB;
				break;
            case Bneq :
				PORTA = Bneq_ctrl;
				PORTC = SUB;
				break;
            case lw :
				PORTA = lw_ctrl;
				PORTC = ADD;
				break;			
			default:
				break;
		}
    }
}

