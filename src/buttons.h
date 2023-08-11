#ifndef _BUTTONS_H
#define _BUTTONS_H
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/util.h>
#include <zephyr/sys/printk.h>
#include <inttypes.h>
#include <stdint.h>


void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
#endif