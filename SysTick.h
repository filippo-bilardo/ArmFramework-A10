// SysTickInts.h
// Runs on LM4F120
// Use the SysTick timer to request interrupts at a particular period.
// Daniel Valvano
// October 11, 2012

/* This example accompanies the book
   "Embedded Systems: Real Time Interfacing to Arm Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2012
   Program 5.12, section 5.7

 Copyright 2012 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */
#ifndef _SYSTICK
#define _SYSTICK

//--------------------------------------------------------------------------------------------------
//=== Global constants =============================================================================
//--------------------------------------------------------------------------------------------------
extern int ServoTick;
extern int ServoTestTick;
extern int DeltaChange;
#define LEDDOG_TH_MIN		1000	// 1000*100us = 100ms
#define LEDDOG_TL_MAX		10000	// 10000*100us = 1s
#define LedDogOn			LedBlueOn
#define LedDogOff			LedBlueOff
#define LedDogToggle		LedBlueToggle

//--------------------------------------------------------------------------------------------------
//=== Global function prototypes ===================================================================
//--------------------------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

// **************SysTickInit*********************
// Initialize Systick periodic interrupts
// Input: interrupt period
//        Units of period are 20ns (assuming 50 MHz clock)
//        Maximum is 2^24-1
//        Minimum is determined by lenght of ISR
// Output: none
void SysTickInit(unsigned long period);

// Interrupt service routine
// Executed every 20ns*(period)
void SysTickHandler(void);
void DelayUs(unsigned long delay);
void DelayMs(unsigned long delay);
void SysTickWait(unsigned long delay);
int SysTickTest(void);
void LedDogTask(void);

#ifdef __cplusplus
}
#endif
//--------------------------------------------------------------------------------------------------
#endif	//_SYSTICK

