/*
 * Timer.h
 *
 * Created: 9/1/2020 3:59:59 PM
 *  Author: Ahmed Atef
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "ATmega_Registers.h"
#include "BIT_MATH.h"

void Timer0_init(void);



void Timer0_Start(void);



void Timer0_Stop(void);



void Timer0_SetDelay(uint32 Delay_Ms);


/******************************************** tIMER 1 *****************************/

void Timer1_init(void);



void Timer1_Start(void);



void Timer1_Stop(void);



void Timer1_SetDelay(uint32 Delay_Ms);


/*************************************************** PWM *********************************/




void PWM_Init(void);


void PWM_Generation(uint16 Duty_Cycle);



void PWM_Start(void);








void Set_Call_Back( void (*Pointer)(void));








#endif /* TIMER_H_ */