#ifndef DIO_H_
#define DIO_H_
/*PORT*/

#define PORT_A 1
#define PORT_B 2
#define PORT_C 3
#define PORT_D 4

#define DDR_A 1
#define DDR_B 2
#define DDR_C 3
#define DDR_D 4

#define PIN_A 1
#define PIN_B 2
#define PIN_C 3
#define PIN_D 4
/*pinNumber*/
#define  PIN0 0
#define  PIN1 1
#define  PIN2 2
#define  PIN3 3
#define  PIN4 4
#define  PIN5 5
#define  PIN6 6
#define  PIN7 7
/*Value*/
#define  HIGH 1
#define  LOW 0
/*Direction*/
#define INPUT 0
#define OUTPUT 1

void DIO_init(uint8_t portNumber , uint8_t pinNumber , uint8_t pinDirection); //Initialize DIO directions.
void DIO_write(uint8_t portNumber , uint8_t pinNumber , uint8_t value); // Write data into pin
void DIO_toggle(uint8_t portNumber , uint8_t pinNumber); // toggle pin
void DIO_read(uint8_t portNumber , uint8_t pinNumber , uint8_t *value); // read data

#endif /* DIO_H_ */