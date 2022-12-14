#include <avr/io.h>
/*#include "../../Utilities/std_types.h"*/
#include "../../Utilities/bit_math.h"
/*#include "../../Utilities/register.h"*/
#include "../../MCAL/DIO/DIO.h" 
#include "timer1.h"
void PWM_OC1A_FM_init()
{
	DIO_init(PORT_D , PIN5 , OUTPUT); /*OCR0 AS OUTPUT.*/
	TCCR1A |= (1 << COM1A1) | (1 << WGM10) | (1 << WGM11);/*Non inverting mood (HIGH IS FIRST).*/
	TCCR1B |= (1 << WGM12) | (1 << CS10);/*start timer1 with no prescelar - 8 bit FAST MODE (1023 for overflow).*/
}
void PWM_OC1A_FM_setDuty(uint8_t dutyCycle)
{
	OCR1AL = dutyCycle*10.23;
	OCR1AH |= (((uint16_t)(dutyCycle*10.23)) >> 8);
}
void PWM_OC1A_phaseCorrect_init()
{
	DIO_init(PORT_D , PIN5 , OUTPUT); /*OCR0 AS OUTPUT.*/
	TCCR1A |= (1 << COM1A1) | (1 << WGM10) | (1 << WGM11);/*Non inverting mood (HIGH IS FIRST).*/
	TCCR1B |= (1 << CS10);/*start timer1 with no prescelar - 10 bit phase correct (1204 for overflow).*/
}
void PWM_OC1A_phaseCorrect_setDuty(uint8_t dutyCycle)
{
	OCR1AL = dutyCycle*10.23;
	OCR1AH |= (((uint16_t)(dutyCycle*10.23)) >> 8);
}
uint16_t ICU()
{
	uint16_t t1  = 0 ,t2 = 0;
	TCCR1A = 0;
	TCCR1B |= (1 << CS10) | (1 << ICES1) | (1 << ICNC1); /*Rising edge , No prescaler , Noise Canceler*/
	TIFR |= (1 << ICF1); /*Clear the Bit*/
	while(READ_BIT(TIFR , ICF1) == 0); /*Wait until detect first rising edge.*/
    t1 = ICR1;
	TIFR |= (1 << ICF1); /*Clear the Bit*/
	/******************************************************************************/
	CLR_BIT(TCCR1B , ICES1); /*Falling edge*/
	TCCR1B |= (1 << CS10) | (1 << ICNC1); /*No prescaler , Noise Canceler*/
	while(READ_BIT(TIFR , ICF1) == 0); /*Wait until detect falling edge.*/
	t2 = ICR1;
	TIFR |= (1 << ICF1); /*Clear the Bit*/
	TCNT1 = 0;
	TCCR1B = 0;
	return t2 - t1;
}
