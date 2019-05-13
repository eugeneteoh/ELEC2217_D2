/*
 * D2_8bit_unsigned_mult.c
 *
 * Created: 9/5/2019 2:10:43 PM
 * Author : User
 */ 

#define F_CPU 12000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "debug.h"
#include "74HCT164.h"

volatile uint16_t outputXY;

void write_display(uint8_t inputX_arg, uint8_t inputY_arg);

int main(void)
{
	char inputX_str [9];
	char inputY_str [9];
	uint8_t inputX, inputY;
	
	// Port A = Il Matto input, chip output (0-7 bits)
	DDRA = 0x00;
	// Port B = Il Matto input, chip output (8-15 bits)
	DDRB = 0x00;
	
	init_debug_uart0();
	shiftInit_0();
	shiftInit_1();
 
    while (1) 
    {
		printf("Enter input X: ");
		fgets(inputX_str, 9, stdin);
		inputX = atoi(inputX_str);
		printf("\n");
		_delay_ms(100);
		printf("Enter input Y: ");
		fgets(inputY_str, 9, stdin);
		inputY = atoi(inputY_str);
		printf("\n");
		_delay_ms(100);
		write_display(inputX, inputY);
		printf("\n");
		_delay_ms(100);
    }
}

void write_display(uint8_t inputX_arg, uint8_t inputY_arg)
{
	// write X
	shiftWrite_0(inputX_arg);
	// write Y
	shiftWrite_1(inputY_arg);
	// read XY
	outputXY = (PINB<<8) | PINA;
	
	uint16_t trueXY;
	trueXY = inputX_arg * inputY_arg;
	if (trueXY == outputXY)
	{
		printf("%u x %u = %u	OK", inputX_arg, inputY_arg, outputXY);
	}
	else
	{
		printf("%u x %u = %u	ERROR	%d", inputX_arg, inputY_arg, outputXY, trueXY);
	}
}