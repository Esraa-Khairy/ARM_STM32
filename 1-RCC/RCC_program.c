#include "BIT_MATHS.h"
#include "STD_TYPES.h"
#include "RCC_registers.h"
#include "RCC_private.h"
#include "RCC_config.h"
#include "RCC_interface.h"

extern void RCC_Init(void)
{
  /* HSI -> off


  PLL -> off
  HSE -> ON
  CSS -> OFF */
  RCC_CR= 0x00010000;
  
  /* Sysclk -> HSE
  AHB,APB1,APB2 -> no devision
  MCO -> not connected*/
  RCC_CFGR= 0X00000001; 
}

extern void RCC_EnableClock (u8 Bus , u8 perphiral)
{
  switch (Bus)
  {
    case 0: SET_BIT(RCC_AHBENR,perphiral);break;
    case 1: SET_BIT(RCC_APB1ENR,perphiral);break;
    case 2: SET_BIT(RCC_APB2ENR,perphiral);break;
  }
  
}

extern void RCC_DisableClock (u8 Bus , u8 perphiral)
{
  switch (Bus)
  {
    case 0: CLR_BIT(RCC_AHBENR,perphiral);break;
    case 1: CLR_BIT(RCC_APB1ENR,perphiral);break;
    case 2: CLR_BIT(RCC_APB2ENR,perphiral);break;
  }
  
}
