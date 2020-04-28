/**********************/
/* Author: Esraa Awad */
/* Date: 2 feb 2020   */
/* version : Vo1      */
/**********************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H



void NVIC_voidEnableExtInt (u8 Copy_u8Idx);

void NVIC_voidDisableExtInt (u8 Copy_u8Idx);

void NVIC_voidSetPendingFlag (u8 Copy_u8Idx);

void NVIC_voidClearPendingFlag (u8 Copy_u8Idx);

u8 NVIC_voidGetActiveFlag (u8 Copy_u8Idx);

void NVIC_voidSetPriority (u8 Copy_u8Idx,u8 Copy_priority) ;

void NVIC_InitPriority (void);


#endif
