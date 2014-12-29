//--------------------------------------------------------------------------------------------------
//=== Includes =====================================================================================
//--------------------------------------------------------------------------------------------------
#include "HwConfig.h"
#include "ADC.h"

//--------------------------------------------------------------------------------------------------
//=== Global Functions =============================================================================
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
void ADC0_InitSWTriggerSeq3_Ch9(void) { 
//-------------------------------------------------------------------------------//
// ROUTINE:			ADC0_InitSWTriggerSeq3_Ch9
// VERSIONE:        1.0
// ULTIMA MODIFICA: 04.02.14
// INPUT:           Nessuno
// OUTPUT:          Nessuno
//
// 1.0	04.02.14	Versione iniziale
//-------------------------------------------------------------------------------//
	volatile unsigned long delay;
																						
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;	// Attivazione clock del PortE
	delay = SYSCTL_RCGCGPIO_R;     				// Pausa in attesa della stabilizzazione del clock
	delay = SYSCTL_RCGCGPIO_R;
	GPIO_PORTE_DIR_R &= ~0x10;     				// Settaggio di PE4 come input
	GPIO_PORTE_AFSEL_R |= 0x10;     			// Abilitazione della funzione alternativa su PE4
	GPIO_PORTE_DEN_R &= ~0x10;      			// Disabilitazione digitale I/O su PE4
	GPIO_PORTE_AMSEL_R |= 0x10;     			// Abilitazione delle funzioni analogiche su PE4
	SYSCTL_RCGC0_R |= 0x00010000;   			// Attivazione dell'ADC0
	ADC0_PC_R &= ~0xF;             				// clear max sample rate field
	ADC0_PC_R |= 0x1;              				// Configurazione per 125K campionamenti/sec
	ADC0_SSPRI_R = 0x3210;						// Sequencer 3 è alla priorità più bassa
	ADC0_ACTSS_R &= ~0x0008;        			// Disabilitazione campionamento sequencer 3
	ADC0_EMUX_R &= ~0xF000;         			// Sequencer 3 è software trigger
	ADC0_SSMUX3_R &= ~0x000F;       			// Pulizia del campio SS3
	ADC0_SSMUX3_R += 9;            				// Settaggio canale
	ADC0_SSCTL3_R = 0x0006;        	 			// No TS0 D0, si IE0 END0
	ADC0_IM_R &= ~0x0008;           			// Disabilitazione SS3 interrupts
	ADC0_ACTSS_R |= 0x0008;         			// Abilitazione campionamento sequencer 3
}

//--------------------------------------------------------------------------------------------------
void ADC0_InitSWTriggerSeq3(unsigned char channelNum) {
// ROUTINE:			ADC0_InitSWTriggerSeq3
// VERSIONE:        1.0
// ULTIMA MODIFICA: 04.02.14
// INPUT:           Nessuno
// OUTPUT:          Nessuno
//
// 1.0	04.02.14	Versione iniziale
//
	volatile unsigned long delay;
	switch(channelNum)
	{             										// Attivazione clock
		case 0:
		case 1:
		case 2:
		case 3:
		case 8:
		case 9:            					// Queste sono su GPIO_PORTE
			SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4; 
			break;
		case 4:
		case 5:
		case 6:
		case 7:            					// Queste sono su GPIO_PORTD
			SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3; 
			break;
		case 10:
		case 11:           					// Queste sono su GPIO_PORTB
			SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1; 
			break;
		default: return;					// Da 0 a 11 sono canali validi su LM4F120
	}
	
	delay = SYSCTL_RCGCGPIO_R;      		// Pausa in attesa della stabilizzazione del clock
	delay = SYSCTL_RCGCGPIO_R;
	
	switch(channelNum)
	{
		case 0:                       		// Ain0 è su PE3
			GPIO_PORTE_DIR_R &= ~0x08;  	// Settaggio PE3 come input
			GPIO_PORTE_AFSEL_R |= 0x08; 	// Abilitazione della funzione alternativa su PE3
			GPIO_PORTE_DEN_R &= ~0x08;  	// Disabilitazione digitale I/O su PE3
			GPIO_PORTE_AMSEL_R |= 0x08; 	// Abilitazione delle funzioni analogiche su PE3
			break;
		case 1:                       		// Ain1 è su PE2
			GPIO_PORTE_DIR_R &= ~0x04;  				
			GPIO_PORTE_AFSEL_R |= 0x04; 				
			GPIO_PORTE_DEN_R &= ~0x04;  				
			GPIO_PORTE_AMSEL_R |= 0x04; 				
			break;
		case 2:                      		// Ain2 è su PE1
			GPIO_PORTE_DIR_R &= ~0x02;  				
			GPIO_PORTE_AFSEL_R |= 0x02; 				
			GPIO_PORTE_DEN_R &= ~0x02;  				
			GPIO_PORTE_AMSEL_R |= 0x02; 				
			break;
		case 3:                       		// Ain3 è su PE0
			GPIO_PORTE_DIR_R &= ~0x01;  				
			GPIO_PORTE_AFSEL_R |= 0x01; 				
			GPIO_PORTE_DEN_R &= ~0x01;  				
			GPIO_PORTE_AMSEL_R |= 0x01; 				
			break;
		case 4:                       		// Ain4 è su PD3
			GPIO_PORTD_DIR_R &= ~0x08;  				
			GPIO_PORTD_AFSEL_R |= 0x08; 				
			GPIO_PORTD_DEN_R &= ~0x08;  				
			GPIO_PORTD_AMSEL_R |= 0x08; 				
			break;
		case 5:                      		// Ain5 è su PD2
			GPIO_PORTD_DIR_R &= ~0x04;  				
			GPIO_PORTD_AFSEL_R |= 0x04; 				
			GPIO_PORTD_DEN_R &= ~0x04;  				
			GPIO_PORTD_AMSEL_R |= 0x04; 				
			break;
		case 6:                       		// Ain6 è su PD1
			GPIO_PORTD_DIR_R &= ~0x02;  				
			GPIO_PORTD_AFSEL_R |= 0x02;	 				
			GPIO_PORTD_DEN_R &= ~0x02;  				
			GPIO_PORTD_AMSEL_R |= 0x02; 				
			break;
		case 7:                       		// Ain7 è su PD0
			GPIO_PORTD_DIR_R &= ~0x01;  				
			GPIO_PORTD_AFSEL_R |= 0x01;					
			GPIO_PORTD_DEN_R &= ~0x01;  				
			GPIO_PORTD_AMSEL_R |= 0x01; 				
			break;
		case 8:                      	 	// Ain8 è su PE5
			GPIO_PORTE_DIR_R &= ~0x20;  				
			GPIO_PORTE_AFSEL_R |= 0x20; 				
			GPIO_PORTE_DEN_R &= ~0x20;  				
			GPIO_PORTE_AMSEL_R |= 0x20; 				
			break;
		case 9:                       		// Ain9 è su PE4
			GPIO_PORTE_DIR_R &= ~0x10;  				
			GPIO_PORTE_AFSEL_R |= 0x10; 				
			GPIO_PORTE_DEN_R &= ~0x10;  				
			GPIO_PORTE_AMSEL_R |= 0x10; 				
			break;
		case 10:                      		// Ain10 è su PB4
			GPIO_PORTB_DIR_R &= ~0x10;  				
			GPIO_PORTB_AFSEL_R |= 0x10; 				
			GPIO_PORTB_DEN_R &= ~0x10; 					
			GPIO_PORTB_AMSEL_R |= 0x10; 				
			break;
		case 11:                     		// Ain11 è su PB5
			GPIO_PORTB_DIR_R &= ~0x20;  				
			GPIO_PORTB_AFSEL_R |= 0x20;					
			GPIO_PORTB_DEN_R &= ~0x20;  				
			GPIO_PORTB_AMSEL_R |= 0x20; 				
			break;
	}

	SYSCTL_RCGC0_R |= 0x00010000;   		// Attivazione dell'ADC0
	delay = SYSCTL_RCGC0_R;         		// Pausa in attesa della stabilizzazione del clock
	delay = SYSCTL_RCGC0_R;
	ADC0_PC_R &= ~0xF;              		// Clear max sample rate field
	ADC0_PC_R |= 0x1;               		// Configurazione per 125K campionamenti/sec
	ADC0_SSPRI_R = 0x3210;          		// Sequencer 3 è alla priorità più bassa
	ADC0_ACTSS_R &= ~0x0008;        		// Disabilitazione campionamento sequencer 3
	ADC0_EMUX_R &= ~0xF000;         		// Sequencer 3 è software trigger
	ADC0_SSMUX3_R &= ~0x000F;       		// Pulizia del campio SS3
	ADC0_SSMUX3_R += channelNum;    		// Settaggio canale
	ADC0_SSCTL3_R = 0x0006;         		// No TS0 D0, si IE0 END0
	ADC0_IM_R &= ~0x0008;           		// Disabilitazione SS3 interrupts
	ADC0_ACTSS_R |= 0x0008;         		// Abilitazione campionamento sequencer 3
}

//--------------------------------------------------------------------------------------------------
void ADC0_InitAllTriggerSeq3(unsigned char channelNum){ 
	volatile unsigned long delay;
	switch(channelNum)						
	{             							// Attivazione clock
		case 0:
		case 1:
		case 2:
		case 3:
		case 8:
		case 9:                       		// Queste sono su GPIO_PORTE
			SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4; 
			break;
		case 4:
		case 5:
		case 6:
		case 7:                       		// Queste sono su GPIO_PORTD
			SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3; 
			break;
		case 10:
		case 11:                      		// Queste sono su GPIO_PORTB
			SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1; 
			break;
		default: return;              		// Da 0 a 11 sono valori validi su LM4F120
	}
	
	delay = SYSCTL_RCGCGPIO_R;      		// Pausa in attesa della stabilizzazione del clock
	
	switch(channelNum)
	{
		case 0:                      		// Ain0 è su PE3
			GPIO_PORTE_DIR_R &= ~0x08;  	// Settaggio PE3 come input
			GPIO_PORTE_AFSEL_R |= 0x08; 	// Abilitazione della funzione alternativa su PE3
			GPIO_PORTE_DEN_R &= ~0x08;  	// Disabilitazione digitale I/O su PE3
			GPIO_PORTE_AMSEL_R |= 0x08; 	// Abilitazione delle funzioni analogiche su PE3
			break;
		case 1:                       		// Ain1 è su PE2
			GPIO_PORTE_DIR_R &= ~0x04;  
			GPIO_PORTE_AFSEL_R |= 0x04;	
			GPIO_PORTE_DEN_R &= ~0x04;  
			GPIO_PORTE_AMSEL_R |= 0x04; 
			break;
		case 2:                       		// Ain2 è su PE1
			GPIO_PORTE_DIR_R &= ~0x02;  
			GPIO_PORTE_AFSEL_R |= 0x02; 
			GPIO_PORTE_DEN_R &= ~0x02;  
			GPIO_PORTE_AMSEL_R |= 0x02; 
			break;
		case 3:                      		// Ain3 è su PE0
			GPIO_PORTE_DIR_R &= ~0x01;  
			GPIO_PORTE_AFSEL_R |= 0x01; 
			GPIO_PORTE_DEN_R &= ~0x01;  
			GPIO_PORTE_AMSEL_R |= 0x01; 
			break;
		case 4:                       		// Ain4 è su PD3
			GPIO_PORTD_DIR_R &= ~0x08; 	
			GPIO_PORTD_AFSEL_R |= 0x08; 
			GPIO_PORTD_DEN_R &= ~0x08;  
			GPIO_PORTD_AMSEL_R |= 0x08; 
			break;
		case 5:                       		// Ain5 è su PD2
			GPIO_PORTD_DIR_R &= ~0x04;  
			GPIO_PORTD_AFSEL_R |= 0x04; 
			GPIO_PORTD_DEN_R &= ~0x04;  
			GPIO_PORTD_AMSEL_R |= 0x04; 	
			break;
		case 6:                       		// Ain6 è su PD1
			GPIO_PORTD_DIR_R &= ~0x02;  	
			GPIO_PORTD_AFSEL_R |= 0x02; 	
			GPIO_PORTD_DEN_R &= ~0x02;  	
			GPIO_PORTD_AMSEL_R |= 0x02; 	
			break;
		case 7:                       		// Ain7 è su PD0
			GPIO_PORTD_DIR_R &= ~0x01;  	
			GPIO_PORTD_AFSEL_R |= 0x01; 	
			GPIO_PORTD_DEN_R &= ~0x01;  	
			GPIO_PORTD_AMSEL_R |= 0x01; 	
			break;
		case 8:                       		// Ain8 è su PE5
			GPIO_PORTE_DIR_R &= ~0x20;  	
			GPIO_PORTE_AFSEL_R |= 0x20; 	
			GPIO_PORTE_DEN_R &= ~0x20;  	
			GPIO_PORTE_AMSEL_R |= 0x20;		
			break;
		case 9:                       		// Ain9 è su PE4
			GPIO_PORTE_DIR_R &= ~0x10;  	
			GPIO_PORTE_AFSEL_R |= 0x10; 	
			GPIO_PORTE_DEN_R &= ~0x10;  	
			GPIO_PORTE_AMSEL_R |= 0x10; 	
			break;
		case 10:                      		// Ain10 è su PB4
			GPIO_PORTB_DIR_R &= ~0x10;  	
			GPIO_PORTB_AFSEL_R |= 0x10; 	
			GPIO_PORTB_DEN_R &= ~0x10;  	
			GPIO_PORTB_AMSEL_R |= 0x10; 	
			break;
		case 11:                     	 	// Ain11 è su PB5
			GPIO_PORTB_DIR_R &= ~0x20;  	
			GPIO_PORTB_AFSEL_R |= 0x20; 	
			GPIO_PORTB_DEN_R &= ~0x20;  	
			GPIO_PORTB_AMSEL_R |= 0x20; 	
			break;
	}	

	SYSCTL_RCGC0_R |= 0x00010000;   	// Attivazione dell'ADC0
	delay = SYSCTL_RCGC0_R;         	// Pausa in attesa della stabilizzazione del clock
	delay = SYSCTL_RCGC0_R;
	ADC0_PC_R &= ~0xF;              	// Clear max sample rate field
	ADC0_PC_R |= 0x1;              		// Configurazione per 125K campionamenti/sec
	ADC0_SSPRI_R = 0x3210;          	// Sequencer 3 è alla priorità più bassa
	ADC0_ACTSS_R &= ~0x0008;        	// Disabilitazione campionamento sequencer 3
	ADC0_EMUX_R |= 0xF000;          	// Sequencer 3 è continuamente triggerato
	ADC0_SSMUX3_R &= ~0x000F;       	// Pulizia del campio SS3
	ADC0_SSMUX3_R += channelNum;    	// Settaggio canale
	ADC0_SSCTL3_R = 0x0006;         	// No TS0 D0, si IE0 END0
	ADC0_IM_R &= ~0x0008;           	// Disabilitazione SS3 interrupts
	ADC0_ACTSS_R |= 0x0008;         	// Abilitazione campionamento sequencer 3
}

//--------------------------------------------------------------------------------------------------
unsigned long ADC0_InSeq3(void) {  
// ROUTINE:			ADC0_InSeq3
// VERSIONE:        1.0
// ULTIMA MODIFICA: 04.02.14
// INPUT:           Nessuno
// OUTPUT:          Nessuno
//
// 1.0	04.02.14	Versione iniziale
//
	unsigned long result;
	ADC0_PSSI_R = 0x0008;            	// Inizializzazione di SS3
	while((ADC0_RIS_R&0x08)==0){};   	// Attesa che la conversione venga completata
	result = ADC0_SSFIFO3_R&0xFFF;   	// Lettura risultato
	ADC0_ISC_R = 0x0008;             	// Completamento riconoscimento
		
	return result;						// Return del risultato
}
//--------------------------------------------------------------------------------------------------
