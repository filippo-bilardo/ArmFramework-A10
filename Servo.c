//--------------------------------------------------------------------------------------------------
//=== Includes =====================================================================================
//--------------------------------------------------------------------------------------------------
#include "HwConfig.h"
#include "Led.h"
#include "SysTick.h"
#include "Servo.h"

//--------------------------------------------------------------------------------------------------
//=== Global Variables =============================================================================
//--------------------------------------------------------------------------------------------------
int ServoTick=0;
int ServoTestTick=0;
int ServoDelta=0;

//--------------------------------------------------------------------------------------------------
//=== Global Functions =============================================================================
//--------------------------------------------------------------------------------------------------
void ServoInit(void)
{
	// SERVO PIN
	#ifdef SERVO_PIN
	SYSCTL_RCGC2_R |= SERVO_SYSCTL_RCGC2; 		// activate port
	SERVO_PORT_DIR_R |= SERVO_PIN; 				// make pin out
	SERVO_PORT_AFSEL_R &= ~SERVO_PIN;			// disable alt functionality
	SERVO_PORT_DEN_R |= SERVO_PIN; 				// enable digital I/O
	SERVO_PORT_AMSEL_R &= ~SERVO_PIN;			// disable analog functionality
	#endif

	// SERVO LED 
	#ifdef SERVO_LED_PIN
	SYSCTL_RCGC2_R |= SERVO_LED_SYSCTL_RCGC2; 	// activate port
	SERVO_LED_PORT_DIR_R |= SERVO_LED_PIN; 		// make pin out
	SERVO_LED_PORT_AFSEL_R &= ~SERVO_LED_PIN;	// disable alt functionality
	SERVO_LED_PORT_DEN_R |= SERVO_LED_PIN; 		// enable digital I/O
	SERVO_LED_PORT_AMSEL_R &= ~SERVO_LED_PIN;	// disable analog functionality
	#endif
}
//--------------------------------------------------------------------------------------------------
void ServoOff(void) {SERVO_PORT_DATA_R &= ~SERVO_PIN;}
void ServoOn(void) {SERVO_PORT_DATA_R |= SERVO_PIN;}
void ServoLedOff(void) {SERVO_LED_PORT_DATA_R |= SERVO_LED_PIN;}
void ServoLedOn(void) {SERVO_LED_PORT_DATA_R &= ~SERVO_LED_PIN;}
void ServoLedToggle(void) {SERVO_LED_PORT_DATA_R ^= SERVO_LED_PIN;}

//--------------------------------------------------------------------------------------------------
void ServoTask(void)
{
	if(ServoTick < SERVO_TH_MIN + ServoDelta) {
		ServoOn();
	} else if (ServoTick < SERVO_TL_MAX) {
		ServoOff();
	} else {
		ServoTick = 0;
	}
}
//--------------------------------------------------------------------------------------------------
void ServoTestTask(void)
{
	if(ServoTestTick < 6000) {
		LedGreenOn();
		ServoLedOn();
		ServoDelta = -3;
	} else if (ServoTestTick < 12000) {
		LedGreenOff();
		ServoLedOff();
		ServoDelta = 3;
	} else if (ServoTestTick < 30000) {
		LedGreenOff();
		ServoLedOff();
		ServoDelta = 0;
	} else {
		ServoTestTick = 0;
	}
}
//--------------------------------------------------------------------------------------------------

