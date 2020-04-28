#include "BIT_MATHS.h"
#include "STD_TYPES.h"

#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO_interface.h"

extern void DIO_SetPinMode (u8 port , u8 pin , u8 mode)   // user give me 4 bits mode 
{
  switch (port)
  {
  case 'A':
    if ( pin <=7)   // u8 from 0 to 255 so warning it never be smaller than 0
    {
      /*clear 4 bits */
      PORTA_CRL &=~((0b1111)<<(pin*4));
      /* set mode in 4 bits */
      PORTA_CRL |=(mode << (pin*4));
    }
    else if (pin <=15)  // of course it will be larger than or equal 8 so its redundant to write first condition pin >=8 
    {
      pin =pin -8;
      
      PORTA_CRH &=~((0b1111)<<(pin*4));
      PORTA_CRH |=(mode << (pin*4));
    }
    break;
  case 'B':
   if ( pin <=7)   // u8 from 0 to 255 so warning it never be smaller than 0
    {
      /*clear 4 bits */
      PORTB_CRL&=~((0b1111)<<(pin*4));
      /* set mode in 4 bits */
      PORTB_CRL|=(mode << (pin*4));
    }
    else if (pin <=15)  // of course it will be larger than or equal 8 so its redundant to write first condition pin >=8 
    {
      pin =pin -8;
      
      PORTB_CRH &=~((0b1111)<<(pin*4));
      PORTB_CRH |=(mode << (pin*4));
    }
    break;
  case 'C':
   if ((pin >=13 )&& (pin <=15))  // of course it will be larger than or equal 8 so its redundant to write first condition pin >=8 
    {
      pin = pin -8;
      
      PORTC_CRH &=~(0b1111)<<(pin*4);
      PORTC_CRH |=(mode << (pin*4));
    }
    break;
  }
}

extern void DIO_SetPinVal (u8 port , u8 pin , u8 val)
{
  switch(port)
  {
    case 'A': 
              if (val ==1)
                SET_BIT(PORTA_ODR,pin);
              else
                CLR_BIT(PORTA_ODR,pin);
              break;
    case 'B':
              if (val ==1)
                SET_BIT(PORTB_ODR,pin);
              else
                CLR_BIT(PORTB_ODR,pin);
              break;
    case 'C':
              if (val ==1)
                SET_BIT(PORTC_ODR,pin);
              else
                CLR_BIT(PORTC_ODR,pin);
              break;
  }
}
extern u8 DIO_GetPinVal (u8 port, u8 pin)
{
  u8 result;
  switch (port)
  {
    case 'A': result=GET_BIT(PORTA_IDR,pin);break; 
    case 'B': result=GET_BIT(PORTB_IDR,pin);break; 
    case 'C': result=GET_BIT(PORTC_IDR,pin);break; 
  }
  return result;
}
