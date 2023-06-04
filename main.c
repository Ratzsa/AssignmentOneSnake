#include <stdio.h>
#include "uart.h"
#include "max72xx.h"
#include "analogRead.h"
#include <string.h>
#include <util/delay.h>

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 

#define MAX_COLUMNS 16
#define MAX_ROWS 8

#define JOYSTICK_BUTTON 2
#define JOYSTICK_VERTICAL 0
#define JOYSTICK_HORIZONTAL 1

void clearScreen();

int main()
{
    BIT_CLEAR(DDRD, JOYSTICK_BUTTON);
    BIT_SET(PIND, JOYSTICK_BUTTON);
    BIT_CLEAR(DDRC, JOYSTICK_VERTICAL);
	BIT_CLEAR(DDRC, JOYSTICK_HORIZONTAL);
    
    int x = 0;
    int y = 0;

	init_serial();
	max7219_init();

    

	while (1)
    {
        if(!BIT_CHECK(PIND, JOYSTICK_BUTTON))
        {
            clearScreen();
        }

        if(x == MAX_COLUMNS)
        {
            clearScreen();
            x = 0;
            y = 0;
        }

        if(y == MAX_ROWS)
        {
            x++;
            y = 0;
        }

        max7219b_set(x, y);
        max7219b_out();
        _delay_ms(50);
        y++;

		// for(int x = 0; x < MAX_COLUMNS; x++)
        // {
		// 	for(int y = 0; y < MAX_ROWS; y++)
        //     {
                
        //         max7219b_set(x, y);
        //         max7219b_out();
        //         _delay_ms(50);
        //     }
        // }
	}
	return 0;
}

void clearScreen()
{
    for(int x = 0; x < MAX_COLUMNS; x++)
    {
        for(int y = 0; y < MAX_ROWS; y++)
        {
            max7219b_clr(x, y);
            max7219b_out();
        }
    }
}