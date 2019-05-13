/*
 * IncFile1.h
 *
 * Created: 10/5/2019 2:19:44 AM
 *  Author: User
 */ 

#include <avr/io.h>

#define HCT164_PORT PORTC
#define HCT164_DDR DDRC

#define HCT164_DSA_POS_0 PC0 // Data pin A (DSA) pin location
#define HCT164_DSB_POS_0 PC1 // Data pin B (DSB) pin location
#define HCT164_CP_0 PC2 // Clock input (CP) pin location

#define HCT164_DSA_POS_1 PC5 // Data pin A (DSA) pin location
#define HCT164_DSB_POS_1 PC6 // Data pin B (DSB) pin location
#define HCT164_CP_1 PC7 // Clock input (CP) pin location

// change data (DS) lines
#define HCT164DSAHigh_0() (HCT164_PORT|=(1<<HCT164_DSA_POS_0))
#define HCT164DSALow_0() (HCT164_PORT&=(~(1<<HCT164_DSA_POS_0)))
#define HCT164DSBHigh_0() (HCT164_PORT|=(1<<HCT164_DSB_POS_0))
#define HCT164DSBLow_0() (HCT164_PORT&=(~(1<<HCT164_DSB_POS_0)))

#define HCT164DSAHigh_1() (HCT164_PORT|=(1<<HCT164_DSA_POS_1))
#define HCT164DSALow_1() (HCT164_PORT&=(~(1<<HCT164_DSA_POS_1)))
#define HCT164DSBHigh_1() (HCT164_PORT|=(1<<HCT164_DSB_POS_1))
#define HCT164DSBLow_1() (HCT164_PORT&=(~(1<<HCT164_DSB_POS_1)))

void shiftInit_0();
void shiftPulse_0();
void shiftWrite_0(uint8_t data);

void shiftInit_1();
void shiftPulse_1();
void shiftWrite_1(uint8_t data);
