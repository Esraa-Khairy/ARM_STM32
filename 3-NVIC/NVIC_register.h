/**********************/
/* Author: Esraa Awad */
/* Date: 2 feb 2020   */
/* version : Vo1      */
/**********************/

#ifndef NVIC_REGISTER_H
#define NVIC_REGISTER_H


/* set enable registers*/
#define NVIC_ISER0    *((volatile u32*)0xE000E100)
#define NVIC_ISER1    *((volatile u32*)0xE000E104)

/* clear enable register */
#define NVIC_ICER0     *((volatile u32*)0xE000E180)
#define NVIC_ICER1     *((volatile u32*)0xE000E184)


/* set pending flag */
#define NVIC_ISPR0     *((volatile u32*)0xE000E200)
#define NVIC_ISPR1     *((volatile u32*)0xE000E204)


/* clear  pending flag */
#define NVIC_ICPR0    *((volatile u32*)0xE000E280)
#define NVIC_ICPR1    *((volatile u32*)0xE000E284)


/* get active flag */
#define NVIC_IABR0     *((volatile u32*)0xE000E300)
#define NVIC_IABR1     *((volatile u32*)0xE000E304)


#define NVIC_IPR  ((volatile u8*)0xE000E400)      // for byte access  this a ptr

#endif
