#ifndef _CONFIG_ETCH_A_SKETCH
#define _CONFIG_ETCH_A_SKETCH

// SET number of LED matrix displays in use. Wokwi simulation uses 2.
#define NUMBER_OF_SEGMENTS 2

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 

// SET MAX_COLUMNS to number of segments times 8.
// 1 segment -> 8, 2 segments -> 16, 3 segments -> 24, 4 segments -> 32
#define MAX_COLUMNS 16
#define MAX_ROWS 8
#define ANALOG_HIGH 768
#define ANALOG_LOW 256

#define JOYSTICK_BUTTON 2
#define JOYSTICK_VERTICAL 0
#define JOYSTICK_HORIZONTAL 1

#endif