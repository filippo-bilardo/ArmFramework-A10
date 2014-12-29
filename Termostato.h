//==================================================================================================
//       _____   ____
//      |  ___| |  _ \
//      | |_    | |_| |
//      |  _|   |  _ /
//	    | |     | |_| |
//	www.|_|     |_____/-labs.blogspot.it
//
// Filename:    Termostato.c
// Description: Utilizzato il pin PD0 (AIN7)
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
// 1.0.0	31.10.14 	Versione iniziale
//
//==================================================================================================
#ifndef _TERMOSTATO
#define _TERMOSTATO

//--------------------------------------------------------------------------------------------------
//=== Global constants =============================================================================
//--------------------------------------------------------------------------------------------------
#define	TEMP_MAX	2731 //0x0000055A -> ??°
#define TEMP_MIN	1364 //0x00000AAB -> ??°

//--------------------------------------------------------------------------------------------------
//=== Global function prototypes ===================================================================
//--------------------------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------------------------------------------------------
// VERSIONE:        1.0.0
// ULTIMA MODIFICA:	04.02.14
// INPUT:           Nessuno
// OUTPUT:          Nessuno
//
// 1.0	04.02.14	Versione iniziale
//
void TermostatoInit(void);
//--------------------------------------------------------------------------------------------------
// VERSIONE:        1.0.0
// ULTIMA MODIFICA:	04.02.14
// INPUT:           Nessuno
// OUTPUT:          Nessuno
//
//  Routine di controllo del valore convertito:
//  Se maggiore di TEMP_MAX sarà indicato con il led rosso
//  Se minore di TEMP_MIN sarà indicato con il led blu
//  Se compreso tra i due valori sarà indicato con il led verde
//
// 1.0	04.02.14	Versione iniziale
//
void TermostatoTask(void);

#ifdef __cplusplus
}
#endif
//--------------------------------------------------------------------------------------------------
#endif
