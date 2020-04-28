/*
 * SPI_program.c
 *
 *  Created on: Apr 22, 2020
 *      Author: pc
 */
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "SPI_interface.h"
#include "SPI_registers.h"


void SPI1_Init (void)
{

	/* Phase = Write then read
	 * polarity = Idle low
	 * Master Mode =APB2 clock /4
	 * Spi enable and msb first - 8 bit data
	 * ss managed by sw (NSS pin disconnected from uC)*/
	SPI1 -> CR1  = 0x034D;

}


/* u8 mode u16 mode it can recieve and sn=end full duplex */
u8 SPI_u8SendSynch (u8 Copy_u8Data)
{

	/* Send data */
SPI1 -> DR =(u32)Copy_u8Data;

/* wait busy flag */
while (GET_BIT((SPI1->SR) , 7) == 1);
	return SPI1->DR;   // if it read as it is a full duplex

}
/**  Assignment  ***/
/*u16 send synch*/
/*u8 asycnch*/
/*u16 asynch*/




