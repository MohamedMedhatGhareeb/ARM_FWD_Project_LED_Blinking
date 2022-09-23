/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpio_Lcfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "GPIO.h"
#include "Gpio_Cfg.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/*
1- PortPinMode : Dio - UART - ADC - ...
2- PortPinLevelValue : Initial Value
3- PornPinDirection: Input - Output
4- PortPinInternalAttach: PU - PD - OD
5- PortPinOutputCurrent

*/
const Port_ConfigType GPIOPin_Cfg[GPIOPin_ACTIVE_NO] ={
	
 {  PIN5, PORT_A, Output , DIO, No_AF, PULL_UP, _4mA}, //PA5 ,
 {  PIN5, PORT_B, Output , DIO, No_AF, PULL_DOWN, _8mA},
 {  PIN0, PORT_D, Input , DIO, No_AF, OPEN_DRAIN, No_OC},
 {  PIN2, PORT_B, Input , ALT_Func, AF_I2C, OPEN_DRAIN, No_OC},
 {  PIN7, PORT_C, Input , ALT_Func, AF_AIN, PULL_UP, No_OC},
 };


/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Lcfg.c
 *********************************************************************************************************************/