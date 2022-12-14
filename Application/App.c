#define F_CPU 16000000UL
#include <util/delay.h>
#include "../ECUAL/LCD/LCD.h"
#include "../ECUAL/Ultrasonic/Ultrasonic.h"

uint8_t string[][16] =  {
	"distance = ",
	"cm",
	"No object !"
};
uint16_t distance = 0;
void AppInit()
{
	LCD_4BIT_inti(); /*Initialize 4 bit mode LCD.*/
	Ultrasonic_Init(); /*Initialize the ultrasonic sensor.*/
}
void AppStart()
{
	distance = Ultrasonic_CalculateDistance(); /*Calculate the distance.*/
	if(distance >= 70)  /*Max range of distance exceeds.*/
	{
		LCD_Write_4BIT_Command(LCD_Clear); /*Clear the LCD*/
		LCD_Write_String(string[2]);	/*No object*/
		_delay_ms(500);
	}	
	else /*detect an object into range of less than 70 cm.*/
	{
		LCD_Write_4BIT_Command(LCD_Clear);
		LCD_Write_String(string[0]); /*"distance"*/
		LCD_Write_Number(distance); /*distance*/
		LCD_Write_String(string[1]); /*"cm"*/
		_delay_ms(500);
	}
}