#include <stdio.h>
#include <stdint.h>
#include "uart.h"
#include "max72xx.h"
#include "analogRead.h"
#include <util/delay.h>

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 

#define MAX_COLUMNS 8
#define MAX_ROWS 8
#define ANALOG_HIGH 768
#define ANALOG_LOW 256

#define JOYSTICK_BUTTON 2
#define JOYSTICK_VERTICAL 0
#define JOYSTICK_HORIZONTAL 1

void clearScreen();
void setMarker(uint8_t x, uint8_t y);

int main()
{
    BIT_CLEAR(DDRD, JOYSTICK_BUTTON);
    BIT_SET(PIND, JOYSTICK_BUTTON);
    BIT_CLEAR(DDRC, JOYSTICK_VERTICAL);
	BIT_CLEAR(DDRC, JOYSTICK_HORIZONTAL);
    
    uint8_t x = 7;
    uint8_t y = 0;

	init_serial();
	max7219_init();

    clearScreen();
    _delay_ms(50);
    // Set start LED
    setMarker(x, y);
    _delay_ms(500);

	while (1)
    {
        int16_t horizontalMove = analogRead(JOYSTICK_HORIZONTAL);
        int16_t verticalMove = analogRead(JOYSTICK_VERTICAL);

        if(!BIT_CHECK(PIND, JOYSTICK_BUTTON))
        {
            clearScreen();
        }
        
        setMarker(x, y);

        if(horizontalMove < ANALOG_LOW && x != 7)
        {
            x++;
        }

        if(horizontalMove > ANALOG_HIGH && x != 0)
        {
            x--;
        }

        if(verticalMove < ANALOG_LOW && y != 0)
        {
            y--;
        }

        if(verticalMove > ANALOG_HIGH && y != 7)
        {
            y++;
        }
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
        }
    }
    max7219b_out();
}

void setMarker(uint8_t x, uint8_t y)
{
    max7219b_set(x, y);
    max7219b_out();
    _delay_ms(100);
}