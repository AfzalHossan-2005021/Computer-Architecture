/*
 * InstructionMemory.c
 *
 * Created: 2/6/2024 4:23:22 PM
 * Author : Afzal Hossan
 */ 

#include <avr/io.h>

char InsMem[][2] = {
	{0b00000010, 0b01100010},
	{0b00010011, 0b00110101},
	{0b00100010, 0b00110100},
	{0b00110010, 0b01010010},
	{0b01000010, 0b00110010},
	{0b01010011, 0b00110011},
	{0b01100100, 0b01010100},
	{0b01110011, 0b00110101},
	{0b10000101, 0b01010001},
	{0b10010011, 0b01000100},
	{0b10100100, 0b01000011},
	{0b11000011, 0b01000010},
	{0b11110011, 0b00110010},
	{0b00000011, 0b00000011},
	{0b11000101, 0b00100101},
	{0b11110101, 0b01000101},
	{0b00000100, 0b00000100},
	{0b01000000, 0b00000001},
	{0b01110001, 0b00010100},
	{0b11010001, 0b00101110},
	{0b01110001, 0b00010100},
	{0b10100001, 0b00010100},
	{0b11100001, 0b00101110},
	{0b01110001, 0b00010100},
	{0b11000001, 0b01010011},
	{0b11000110, 0b00010000},
	{0b10100110, 0b01100001},
	{0b11110001, 0b01110011},
	{0b11000110, 0b01110000},
	{0b10100110, 0b01100001},
	{0b01110110, 0b01100001},
	{0b11110110, 0b00010000},
	{0b01000001, 0b00000001},
	{0b01110110, 0b01100001},
	{0b11110110, 0b00010000},
	{0b01000001, 0b00000001},
	{0b10110000, 0b00000000}
};

void initialize() {
	MCUCSR |= (1 << JTD);
	MCUCSR |= (1 << JTD);
	
	DDRA = 0xFF;	// Opcode output
	DDRB = 0x00;	// Address input
	DDRC = 0xFF;	// RegSrc1: 7-4, RegSrc2: 3-0 and jump address 7-0
	DDRD = 0xFF;	// RegDst: 3-0
	
	PORTA = 0x00;	// Just initialize output
	PORTC = 0x00;	// Just initialize output
}



int main(void)
{
	initialize();
    
    while (1) 
    {
		PORTA = InsMem[PINB][0] >> 4;
		PORTC = (InsMem[PINB][0] << 4) | (InsMem[PINB][1] >> 4);
		PORTD = InsMem[PINB][1] & 0x0F;
    }
}

