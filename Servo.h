//==================================================================================================
//       _____   ____
//      |  ___| |  _ \
//      | |_    | |_| |
//      |  _|   |  _ /
//	    | |     | |_| |
//	www.|_|     |_____/-labs.blogspot.it
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
// Ver    	Date        Comment
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 1.0.0	27.11.13	Initial version
// 1.0.1	31.10.14	adeguamento commenti
//
//==================================================================================================
#ifndef _SERVO
#define _SERVO

//==================================================================================================
//=== Global constants =============================================================================
//--------------------------------------------------------------------------------------------------
#define SERVO_TH_MIN		14		// 15*100us = 1,5ms
#define SERVO_TL_MAX		200		// 200*100us = 20ms

#define SERVO_TEST_TH_MIN	2000	// 2000*100us = 200ms
#define SERVO_TEST_TL_MAX	15000	// 15000*100us = 1,5s

//--------------------------------------------------------------------------------------------------
//=== Global function prototypes ===================================================================
//--------------------------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

void ServoInit(void);
void ServoTask(void);
void ServoTestTask(void);
void ServoOff(void);
void ServoOn(void);
void ServoLedOn(void);
void ServoLedOff(void);
void ServoLedToggle(void);

#ifdef __cplusplus
}
#endif
//--------------------------------------------------------------------------------------------------
#endif	//_SERVO
