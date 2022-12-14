/*
 * Ultrasonic.c
 *
 * Created: 14/11/2022 07:10:57 م
 *  Author: user
 */
#define F_CPU 16000000UL
#include <util/delay.h>
#include "../../Utilities/bit_math.h"
#include "../../Utilities/register.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/TIMER1/timer1.h"
#include "Ultrasonic_config.h"

void Ultrasonic_Init()
{
	DIO_init(PORT_D , PIN5 , OUTPUT);  /*Trigger pin as output.*/
	DIO_init(PORT_D , PIN6 , INPUT);  /*Echo pin as input.*/
}
uint16_t Ultrasonic_CalculateDistance()
{
	uint16_t distance = 0 , _time_ = 0;
	DIO_write(PORT_D , PIN5 , LOW); /*STo make sure that the trigger pin is LOW.*/
	_delay_us(2);
	DIO_write(PORT_D , PIN5 , HIGH); /*Make the trigger pin HIGH for 20 micro second.*/
	_delay_us(20);
	DIO_write(PORT_D , PIN5 , LOW); /*Make the trigger pin LOW.*/
    distance=((ICU()*34600)/(F_CPU*2)) ;
	/*_time_ = ICU() * (1/16000000);
 	distance = (_time_ / 2) * 0.034;*/
    return distance;	
}