#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "STK_register.h"
#include "STK_interface.h"




void (*SysTick_callBack)(void);
void STK_voidInitialize (void)
{

	/* ENABLE systick interrupt  -clock AHB =8  */
		STK_CTRL=0x00000002;


}

void STK_voidStart (u32 Copy_u32Value)
{
		STK_LOAD = Copy_u32Value;

		STK_VAL =0;

		SET_BIT(STK_CTRL,0);
}

void STK_voidSetCallBack (void (*Copy_Ptr)(void))
{

		SysTick_callBack = Copy_Ptr;
}


void SysTick_Handler (void)
{
	SysTick_callBack();
}

void STK_voidBusyDelay (u32 Copy_microseconds)
{

	/*disable interrupt */
	CLR_BIT(STK_CTRL,1);


	/* load "load register"and clear "load value"*/
	STK_LOAD = Copy_microseconds;
	STK_VAL = 0;

	/* Enable STK */
	SET_BIT(STK_CTRL , 0);

	/* wait flag */
	while ( (GET_BIT(STK_CTRL,16)) == 0 );   // flag eli hytrf3 lma stk ykon be zero and hena msh 3mlaha be interruptde synchronous
}
