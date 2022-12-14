#include "../../Utilities/std_types.h"
#include "../../Utilities/bit_math.h"
#include "../../Utilities/register.h"
#include "DIO.h"

void DIO_init(uint8_t portNumber , uint8_t pinNumber , uint8_t pinDirection)
{
	switch(portNumber)
	{
		case PORT_A :
			if(pinDirection ==	OUTPUT) 
			SET_BIT(DDRA , pinNumber);
			else
			CLR_BIT(DDRA , pinNumber);
		break;
		case PORT_B :
			if(pinDirection == OUTPUT)
			SET_BIT(DDRB , pinNumber);
			else
			CLR_BIT(DDRB , pinNumber);
		break;
		case PORT_C :
			if(pinDirection == OUTPUT)
			SET_BIT(DDRC , pinNumber);
			else
			CLR_BIT(DDRC , pinNumber);
		break;
			case PORT_D :
			if(pinDirection == OUTPUT)
			SET_BIT(DDRD , pinNumber);
			else
			CLR_BIT(DDRD , pinNumber);
		break;  
	}
}
void DIO_write(uint8_t portNumber , uint8_t pinNumber , uint8_t value)
{
	switch(portNumber)
	{
		case PORT_A :
		if(value == HIGH)
		SET_BIT(PORTA , pinNumber);
		else if(value == LOW)
		CLR_BIT(PORTA , pinNumber);
		break;
		case PORT_B :
		if(value == HIGH)
		SET_BIT(PORTB , pinNumber);
		else if(value == LOW)
		CLR_BIT(PORTB , pinNumber);
		break;
		case PORT_C :
		if(value == HIGH)
		SET_BIT(PORTC , pinNumber);
		else if(value == LOW)
		CLR_BIT(PORTC , pinNumber);
		break;
		case PORT_D :
		if(value == HIGH)
		SET_BIT(PORTD , pinNumber);
		else if(value == LOW)
		CLR_BIT(PORTD , pinNumber);
		break;
	}
}
void DIO_toggle(uint8_t portNumber , uint8_t pinNumber)
{
	switch(portNumber)
	{
		case PORT_A :
		TOG_BIT(PORTA , pinNumber);
		break;
		case PORT_B :
		TOG_BIT(PORTB , pinNumber);
		break;
		case PORT_C :
		TOG_BIT(PORTC , pinNumber);
		break;
		case PORT_D :
		TOG_BIT(PORTD , pinNumber);
		break;
	}
}
void DIO_read(uint8_t portNumber , uint8_t pinNumber , uint8_t *value)
{
	switch(portNumber)
	{
		
		case PORT_A :
		*value = READ_BIT(PINA , pinNumber);
		break;
		case PORT_B :
		*value = READ_BIT(PINB , pinNumber);
		break;
		case PORT_C :
		*value = READ_BIT(PINC , pinNumber);
		break;
		case PORT_D :
		*value = READ_BIT(PIND , pinNumber);
		break;
	}
}