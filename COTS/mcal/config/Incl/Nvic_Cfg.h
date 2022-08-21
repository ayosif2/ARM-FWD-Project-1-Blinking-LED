/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Nvic_Cfg.H
 *       Module:  -
 *
 *  Description:  configuration for the interrupt module    
 *  
 *********************************************************************************************************************/
#ifndef Nvic_cfg_h
#define Nvic_cfg_h

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PRIGROUP  0xE000ED0C
#define int_base1 0xE000E100
#define int_base2 0xE000E104
#define int_base3 0xE000E108
#define int_base4 0xE000E10C
#define int_base5 0xE000E110
#define PRI0	  	0xE000E400


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum{
	Enable,
	Disable
}NVIC_state;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* Nvic_Cfg_H */

/**********************************************************************************************************************
 *  END OF FILE: Nvic_Cfg.h
 *********************************************************************************************************************/