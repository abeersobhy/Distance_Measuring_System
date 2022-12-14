/*
 * timer1.h
 *
 * Created: 04/09/2022 04:10:16 م
 *  Author: user
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_


void PWM_OC1A_FM_init();
void PWM_OC1A_FM_setDuty(uint8_t dutyCycle);
void PWM_OC1A_phaseCorrect_init();
void PWM_OC1A_phaseCorrect_setDuty(uint8_t dutyCycle);
uint16_t ICU();
#endif /* TIMER1_H_ */