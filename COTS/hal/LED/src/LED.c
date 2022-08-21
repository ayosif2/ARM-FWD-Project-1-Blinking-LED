/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  LED.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "LED.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
	volatile int time_on;
	volatile int time_on_b;
	volatile int Time_off;
	volatile int time_off_b;
	volatile Dio_port Port;
	volatile int Pin_Number;


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void LED_Blink(int time_on,Time_off,Dio_port Port,int Pin_Number)        
* \Description     : it blinks the Led                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/

	void LED_Blink_Handler(){
		int t=1;
			//if (Timer_Config==Active){t=4;}
		if (time_on>1000/t){	
			Dio_WriteChannel(Port , Pin_Number,HIGH);
			systick_Start(1000/t);
			time_on=time_on-1000/t;
			return;
		}else if(time_on>0){
			Dio_WriteChannel(Port , Pin_Number,HIGH);
			systick_Start(time_on);
			time_on=0;
			Time_off=time_off_b;
			return;
		}else if (Time_off>1000/t){
			Dio_WriteChannel(Port , Pin_Number,LOW);
			systick_Start(1000/t);
			Time_off=Time_off-1000/t;
			return;
		}else if(Time_off>=0){
			Dio_WriteChannel(Port , Pin_Number,LOW);
			systick_Start(Time_off);
			Time_off=0;
			time_on=time_on_b;
			return;
		}		
	}
void LED_Blink(int time_on_f,int Time_off_f){
		time_on=time_on_f*2-1;
		Time_off=Time_off_f*2;
		time_on_b=time_on_f*2;
		time_off_b=Time_off_f*2;
		Port=LED_Config.port;
		Pin_Number=LED_Config.PinNumber;
		Dio_WriteChannel(Port , Pin_Number,HIGH);
		Handler_PTR =LED_Blink_Handler;
		systick_Start(1);		
}

void LED_Blink_delay(int time_on_n,int Time_off_n){
	while(1){
	Dio_WriteChannel(LED_Config.port , LED_Config.PinNumber,HIGH);
	system_delay(time_on_n);
	Dio_WriteChannel(LED_Config.port , LED_Config.PinNumber,LOW);
	system_delay(Time_off_n);

	}
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/