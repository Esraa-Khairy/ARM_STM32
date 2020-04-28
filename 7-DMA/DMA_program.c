/*
 * DMA_program.c
 *
 *  Created on: Mar 30, 2020
 *      Author: pc
 */
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "DMA_register.h"
#include "DMA_interface.h"
#include "DMA_private.h"



/* DMA channel 1 Init */
void DMA_Init (void)
{
	/* Enable M2M
	 * Data size 32 bits
	 * MINC and PINC =1
	 * no circular
	 * Direction  CPAR -> CMAR
	 * Enable transmission complete interrupt
	 * */
	MYDMA -> channel[0].CCR = 0x00007AC2;
}

/*DMA channel 1 start*/
void DMA_voidStart (u32 Copy_u32SourceAddress , u32 Copy_u32DestAddress , u16 Copy_u32Blocklength)
{

	MYDMA -> channel[0].CPAR  = Copy_u32SourceAddress;
	MYDMA -> channel[0].CMAR  = Copy_u32DestAddress;
	MYDMA -> channel[0].CNDTR = Copy_u32Blocklength;

	/* DMA Channel 1 enable */
	MYDMA -> channel[0].CCR |=1;


}



