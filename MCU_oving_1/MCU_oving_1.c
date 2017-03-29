/*
 * MCU_oving_1.c
 *
 * Created: 22.03.2017 16.35.59
 *  Author: loewe_000
 */ 
#define F_CPU 16000000
#define HIGH 1
#define LOW 0 

#include <avr/io.h>
#include <util/delay.h>
#include "switch.h"
#include "led.h"


int main(void)
{
	led_init();
	switch_init();

    while(1)
    {
		for (int i = 0; i < 4; i++)
		{
			if (switch_read(i) == HIGH)
			{
				led_set(i,HIGH);
			}
			else
			{
				led_set(i,LOW);
			}
		}
    }
}
