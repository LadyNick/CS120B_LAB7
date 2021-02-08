/*	Author: lab
 *  Partner(s) Name: Nicole Navarro
 *	Lab Section:21
 *	Assignment: Lab #7  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *	Demo Video: https://youtu.be/xK6X6s-XPTg
 *
 *	I was recording with flash because that's how I got my MAX so it's kind of hard to tell but I promise you that all the LEDs are begin light up and turned off with changes in exposure to light.
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
	/*For the 8 divions of MAX = 0X147, divided by 8 is 40.8 so ill round up to 41
	 * 1: 0 
	 * 2: 41
	 * 3: 82
	 * 4: 123
	 * 5: 164
	 * 6: 205
	 * 7: 246
	 * 8: 287
	 */

	ADC_init();

    while (1) {
	unsigned short x = ADC;
	if(x > 0){
		PORTB = 0X01;
	}
	if(x > 41){
		PORTB = 0X02;
	}
	if(x > 82){
		PORTB = 0x04;
	}
	if(x > 123){
		PORTB = 0x08;
	}
	if(x > 164){
		PORTB = 0x10;
	}
	if(x > 205){
		PORTB = 0x20;
	}
	if(x > 246){
		PORTB = 0x40;
	}
	if(x > 287){
		PORTB = 0X80;
	}
    }
    return 1;
}
