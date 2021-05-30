/*
 * Dc_Motor.c
 *
 * Created: 9/5/2020 5:11:55 PM
 *  Author: Ahmed Atef
 */ 
#include "Dc_Motor.h"


void DC_Motor_init(void){
	
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN3,DIO_PIN_OUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN4,DIO_PIN_OUT);
	PWM_Init();

	
}

void PWM_LED(void)
{
	
	DIO_SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
}


void Dc_Motor_Direction(uint8 dir){
	switch(dir)
	{
		case CLOCK_WISE_DRIRECTION :
		DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
		DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
		break;
		
		case ANTI_CLOCK_WISE_DIRECTION:
		DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
		DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_HIGH);
		
		break;
		
		
		
		default:
		break;
		}
	
}



void DC_Motor_Set_Speed(uint8 speed){
	
	speed *= 10;     // multiplay by 10 3shan lma ab3to l PWM_GEN ydene DC 2li 3wzha
	PWM_Generation(speed);
}



void DC_Motor_Start(void)
{
	PWM_Start();
	
}


void DC_Motor_Stop(void)
{
DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_HIGH);
}