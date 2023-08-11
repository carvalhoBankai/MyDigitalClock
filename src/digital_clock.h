/**
 * @file digital_clock.h
 * @author Dario Carvalho (dariocarvalho2019@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-07-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _DIGITAL_CLOCK_H
#define _DIGITAL_CLOCK_H

#include <zephyr/drivers/led.h>
#include <zephyr/devicetree.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include "MyDisplay.h"


struct time
{
    uint32_t hour;
    uint32_t minute;
};


/**
 * @brief Initialises the clock
 * 
 * @return true if all ressources where allocated correctly
 * @return false if it was possible to allocate all ressources
 */
bool digitalClockInit(); 

/**
 * @brief Set the Hour
 * 
 * @param hour the hour to set.
 */
void setHour(uint32_t hour);

/**
 * @brief Set the Minutes
 * 
 * @param minute the minutes we want to set
 */
void setMinutes(uint32_t minute);


/**
 * @brief Set an alarm
 *
 * @param time the alarm time
 */
void setAlarm(struct time time);

#endif