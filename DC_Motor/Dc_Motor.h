/*
 * Dc_Motor.h
 *
 * Created: 9/5/2020 5:12:11 PM
 *  Author: Ahmed Atef
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "Timer.h"

#include "DIO.h"

#define CLOCK_WISE_DRIRECTION     0
#define ANTI_CLOCK_WISE_DIRECTION 1
/*
typedef enum
{
	CLOCK_WISE_DRIRECTION,
	ANTI_CLOCK_WISE_DIRECTION
	}DC_MOTOR_DIR;
*/


void DC_Motor_init(void);


void Dc_Motor_Direction(uint8 dir);



void DC_Motor_Set_Speed(uint8 speed);



void DC_Motor_Start(void);


void DC_Motor_Stop(void);



#endif /* DC_MOTOR_H_ */