#define SYSCTL_RIS_R            (*((volatile unsigned long *)0x400FE050))
#define SYSCTL_RIS_PLLLRIS      0x00000040  // PLL Lock Raw Interrupt Status
#define SYSCTL_RCC_R            (*((volatile unsigned long *)0x400FE060))
#define SYSCTL_RCC_XTAL_M       0x000003C0  // Crystal Value
#define SYSCTL_RCC_XTAL_6MHZ    0x000002C0  // 6 MHz Crystal
#define SYSCTL_RCC_XTAL_8MHZ    0x00000380  // 8 MHz Crystal
#define SYSCTL_RCC_XTAL_16MHZ   0x00000540  // 16 MHz Crystal
#define SYSCTL_RCC2_R           (*((volatile unsigned long *)0x400FE070))
#define SYSCTL_RCC2_USERCC2     0x80000000  // Use RCC2
#define SYSCTL_RCC2_DIV400      0x40000000  // Divide PLL as 400 MHz vs. 200
                                            // MHz
#define SYSCTL_RCC2_SYSDIV2_M   0x1F800000  // System Clock Divisor 2
#define SYSCTL_RCC2_SYSDIV2LSB  0x00400000  // Additional LSB for SYSDIV2
#define SYSCTL_RCC2_PWRDN2      0x00002000  // Power-Down PLL 2
#define SYSCTL_RCC2_BYPASS2     0x00000800  // PLL Bypass 2
#define SYSCTL_RCC2_OSCSRC2_M   0x00000070  // Oscillator Source 2
#define SYSCTL_RCC2_OSCSRC2_MO  0x00000000  // MOSC

//--------------------------------------------------------------------------------------------------
//=== Includes =====================================================================================
//--------------------------------------------------------------------------------------------------
#include "PLL.h"

//--------------------------------------------------------------------------------------------------
//=== Global Functions =============================================================================
//--------------------------------------------------------------------------------------------------
// configure the system to get its clock from the PLL
void PLL_Init(void){
	// 1) configure the system to use RCC2 for advanced features
	//    such as 400 MHz PLL and non-integer System Clock Divisor
	SYSCTL_RCC2_R |= SYSCTL_RCC2_USERCC2;
	// 2) bypass PLL while initializing
	SYSCTL_RCC2_R |= SYSCTL_RCC2_BYPASS2;
	// 3) select the crystal value and oscillator source
	SYSCTL_RCC_R &= ~SYSCTL_RCC_XTAL_M;   // clear XTAL field
	SYSCTL_RCC_R += SYSCTL_RCC_XTAL_16MHZ;// configure for 16 MHz crystal
	SYSCTL_RCC2_R &= ~SYSCTL_RCC2_OSCSRC2_M;// clear oscillator source field
	SYSCTL_RCC2_R += SYSCTL_RCC2_OSCSRC2_MO;// configure for main oscillator source
	// 4) activate PLL by clearing PWRDN
	SYSCTL_RCC2_R &= ~SYSCTL_RCC2_PWRDN2;
	// 5) use 400 MHz PLL
	SYSCTL_RCC2_R |= SYSCTL_RCC2_DIV400;
	// 6) set the desired system divider and the system divider least significant bit
	SYSCTL_RCC2_R &= ~SYSCTL_RCC2_SYSDIV2_M;  // clear system clock divider field
	SYSCTL_RCC2_R &= ~SYSCTL_RCC2_SYSDIV2LSB; // clear bit SYSDIV2LSB

	// set SYSDIV2 and SYSDIV2LSB fields
	SYSCTL_RCC2_R += (SYSDIV<<23)|(LSB<<22);  // divide by (2*SYSDIV+1+LSB)

	// 7) wait for the PLL to lock by polling PLLLRIS
	while((SYSCTL_RIS_R&SYSCTL_RIS_PLLLRIS)==0){};
	// 8) enable use of PLL by clearing BYPASS
	SYSCTL_RCC2_R &= ~SYSCTL_RCC2_BYPASS2;
}
//--------------------------------------------------------------------------------------------------
