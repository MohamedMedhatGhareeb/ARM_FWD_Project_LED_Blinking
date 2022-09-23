/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  app.h
 *       Module:  DIO
 *
 *  Description:  header file for Application layer Functions    
 *  
 *********************************************************************************************************************/
#ifndef APP_H
#define APP_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "DIO.h"
#include "GPT.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
extern Dio_ChannelType LED_Pin;
extern uint32 On_Time,Off_Time;
extern Gpt_ValueType On_Ticks, Off_Ticks;
extern Gpt_ChannelType Timer_Used;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
//extern const IRQ_CfgType IRQ_Cfg[NVIC_IQR_ACTIVE_NO] ;

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
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
Std_ReturnType On_Duration_OffDuration_ms(uint32 ON_TIME,uint32 OFF_TIME);

/******************************************************************************
* \Syntax          : Gpt_ValueType convertTime_ms_ToTicks(uint32 value);                                      
* \Description     : convert input time from user to real ticks for the Timer                                                                                                    
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : value                   
* \Parameters (out): None                                                      
* \Return value:   : Gpt_ValueType Ticks calue for timer
*******************************************************************************/
Gpt_ValueType convertTime_ms_ToTicks(uint32 value);

/******************************************************************************
* \Syntax          : void execute_change (void)                                   
* \Description     : callback function execution                                                                                                    
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void execute_change (void);

#endif  /* APP_H */

/**********************************************************************************************************************
 *  END OF FILE: APP.h
 *********************************************************************************************************************/
