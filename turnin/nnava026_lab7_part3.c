/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #7  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *	Demo Video: https://youtu.be/gLBwyajFbZQ
 *
 *	My max is different because for some reason with my other max the light would never ever turn off even with all my lights off and a mug covering the small light from the programmer and the power supply. My max in this video was 0X147.
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
	//ADEN enable analog to digital, ADSC starts first conversion, ADATE enables auto triggering
}

int main(void) {
	DDRB = 0XFF; PORTB = 0X00;
	DDRD = 0XFF; PORTD = 0X00;


	ADC_init();

    while (1) {
	unsigned short x = ADC;
	if(x >= (0x147 / 2)){
		PORTB = 0x01;
	}
	else{
		PORTB = 0x00;
	}
    }
    return 1;
}
