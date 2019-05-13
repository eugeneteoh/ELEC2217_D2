/*
 * _74HCT164.c
 *
 * Created: 10/5/2019 2:20:30 AM
 *  Author: User
 */ 

#include <avr/io.h>
#include "74HCT164.h"

void shiftInit_0()
{
	HCT164_DDR |= (1<<HCT164_DSA_POS_0) | (1<<HCT164_DSB_POS_0) | (1<<HCT164_CP_0);
}

void shiftInit_1()
{
	HCT164_DDR |= (1<<HCT164_DSA_POS_1) | (1<<HCT164_DSB_POS_1) | (1<<HCT164_CP_1);
}

// Sends a clock pulse on CP
void shiftPulse_0()
{
	// Pulse the shift clock
	HCT164_PORT |= (1<<HCT164_CP_0);
	HCT164_PORT &= ~(1<<HCT164_CP_0);
}

void shiftPulse_1()
{
	// Pulse the shift clock
	HCT164_PORT |= (1<<HCT164_CP_1);
	HCT164_PORT &= ~(1<<HCT164_CP_1);
}


void shiftWrite_0(uint8_t data)
{
	// Set DSB high to enable DSA input
	HCT164DSBHigh_0();
	// Send each 8 bits serially
	// Order is MSB first
	for (uint8_t i = 0; i < 8; i++)
	{
		// Output the data on DS line according to the
		// Value of MSB
		if (data & 0b10000000)
		{
			// MSB is 1 so output high
			HCT164DSAHigh_0();
		}
		else
		{
			// MSB is 0 so output low
			HCT164DSALow_0();
		}
		shiftPulse_0(); // Pulse the clock line
		data = data << 1; // Now bring next bit at MSB position
	}
	// Set DSB low to disable DSA output
	HCT164DSBLow_0();
}

void shiftWrite_1(uint8_t data)
{
	// Set DSB high to enable DSA input
	HCT164DSBHigh_1();
	// Send each 8 bits serially
	// Order is MSB first
	for (uint8_t i = 0; i < 8; i++)
	{
		// Output the data on DS line according to the
		// Value of MSB
		if (data & 0b10000000)
		{
			// MSB is 1 so output high
			HCT164DSAHigh_1();
		}
		else
		{
			// MSB is 0 so output low
			HCT164DSALow_1();
		}
		shiftPulse_1(); // Pulse the clock line
		data = data << 1; // Now bring next bit at MSB position
	}
	// Set DSB low to disable DSA output
	HCT164DSBLow_1();
}