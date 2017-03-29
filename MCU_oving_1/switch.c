/*
 * CFile1.c
 *
 * Created: 22.03.2017 16.48.15
 *  Author: loewe_000
 */ 
#include <avr/io.h>

void switch_init(void)
{
	for(int i = 1; i < 8; i += 2)
	{
		DDRB &= ~(1 << i);
	}
}
int switch_read(int button_number)
{
	if (PINB & (1<<(button_number*2 + 1)))
	{
		return 0;
	}
	return 1;
}
