/**
 * @file MyDisplay.h
 * @author Dario Carvalho (dariocarvalho2019@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-07-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _DISPLAY_H
#define _DISPLAY_H

#include <stdint.h>
#include <zephyr/drivers/led.h>
#include <zephyr/kernel.h>

#define ON true
#define OFF false
#define DISPLAY_SIZE 4;

/**
 * @brief displays a number between 0 and 9
 * 
 * @param num the number we want display
 * @param position the position at which the nuymber is going to be displayed
 * @param led the device needed by the LED driver
 * @return 0
 */
uint32_t displaySingleNumber(uint32_t num, uint32_t position, const struct device *const led);

/**
 * @brief displays a caracter between A and Z, you must give an upper case char
 * 
 * @param letter the letter we want to display
 * @param position the position of the char on the display.
 * @param led the device needed by the LED driver
 */
void displayChar(char letter,uint32_t position,const struct device *const led);


/**
 * @brief displays a number between 0 and 9999
 * 
 * @param num the number we want to display
 * @param led the device required by the LED driver API
 */
void displayNum(uint32_t num,const struct device *const led);


/**
 * @brief Displays a string
 * 
 * @param phrase a pointer to the string
 * @param led the device needed by the LED driver
 */
void displayString(const char * phrase,const struct device *const led);

/**
 * @brief set the state of the central points
 * 
 * @param state the state we want to set, 0 off, 1 ON
 * @param led the device needed by the LED driver
 */
void setStateCentralPoint(const struct device *const led, uint32_t state);

/**
 * @brief set the state of the Degree Point
 * 
 * @param state the state we want to set, 0 off, 1 ON
 * @param led the device needed by the LED driver
 */
void setDegreePointState(const struct device *const led, uint32_t state);

#endif