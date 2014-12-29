//--------------------------------------------------------------------------------------------------
//=== Includes =====================================================================================
//--------------------------------------------------------------------------------------------------
#include "HwConfig.h"
#include "Led.h"
#include "SysTick.h"

//--------------------------------------------------------------------------------------------------
//=== Local variables ==============================================================================
//--------------------------------------------------------------------------------------------------
int leddog_tick=0;
int sys_tick=0;

//--------------------------------------------------------------------------------------------------
//=== Global Functions =============================================================================
//--------------------------------------------------------------------------------------------------
// **************SysTickInit*********************
// Initialize SysTick periodic interrupts
// Input: interrupt period
//	Units of period are 20ns (assuming 50 MHz clock)
// 	period = 5000 -> 5000*20*10-9 = 100*10-6 us
// 	Maximum is 2^24-1
// 	Minimum is determined by length of ISR
// Output: none
void SysTickInit(unsigned long period){
	long sr;
	sr = StartCritical();
	NVIC_ST_CTRL_R = 0;         // disable SysTick during setup
	NVIC_ST_RELOAD_R = period-1;// reload value
	NVIC_ST_CURRENT_R = 0;      // any write to current clears it
	NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x40000000; // priority 2
								// enable SysTick with core clock and interrupts
	NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE+NVIC_ST_CTRL_CLK_SRC+NVIC_ST_CTRL_INTEN;
	EndCritical(sr);
}
//--------------------------------------------------------------------------------------------------
int SysTickTest(void) 
{
	SysTickInit(5000);        	// initialize SysTick timer
	EnableInterrupts();

	while(1){                   // interrupts every 1ms, 500 Hz flash
		WaitForInterrupt();
	}
}
//--------------------------------------------------------------------------------------------------
// Interrupt service routine
// Executed every 20ns*(period)
void SysTickHandler(void)
{
	ServoTick++;
	ServoTestTick++;
	leddog_tick++;
	sys_tick++;
}
//--------------------------------------------------------------------------------------------------
// led blink every 1sec (0.1sec on 0.9sec off)
void LedDogTask(void)
{
	if(leddog_tick < LEDDOG_TH_MIN) {
		LedDogOn();
	} else if (leddog_tick < LEDDOG_TL_MAX) {
		LedDogOff();
	} else {
		leddog_tick = 0;
	}
}
//--------------------------------------------------------------------------------------------------
// Time delay using busy wait.
// The delay parameter is in units of the core clock. (units of 20 nsec for 50 MHz clock)
void SysTickWait(unsigned long delay) {
	volatile unsigned long elapsedTime;
	unsigned long startTime = NVIC_ST_CURRENT_R;
	do{
		elapsedTime = (startTime-NVIC_ST_CURRENT_R)&0x00FFFFFF;
	}
	while(elapsedTime <= delay);
}
//--------------------------------------------------------------------------------------------------
// Time delay using busy wait.
// This assumes 50 MHz system clock.
void DelayUs(unsigned long delay) {
	unsigned long i;
	for(i=0; i<delay; i++){
		SysTickWait(50);  // wait 1us (assuming 50 MHz clock -> 50*20ns = 1us)
	}
}
//--------------------------------------------------------------------------------------------------
// Time delay using busy wait.
// This assumes 50 MHz system clock.
void DelayMs(unsigned long delay) {
	unsigned long i;
	for(i=0; i<delay; i++){
		DelayUs(1000);  // wait 1ms (assumes 50 MHz clock)
	}
}
//--------------------------------------------------------------------------------------------------

