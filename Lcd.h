////////////////////////////////////////////////////////////////////////////////////////////////////
//       _____   ____
//      |  ___| |  _ \
//      | |_    | |_| |
//      |  _|   |  _ /
//	    | |     | |_| |
//	www.|_|     |_____/ -labs.blogspot.it
//
//
// Filename:    
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
// Author:	Filippo Bilardo
//
// Ver    Date        Comment
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 1.0.0	27.11.13 		Initial version
//
////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------------------------------------------------------
#ifndef _LED
#define _LED

//--------------------------------------------------------------------------------------------------
//=== Global constants =============================================================================
//--------------------------------------------------------------------------------------------------
#define LED0
#define LED1
#define LED2
#define LED3

//--------------------------------------------------------------------------------------------------
//=== Includes =====================================================================================
//--------------------------------------------------------------------------------------------------
#include "hw_types.h"

//--------------------------------------------------------------------------------------------------
//=== Global function prototypes ===================================================================
//--------------------------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

extern void LedInit(void);
extern void LedOn(void);
extern void LedOff(void);
extern void LedBlink(uint8_t val, uint16_t cont, uint16_t delay);
extern void LedTest(void);
extern void LedTest2(void);
extern void LedHex(uint8_t val);
#ifdef LED0
extern void Led0On(void);
extern void Led0Off(void);
extern void Led0Toggle(void);
#endif
#ifdef LED1
extern void Led1On(void);
extern void Led1Off(void);
extern void Led1Toggle(void);
#endif
#ifdef LED2
extern void Led2On(void);
extern void Led2Off(void);
extern void Led2Toggle(void);
#endif
#ifdef LED3
extern void Led3On(void);
extern void Led3Off(void);
extern void Led3Toggle(void);
#endif
extern void LedRedOn(void);
extern void LedRedOff(void);
extern void LedRedToggle(void);
extern void LedBlueOn(void);
extern void LedBlueOff(void);
extern void LedBlueToggle(void);
extern void LedGreenOn(void);
extern void LedGreenOff(void);
extern void LedGreenToggle(void);
extern void LedWhiteOn(void);
extern void LedWhiteOff(void);
extern void LedWhiteToggle(void);

#ifdef __cplusplus
}
#endif
//--------------------------------------------------------------------------------------------------
#endif //_LED
