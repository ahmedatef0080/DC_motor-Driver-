/*
 * DC_Motor.c
 *
 * Created: 9/5/2020 5:09:55 PM
 * Author : Ahmed Atef
 */ 

#include "Timer.h"

#include "Dc_Motor.h"


int main(void)
{
	
	DC_Motor_init();
	
	
	
	
	Dc_Motor_Direction(CLOCK_WISE_DRIRECTION);
	
	
	
	
	DC_Motor_Set_Speed(8);
	
	
	
	
	
	DC_Motor_Start();
	
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

