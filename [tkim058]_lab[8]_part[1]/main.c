/*
 * [tkim058]_lab[8]_part[1].c
 * Partner(s) Name & E-mail: MinHwan Oh
 * Lab Section: B01
 * Assignment: Lab #7 Exercise #1
 * Exercise Description: [A2D]
 *
 * I acknowledge all content contained herein, excluding template or example
 * code, is my own original work.
 */ 


#include <avr/io.h>

void ADC_init()
{
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void)
{
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	
	ADC_init();
	
	unsigned short x;
	
	while (1)
	{
		x = ADC;
		PORTB = (char)(x & 0x00FF);
		PORTD = (char)(x >> 6);
	}
}

