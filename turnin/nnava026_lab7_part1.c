/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:21
 *	Assignment: Lab #7  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *	https://youtu.be/_R745N4WScY
 *	For some reason my max and min was different from what was in the video, and then I tried rewiring to see if maybe wiring was the problem but that didnt change anything.
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
