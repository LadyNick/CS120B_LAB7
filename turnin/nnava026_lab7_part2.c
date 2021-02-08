/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #7  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *	Demo Video: https://youtu.be/hKn3WsQE3vw
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
	DDRA = 0X00; PINA = 0XFF;

	ADC_init();

    while (1) {
	unsigned short x = ADC;
	unsigned char right = (char)x;
	unsigned char left = (char)(x>>8);
	PORTB = right;
	PORTD = left;
    }
    return 1;
}
