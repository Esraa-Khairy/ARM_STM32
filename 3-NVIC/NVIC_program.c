
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "NVIC_interface.h"
#include "NVIC_config.h"
#include "NVIC_register.h"



void NVIC_InitPriority (void)
{

#define SCB_AIRCR *((volatile u32*)0xE000ED0C)
	/*bit 7&6 for group */
	/* bit 5&4 for sub */
	SCB_AIRCR = 0xd05FA0500;

	}


void NVIC_voidSetPriority (u8 Copy_u8Idx,u8 Copy_priority)    // kol register byandle 4
{
	NVIC_IPR[Copy_u8Idx]=Copy_priority;

}

void NVIC_voidEnableExtInt (u8 Copy_u8Idx)
{
  if ( Copy_u8Idx <=31)
  {
    SET_BIT(NVIC_ISER0,Copy_u8Idx);
  }
  else if (Copy_u8Idx <=59)
  {
	  Copy_u8Idx-=32;
    SET_BIT(NVIC_ISER1,Copy_u8Idx);
  }
  
  
}

void NVIC_voidDisableExtInt (u8 Copy_u8Idx)
{
	 if ( Copy_u8Idx <=31)
	  {
	    SET_BIT(NVIC_ICER0,Copy_u8Idx);
	  }
	  else if (Copy_u8Idx <=59)
	  {
		Copy_u8Idx-=32;
	    SET_BIT(NVIC_ICER1,Copy_u8Idx);
	  }

}

void NVIC_voidSetPendingFlag (u8 Copy_u8Idx)
{
	 if ( Copy_u8Idx <=31)
	  {
	    SET_BIT(NVIC_ISPR0,Copy_u8Idx);
	  }
	  else if (Copy_u8Idx <=59)
	  {
		  Copy_u8Idx-=32;
	    SET_BIT(NVIC_ISPR1,Copy_u8Idx);
	  }

}

void NVIC_voidClearPendingFlag (u8 Copy_u8Idx)
{
	 if ( Copy_u8Idx <=31)
	  {
	    SET_BIT(NVIC_ICPR0,Copy_u8Idx);
	  }
	  else if (Copy_u8Idx <=59)
	  {
		  Copy_u8Idx-=32;
	    SET_BIT(NVIC_ICPR1,Copy_u8Idx);
	  }

}

u8 NVIC_voidGetActiveFlag (u8 Copy_u8Idx)
{
	u8 Local_u8Result;

	 if ( Copy_u8Idx <=31)
	  {
	    Local_u8Result=GET_BIT(NVIC_IABR1,Copy_u8Idx);
	  }
	  else if (Copy_u8Idx <=59)
	  {
		  Copy_u8Idx-=32;
	    Local_u8Result=GET_BIT(NVIC_IABR1,Copy_u8Idx);
	  }


}


