//==================================================================================================
//       _____   ____
//      |  ___| |  _ \
//      | |_    | |_| |
//      |  _|   |  _ /
//	    | |     | |_| |
//	www.|_|     |_____/-labs.blogspot.it
//
// Filename:    hwconfig.h
// Description: Hardware abstraction layer for LM4F120
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
// Ver		Date   		Comment
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 1.0.0	12.11.12	Initial version
// 1.0.1	29.10.14 	adeguamento commenti
//
//==================================================================================================

#ifndef __HWCONFIG_H__
#define __HWCONFIG_H__

#ifdef __cplusplus
extern "C"
{
#endif

//--------------------------------------------------------------------------------------------------
//=== Includes =====================================================================================
//--------------------------------------------------------------------------------------------------
#include "lm4f120h5qr.h"

//--------------------------------------------------------------------------------------------------
//=== Global function prototypes ===================================================================
//--------------------------------------------------------------------------------------------------
// file startup.s
extern void DisableInterrupts(void); // Disable interrupts
extern void EnableInterrupts(void);  // Enable interrupts
extern long StartCritical (void);    // previous I bit, disable interrupts
extern void EndCritical(long sr);    // restore I bit to previous value
extern void WaitForInterrupt(void);  // low power mode

//--------------------------------------------------------------------------------------------------
//=== Global constants =============================================================================
//--------------------------------------------------------------------------------------------------
//
// Define pin mapping.
//
										//J1.01 3.3V
										//J1.02 PB5 57 AIN11 - SSI2Fss - T1CCP1 CAN0Tx - -
						//U1RX			J1.03 PB0 45 - U1Rx - - T2CCP0 - - -
						//U1TX			J1.04 PB1 46 - U1Tx - - T2CCP1 - - -
						//I2C2SCL		J1.05 PE4 59 AIN9 U5Rx - I2C2SCL - CAN0Rx - -
						//I2C2SDA		J1.06 PE5 60 AIN8 U5Tx - I2C2SDA - CAN0Tx - -
						//MOT1			J1.07 PB4 58 AIN10 - SSI2Clk - T1CCP0 CAN0Rx - -
						//P0_UP			J1.08 PA5 22 - - SSI0Tx - - - - -
						//P0_LEFT		J1.09 PA6 23 - - - I2C1SCL - - - -
						//P0_DOWN		J1.10 PA7 24 - - - I2C1SDA - - - -

										//J3.01 5.0V
										//J3.02 GND
						//SSI1Clk		J3.03 PD0 61 AIN7 SSI3Clk SSI1Clk I2C3SCL WT2CCP0 - - -
						//SSI1Fss		J3.04 PD1 62 AIN6 SSI3Fss SSI1Fss I2C3SDA WT2CCP1 - - -
						//SSI1Rx		J3.05 PD2 63 AIN5 SSI3Rx SSI1Rx - WT3CCP0 - - -
						//SSI1Tx		J3.06 PD3 64 AIN4 SSI3Tx SSI1Tx - WT3CCP1 - - -
						//MOT2			J3.07 PE1 8 AIN2 U7Tx - - - - - -
						//V_TRIM		J3.08 PE2 7 AIN1 - - - - - - -
						//P0_RIGHT		J3.09 PE3 6 AIN0 - - - - - - -
#define RED_LED_PIN				0x02	//J3.10 PF1 29 - U1CTS SSI1Tx - T0CCP1 - C1o TD1


										//J2.01 GND
#define SONAR_PIN						//J2.02 PB2 47 - - - I2C0SCL T3CCP0 - - -
#define SERVO_LED_PIN			0x01	//J2.03 PE0 9 AIN3 U7Rx - - - - - -
#define SW_RIGHT_PIN			0x01	//J2.04 PF0 28 - U1RTS SSI1Rx CAN0Rx T0CCP0 NMI C0o -
										//J2.05 RESET
										//J2.06 PB7 4 - - SSI2Tx - T0CCP1 - - -
										//J2.07 PB6 1 - - SSI2Rx - T0CCP0 - - -
										//J2.08 PA4 21 - - SSI0Rx - - - - -
										//J2.09 PA3 20 - - SSI0Fss - - - - -
										//J2.10 PA2 19 - - SSI0Clk - - - - -

#define BLUE_LED_PIN			0x04	//J4.01 PF2 30 - - SSI1Clk - T1CCP0 - - TRD0
#define GREEN_LED_PIN			0x08	//J4.02 PF3 31 - - SSI1Fss CAN0Tx T1CCP1 - - TRCLK
#define SERVO_PIN				0x08	//J4.03 PB3 48 - - - I2C0SDA T3CCP1 - - -
										//LCD_SCLK	J4.04 PC4 16 C1- U4Rx U1Rx - WT0CCP0 U1RTS - -
										//LCD_RS  	J4.05 PC5 15 C1+ U4Tx U1Tx - WT0CCP1 U1CTS - -
										//LCD_RST		J4.06 PC6 14 C0+ U3Rx - - WT1CCP0 - - -
										//LCD_CS		J4.07 PC7 13 C0- U3Tx - - WT1CCP1 - - -
										//P0_CENTER J4.08 PD6 53 - U2Rx - - WT5CCP0 - - -
										//SW1				J4.09 PD7 10 - U2Tx - - WT5CCP1 NMI - -
#define SW_LEFT_PIN				0x10	//J4.10 PF4 5 - - - - T2CCP0 - - -

#define PULS_D1					SW_LEFT_PIN
#define PULS_D1_SYSCTL_RCGC2	SYSCTL_RCGC2_GPIOF
#define PULS_D1_PORT_DIR_R		GPIO_PORTF_DIR_R
#define PULS_D1_PORT_AFSEL_R	GPIO_PORTF_AFSEL_R
#define PULS_D1_PORT_DEN_R		GPIO_PORTF_DEN_R
#define PULS_D1_PORT_AMSEL_R	GPIO_PORTF_AMSEL_R
#define PULS_D1_PORT_PUR_R		GPIO_PORTF_PUR_R
#define PULS_D1_PORT_PDR_R		GPIO_PORTF_PDR_R
#define PULS_D1_PORT_DATA_R		GPIO_PORTF_DATA_R

#define PULS_D2					SW_RIGHT_PIN
#define PULS_D2_SYSCTL_RCGC2	SYSCTL_RCGC2_GPIOF
#define PULS_D2_PORT_DIR_R		GPIO_PORTF_DIR_R
#define PULS_D2_PORT_AFSEL_R	GPIO_PORTF_AFSEL_R
#define PULS_D2_PORT_DEN_R		GPIO_PORTF_DEN_R
#define PULS_D2_PORT_AMSEL_R	GPIO_PORTF_AMSEL_R
#define PULS_D2_PORT_PUR_R		GPIO_PORTF_PUR_R
#define PULS_D2_PORT_PDR_R		GPIO_PORTF_PDR_R
#define PULS_D2_PORT_LOCK_R		GPIO_PORTF_LOCK_R
#define GPIO_LOCK_KEY           0x4C4F434B  // Unlocks the GPIO_CR register
#define PULS_D2_PORT_DATA_R		GPIO_PORTF_DATA_R

#ifdef RED_LED_PIN
#define RED_LED_SYSCTL_RCGC2	SYSCTL_RCGC2_GPIOF
#define RED_LED_PORT_DIR_R		GPIO_PORTF_DIR_R
#define RED_LED_PORT_AFSEL_R	GPIO_PORTF_AFSEL_R
#define RED_LED_PORT_DEN_R		GPIO_PORTF_DEN_R
#define RED_LED_PORT_AMSEL_R	GPIO_PORTF_AMSEL_R
#define RED_LED_PORT_DATA_R		GPIO_PORTF_DATA_R
#endif

#ifdef BLUE_LED_PIN
#define BLUE_LED_SYSCTL_RCGC2	SYSCTL_RCGC2_GPIOF
#define BLUE_LED_PORT_DIR_R		GPIO_PORTF_DIR_R
#define BLUE_LED_PORT_AFSEL_R	GPIO_PORTF_AFSEL_R
#define BLUE_LED_PORT_DEN_R		GPIO_PORTF_DEN_R
#define BLUE_LED_PORT_AMSEL_R	GPIO_PORTF_AMSEL_R
#define BLUE_LED_PORT_DATA_R	GPIO_PORTF_DATA_R
#endif

#ifdef GREEN_LED_PIN
#define GREEN_LED_SYSCTL_RCGC2	SYSCTL_RCGC2_GPIOF
#define GREEN_LED_PORT_DIR_R	GPIO_PORTF_DIR_R
#define GREEN_LED_PORT_AFSEL_R	GPIO_PORTF_AFSEL_R
#define GREEN_LED_PORT_DEN_R	GPIO_PORTF_DEN_R
#define GREEN_LED_PORT_AMSEL_R	GPIO_PORTF_AMSEL_R
#define GREEN_LED_PORT_DATA_R	GPIO_PORTF_DATA_R
#endif

#ifdef SERVO_LED_PIN
#define SERVO_LED_SYSCTL_RCGC2	SYSCTL_RCGC2_GPIOE
#define SERVO_LED_PORT_DIR_R	GPIO_PORTE_DIR_R
#define SERVO_LED_PORT_AFSEL_R	GPIO_PORTE_AFSEL_R
#define SERVO_LED_PORT_DEN_R	GPIO_PORTE_DEN_R
#define SERVO_LED_PORT_AMSEL_R	GPIO_PORTE_AMSEL_R
#define SERVO_LED_PORT_DATA_R	GPIO_PORTE_DATA_R
#endif

#ifdef SERVO_PIN
#define SERVO_SYSCTL_RCGC2		SYSCTL_RCGC2_GPIOB
#define SERVO_PORT_DIR_R		GPIO_PORTB_DIR_R
#define SERVO_PORT_AFSEL_R		GPIO_PORTB_AFSEL_R
#define SERVO_PORT_DEN_R		GPIO_PORTB_DEN_R
#define SERVO_PORT_AMSEL_R		GPIO_PORTB_AMSEL_R
#define SERVO_PORT_DATA_R		GPIO_PORTB_DATA_R
#endif

//*****************************************************************************
//
// Values that can be passed to GPIODirModeSet as the ulPinIO parameter, and
// returned from GPIODirModeGet.
//
//*****************************************************************************
#define GPIO_DIR_MODE_IN        0x00000000  // Pin is a GPIO input
#define GPIO_DIR_MODE_OUT       0x00000001  // Pin is a GPIO output
#define GPIO_DIR_MODE_HW        0x00000002  // Pin is a peripheral function

//*****************************************************************************
//
// Values that can be passed to GPIOIntTypeSet as the ulIntType parameter, and
// returned from GPIOIntTypeGet.
//
//*****************************************************************************
#define GPIO_FALLING_EDGE       0x00000000  // Interrupt on falling edge
#define GPIO_RISING_EDGE        0x00000004  // Interrupt on rising edge
#define GPIO_BOTH_EDGES         0x00000001  // Interrupt on both edges
#define GPIO_LOW_LEVEL          0x00000002  // Interrupt on low level
#define GPIO_HIGH_LEVEL         0x00000007  // Interrupt on high level
#define GPIO_DISCRETE_INT       0x00010000  // Interrupt for individual pins

//*****************************************************************************
//
// Values that can be passed to GPIOPadConfigSet as the ulStrength parameter,
// and returned by GPIOPadConfigGet in the *pulStrength parameter.
//
//*****************************************************************************
#define GPIO_STRENGTH_2MA       0x00000001  // 2mA drive strength
#define GPIO_STRENGTH_4MA       0x00000002  // 4mA drive strength
#define GPIO_STRENGTH_8MA       0x00000004  // 8mA drive strength
#define GPIO_STRENGTH_8MA_SC    0x0000000C  // 8mA drive with slew rate control

//*****************************************************************************
//
// The following define the base address of the memories and peripherals.
//
//*****************************************************************************
#define FLASH_BASE              0x00000000  // FLASH memory
#define SRAM_BASE               0x20000000  // SRAM memory
#define WATCHDOG_BASE           0x40000000  // Watchdog
#define GPIO_PORTA_BASE         0x40004000  // GPIO Port A
#define GPIO_PORTB_BASE         0x40005000  // GPIO Port B
#define GPIO_PORTC_BASE         0x40006000  // GPIO Port C
#define GPIO_PORTD_BASE         0x40007000  // GPIO Port D
#define SSI_BASE                0x40008000  // SSI
#define UART0_BASE              0x4000C000  // UART0
#define UART1_BASE              0x4000D000  // UART1
#define I2C_MASTER_BASE         0x40020000  // I2C Master
#define I2C_SLAVE_BASE          0x40020800  // I2C Slave
#define GPIO_PORTE_BASE         0x40024000  // GPIO Port E
#define GPIO_PORTF_BASE         0x40025000  // GPIO Port F
#define PWM_BASE                0x40028000  // PWM
#define QEI_BASE                0x4002C000  // QEI
#define TIMER0_BASE             0x40030000  // Timer0
#define TIMER1_BASE             0x40031000  // Timer1
#define TIMER2_BASE             0x40032000  // Timer2
#define ADC_BASE                0x40038000  // ADC
#define COMP_BASE               0x4003C000  // Analog comparators
#define FLASH_CTRL_BASE         0x400FD000  // FLASH Controller
#define SYSCTL_BASE             0x400FE000  // System Control
#define ITM_BASE                0xE0000000  // Instrumentation Trace Macrocell
#define DWT_BASE                0xE0001000  // Data Watchpoint and Trace
#define FPB_BASE                0xE0002000  // FLASH Patch and Breakpoint
#define NVIC_BASE               0xE000E000  // Nested Vectored Interrupt Ctrl
#define TPIU_BASE               0xE0040000  // Trace Port Interface Unit


//--------------------------------------------------------------------------------------------------
//=== Global function prototypes ===================================================================
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//=== Type definitions (typedef) ===================================================================
//=== Local constants  =============================================================================
//=== Local variables ==============================================================================
//=== Local function prototypes ====================================================================
//--------------------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif //  __HWCONFIG_H__
