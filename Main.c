//==================================================================================================
//
// Project:	ARM_TEMPLATE-A10-FW1.0.0
// Date:	29.10.14
// Author:	Filippo Bilardo
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//   <inserire una breve descrizione del progetto>
//   <specifiche del progetto> 
//   <specifiche del collaudo> 
//
// Ver		Date		Comment
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 1.0.0	29.10.14	Versione iniziale
// <Descrivere per ogni revisione o cambio di versione le modifiche apportate>
//
//==================================================================================================
//--------------------------------------------------------------------------------------------------
//=== Includes =====================================================================================
//--------------------------------------------------------------------------------------------------
#include "PLL.h"
#include "HwConfig.h"
#include "HwTypes.h"
#include "SysTick.h"
#include "Led.h"
#include "Puls.h"
#include "Servo.h"
#include "Termostato.h"

//--------------------------------------------------------------------------------------------------
//=== Main =========================================================================================
//--------------------------------------------------------------------------------------------------
int main(void)
{
	// Inizializzazioni
	PLL_Init();               	// set system clock to 50 MHz
	SysTickInit(5000);        	// initialize SysTick timer -> Interrupts every 100us
	LedInit();
	PulsInit();
	ServoInit();
	TermostatoInit();

	// Autodiagnostica
	LedTest();
	//PulsTest();

	EnableInterrupts();
	// Ciclo infinito
	for(;;)
	{                   	
		TermostatoTask();
		//ServoTask();
		//ServoTestTask();
		LedDogTask();
	}
}
//--------------------------------------------------------------------------------------------------
