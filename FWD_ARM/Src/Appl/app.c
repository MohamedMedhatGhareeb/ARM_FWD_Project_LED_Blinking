/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  app.c
 *        \brief  Application Layer Functions
 *
 *      \details  Application Layer Functions
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "app.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
Dio_ChannelType LED_Pin;
uint32 On_Time,Off_Time;
Gpt_ValueType On_Ticks, Off_Ticks;
Gpt_ChannelType Timer_Used = TIM_0;
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
* \Syntax          : Std_ReturnType On_Duration_OffDuration_ms(uint32 ON_TIME,uint32 OFF_TIME)                                    
* \Description     : take from user On & Off duration of LED (Pin)                                                                                                           
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ON_TIME, OFF_TIME [uint32 _type]                   
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType - ok if suitable inputs
*******************************************************************************/
Std_ReturnType On_Duration_OffDuration_ms(uint32 ON_TIME,uint32 OFF_TIME)
{
	On_Time = ON_TIME;
	Off_Time = OFF_TIME;
	return E_OK;
}

/******************************************************************************
* \Syntax          : Gpt_ValueType convertTime_ms_ToTicks(uint32 value);                                      
* \Description     : convert input time from user to real ticks for the Timer                                                                                                    
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : value                   
* \Parameters (out): None                                                      
* \Return value:   : Gpt_ValueType Ticks calue for timer
*******************************************************************************/
Gpt_ValueType convertTime_ms_ToTicks(uint32 value)
{
	return (value)/((Pre_Scaler)/(System_CLock));
}

/******************************************************************************
* \Syntax          : void execute_change (void)                                   
* \Description     : callback function execution                                                                                                    
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void execute_change (void)
{
	if(Dio_ReadChannel(LED_Pin) == Level_Low)
	{
		Dio_WriteChannel(LED_Pin,Level_High);
		GPT_StartTime(Timer_Used,convertTime_ms_ToTicks(On_Time));
	}
	else if (Dio_ReadChannel(LED_Pin) == Level_High)
	{
		Dio_WriteChannel(LED_Pin,Level_Low);
		GPT_StartTime(Timer_Used,convertTime_ms_ToTicks(Off_Time));
	}
}

/**********************************************************************************************************************
 *  END OF FILE: app.c
 *********************************************************************************************************************/

