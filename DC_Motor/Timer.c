/*
 * Timer.c
 *
 * Created: 9/1/2020 4:00:14 PM
 *  Author: Ahmed Atef
 */ 



#include "Timer.h"

#include <avr/interrupt.h>

uint8 init_Value = 0 ;

uint32 N_OF_OVR_FLOWS = 0;

#define NULL ((void *)(0))
void (*ptr)(void)= NULL ;







void Timer0_init(void)
{
	 TCCR0 |=0x00;   //initialize normal mode


	  //clear_bit(TCCR0,3);  //initialize normal mode 
	  
	  
	 TIMSK |= 0x01;        //set_bit(TIMSK,1);    //enable interrupt
	  
	  
	  SREG |= 0X80;  // GLOBAL INTERRUPT
	  
	 
}



void Timer0_Start(void)
{
	TCCR0 |= 0x05; // initialize clock 1024 clk
}



void Timer0_Stop(void)
{
	// disconect prescaler
	clear_bit(TCCR0,0);
	clear_bit(TCCR0,1);
	clear_bit(TCCR0,2);

	
}



void Timer0_SetDelay(uint32 Delay_Ms)
{
	uint8 Tick_Time = (1024/16); // (prescaler/oscilator) mili_second delay
	
	uint32 Total_Ticks = (Delay_Ms * 1000/*TO be micro secon*/) / Tick_Time;

	N_OF_OVR_FLOWS = Total_Ticks / 265 ; // know number of over flows

	init_Value = 256 - (Total_Ticks % 256); // to detrmind which number of tick should i set to complete Delay_Ms accuracy

	TCNT0 = init_Value ; // set TCNT0 reg at specific tick to make delay_ms accurte (3shan el ksor bt3t el over flow )

	N_OF_OVR_FLOWS++; // over flow ++ for decimal number of over flows
	
}



/******************************************** tIMER 1 *****************************/
void Timer1_init(void){
	
	TCCR1B |= 0X08; //SET CTC MODE 
	TIMSK |= 0X10; // ENABLE INTERRUPT
	SREG =0X80; // global interrtups 
}



void Timer1_Start(void){
	TCCR1B |= 0X05; // set prescaler 
	
}



void Timer1_Stop(void){
	clear_bit(TCCR1B,0);
	clear_bit(TCCR1B,1);
	clear_bit(TCCR1B,2);
	
}



void Timer1_SetDelay(uint32 Delay_Ms){
	if(Delay_Ms <=4000)
	{
		uint8 Tick_Time = 1024 / 16 ;
		uint32 num_of_ticks = (Delay_Ms *1000)/ Tick_Time;
		OCR1A = num_of_ticks - 1;
	}
}


void Set_Call_Back(void(*Pointer)(void))
{
	ptr = Pointer ;
}






/*************************************************** PWM *********************************/




void PWM_Init(void)
{
	
	DDRB |=(1<<3); // set port B pin 3 as OUTPUT 
	
	TCCR0 |=0x68; // fast PWM mode "non inverted mode "
}


void PWM_Generation(uint16 Duty_Cycle)
{
	OCR0 = ((256 * Duty_Cycle)/100)-1;
}



void PWM_Start(void)
{
	// Fgeneration= Fosc/number of timer bit * prescaler 
	set_bit(TCCR0,CS00);
}





/**************************************** Interrupts **************************************/

ISR(TIMER0_OVF_vect)
{
	static uint32 counter =0;
	counter++;
	if(counter == N_OF_OVR_FLOWS)
	{
		TCNT0 = init_Value;
		
		counter = 0;
		(*ptr)();		
	}

}






/*
ISR(TIMER1_CAPT_vect)
{
	static counter = 0 ;
	counter ++;
	if (counter ==1)
	{
		counter=0;
		LED0_Toggle();
	}

}
*/