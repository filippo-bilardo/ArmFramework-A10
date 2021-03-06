//--------------------------------------------------------------------------------------------------
//=== Includes =====================================================================================
//--------------------------------------------------------------------------------------------------
#include "Led.h"
#include "ADC.h"
#include "Termostato.h"

//--------------------------------------------------------------------------------------------------
//=== Global Functions =============================================================================
//--------------------------------------------------------------------------------------------------
void TermostatoInit(void)
{
		ADC0_InitSWTriggerSeq3(7);
}
//--------------------------------------------------------------------------------------------------
void TermostatoTask(void)
{
	int conversione = ADC0_InSeq3();
	
	if(conversione > TEMP_MAX)
	{
		LedOff();
		LedRedOn();
	}
	else
	{
		if(conversione < TEMP_MIN)
		{
			LedOff();
			LedBlueOn();
		}
		else
		{
			LedOff();
			LedGreenOn();
		}
	}

}
//--------------------------------------------------------------------------------------------------
