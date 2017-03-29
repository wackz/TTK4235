/*
 * CFile1.c
 *
 * Created: 22.03.2017 16.48.02
 *  Author: loewe_000
 */ 
#include <avr/io.h>

void led_init(void)
{
	for(int i = 0; i < 8; i += 2)
	{
		DDRB |= (1 << i);
		PORTB |= (1 << i);
	}
}

void led_set(int led_number, int led_value)
{
	if (led_value > 0)
	{
		PORTB &= ~((1 << led_number*2));
	}
	else
	{
		PORTB |= (1 << (led_number*2));
	}
}