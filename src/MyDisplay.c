/**
 * @file MyDisplay.c
 * @author Dario Carvalho (dariocarvalho2019@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-07-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "MyDisplay.h"

// given a number i, fNumber[i] returns a 7 seg display code that corresponds to i
const uint32_t fNumber[11] = {0xFC, 0x60, 0xda, 0xf2, 0x66, 0xb6, 0xbe, 0xe0, 0xfe, 0xf6, 0x00};

// given a letter between A and Z excluding Y , fChar[a] returns a 7 seg display cde that
// corresponds to s
const uint32_t fChar[25] = {0xfa, 0x3e, 0x9c, 0x7a, 0xde, 0x8e, 0xbe, 0x6e, 0x0c,
			    0x78, 0x6e, 0x1c, 0xec, 0xec, 0xfc, 0xce, 0xe6, 0x8c,
			    0xb6, 0x3c, 0x7c, 0x7c, 0x6e, 0xda, 0x00};

#define LED0_OFFSET   0
#define LED1_OFFSET   16
#define LED2_OFFSET   48
#define LED3_OFFSET   64
#define CENTRAL_POINT 33
#define DEGREE_POINT  36

/**
 * @brief given a position of a led, return its offset according to the LED API.
 *
 * @param pos the position of the element on the display. At the moment it can be a value between 0
 * and 3 representing each display from left to right respectively.
 * @return the offset of the led according to the LED driver API.
 */
static uint32_t offsetLED(uint32_t pos)
{
	uint32_t offset = 0;
	switch (pos) {
	case 0:
		offset = LED0_OFFSET;
		break;
	case 1:
		offset = LED1_OFFSET;
		break;
	case 2:
		offset = LED2_OFFSET;
		break;
	case 3:
		offset = LED3_OFFSET;
	}

	return offset;
}

static void writeValue(const struct device *const led, uint32_t number, uint32_t offset)
{
	uint32_t un = 2;

	for (int j = 6; j >= 0; j--) {
		if (un & number) {
			led_on(led, offset + j);
		} else {
			led_off(led, offset + j);
		}
		un = un * 2;
	}
}

uint32_t displaySingleNumber(uint32_t num, uint32_t position, const struct device *const led)
{
	uint32_t number = fNumber[num];
	uint32_t offset = offsetLED(position);
	writeValue(led, number, offset);
	return 0;
}

void displayChar(char letter, uint32_t position, const struct device *const led)
{
	uint32_t offset = offsetLED(position);
	uint32_t charNum = letter - 'A';
	charNum = fChar[charNum];
	writeValue(led, charNum, offset);
}

void displayNum(uint32_t num, const struct device *const led)
{
	uint32_t n1 = num / 1000;
	uint32_t n2 = ((num % 1000) / 100);
	uint32_t n3 = (((num % 1000) % 100) / 10);
	uint32_t n4 = (((num % 1000) % 100) % 10);
	displaySingleNumber(n1, 0, led);
	displaySingleNumber(n2, 1, led);
	displaySingleNumber(n3, 2, led);
	displaySingleNumber(n4, 3, led);
}

void displayString(const char *phrase, const struct device *const led)
{
	int i = 0;
	while (phrase[i] != '\0') {
		if (phrase[i] >= 'A' && phrase[i] < 'Z') {
			displayChar(phrase[i], i, led);
		} else if (phrase[i] >= '0' && phrase[i] <= '9') {
			displaySingleNumber((uint32_t)(phrase[i]) - 48, i, led);
		}
		i++;
	}
}

void setStateCentralPoint(const struct device *const led, uint32_t state)
{
	(state == true) ? led_on(led, CENTRAL_POINT) : led_off(led, CENTRAL_POINT);
}

void setDegreePointState(const struct device *const led, uint32_t state)
{
	(state == true) ? led_on(led, DEGREE_POINT) : led_off(led, DEGREE_POINT);
}