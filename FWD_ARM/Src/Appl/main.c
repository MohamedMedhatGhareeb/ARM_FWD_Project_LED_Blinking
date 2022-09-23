#include "Platform_Types.h"
#include "IntCtrl.h"
#include "GPIO.h"
#include "GPT.h"
#include "app.h"
void x()
{
	
}

int main (void)
{	
	
	
	

	//GPIO Initialization LEDPin
	Port_Init(&GPIOPin_Cfg[0]);
	//Timer Initialization Timer_0
	GPT_Init(Gpt_Config);
	//Enable Timer Interrupts
	GPT_EnableNotification(Gpt_Config->GptChannelID);
	
	/* user need to input :
		1- Interrupt/exceptions needed to be enabledd
		2- Group Priority
		3- Sub-group Priority
	*/
	//IntCrtl_Init() ;
	
	
	
	
	//Input On Duration & Off Duration for LED Blinking
	On_Duration_OffDuration_ms(400,600);  // in ms
	//Apply Callback Function to change LED Blinking when Timer reaches its desired Value
	GPT_Notification[0] = & execute_change;
	
	while(1)
	{
	}
}
