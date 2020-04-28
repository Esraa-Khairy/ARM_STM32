

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

#include "STD_TYPES.h"



void STK_voidInitialize (void);

void STK_voidStart (u32 Copy_u32Value);

void STK_voidSetCallBack (void (*Copy_Ptr)(void));

void STK_voidBusyDelay (u32 Copy_microseconds);

#endif
