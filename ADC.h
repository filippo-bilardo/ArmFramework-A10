// ADCSWTrigger.c
// Runs on LM4F120
// Provide functions that initialize ADC0 SS3 to be triggered by
// software and trigger a conversion, wait for it to finish,
// and return the result.
// Daniel Valvano
// October 8, 2012

/* This example accompanies the book
   "Embedded Systems: Real Time Interfacing to Arm Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2012

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

// There are many choices to make when using the ADC, and many
// different combinations of settings will all do basically the
// same thing.  For simplicity, this function makes some choices
// for you.  When calling this function, be sure that it does
// not conflict with any other software that may be running on
// the microcontroller.  Particularly, ADC0 sample sequencer 3
// is used here because it only takes one sample, and only one
// sample is absolutely needed.  Sample sequencer 3 generates a
// raw interrupt when the conversion is complete, but it is not
// promoted to a controller interrupt.  Software triggers the
// ADC0 conversion and waits for the conversion to finish.  If
// somewhat precise periodic measurements are required, the
// software trigger can occur in a periodic interrupt.  This
// approach has the advantage of being simple.  However, it does
// not guarantee real-time.
//
// A better approach would be to use a hardware timer to trigger
// the ADC0 conversion independently from software and generate
// an interrupt when the conversion is finished.  Then, the
// software can transfer the conversion result to memory and
// process it after all measurements are complete.

//==================================================================================================
//       _____   ____
//      |  ___| |  _ \
//      | |_    | |_| |
//      |  _|   |  _ /
//	    | |     | |_| |
//	www.|_|     |_____/-labs.blogspot.it
//
// Filename:    ADC
// Description: 
//    
// Open Source Licensing 
//
// This program is free software: you can redistribute it and/or modify it under the terms of 
// the GNU General Public License as published by the Free Software Foundation, either version 3 
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,but WITHOUT ANY WARRANTY; without
// even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with this program.  
// If not, see <http://www.gnu.org/licenses/>.
//
// Modify by:	Filippo Bilardo
//
// Ver    	Date        Comment
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 1.0.0	31.10.14 	Versione iniziale
//
//==================================================================================================
#ifndef _ADC
#define _ADC

//--------------------------------------------------------------------------------------------------
//=== Global function prototypes ===================================================================
//--------------------------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

//------------------------------------------------------------------------------------------
// Versione:		1.0.0
// Prima versione:	
// Ultima modifica:	
//  
// 	This initialization function sets up the ADC according to the
// 	following parameters.  Any parameters not explicitly listed
// 	below are not modified:
// 	Max sample rate: <=125,000 samples/second
// 	Sequencer 0 priority: 1st (highest)
// 	Sequencer 1 priority: 2nd
// 	Sequencer 2 priority: 3rd
// 	Sequencer 3 priority: 4th (lowest)
// 	SS3 triggering event: software trigger
// 	SS3 1st sample source: Ain9 (PE4)
// 	SS3 interrupts: enabled but not promoted to controller
extern void ADC0_InitSWTriggerSeq3_Ch9(void);

//------------------------------------------------------------------------------------------
// Versione:		1.0.0
// Prima versione:	
// Ultima modifica:	
//  
//	This initialization function sets up the ADC according to the
//	following parameters.  Any parameters not explicitly listed
//	below are not modified:
//	Max sample rate: <=125,000 samples/second
//	Sequencer 0 priority: 1st (highest)
//	Sequencer 1 priority: 2nd
//	Sequencer 2 priority: 3rd
//	Sequencer 3 priority: 4th (lowest)
//	SS3 triggering event: software trigger
//	SS3 1st sample source: programmable using variable 'channelNum' [0:7]
//	SS3 interrupts: enabled but not promoted to controller
//
void ADC0_InitSWTriggerSeq3(unsigned char channelNum);

//------------------------------------------------------------------------------------------
// Versione:		1.0.0
// Prima versione:	
// Ultima modifica:	
//
//	This initialization function sets up the ADC according to the
//	following parameters.  Any parameters not explicitly listed
//	below are not modified:
//	Max sample rate: <=125,000 samples/second
//	Sequencer 0 priority: 1st (highest)
//	Sequencer 1 priority: 2nd
//	Sequencer 2 priority: 3rd
//	Sequencer 3 priority: 4th (lowest)
//	SS3 triggering event: always trigger
//	SS3 1st sample source: programmable using variable 'channelNum' [0:11]
//	SS3 interrupts: enabled but not promoted to controller
void ADC0_InitAllTriggerSeq3(unsigned char channelNum);

//------------------------------------------------------------------------------------------
// Versione:		1.0.0
// Prima versione:	
// Ultima modifica:	
// Input: 			none
// Output: 			12-bit result of ADC conversion
//
//	Busy-wait Analog to digital conversion
//
unsigned long ADC0_InSeq3(void);

#ifdef __cplusplus
}
#endif
//--------------------------------------------------------------------------------------------------
#endif 	//_ADC
