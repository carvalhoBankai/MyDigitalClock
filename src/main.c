
#include "digital_clock.h"
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/util.h>
#include <zephyr/sys/printk.h>
#include <inttypes.h>

// #define LED_NODE DT_COMPAT_GET_ANY_STATUS_OKAY(holtek_ht16k33)

void printText(const char *textToPrint, const struct device *const led)
{

	int j = 0;
	char textSlice[4] = {"YYYY"};
	while (textToPrint[j] != '\0') {

		displayString(textSlice, led);

		for (int k = 0; k < 3; k++) {
			textSlice[k] = textSlice[k + 1];
		}
		textSlice[3] = textToPrint[j];
		k_msleep(1000);
		j++;
	}
}



void main(void)
{

	/* code */
	// if (!device_is_ready(led)) {
	//  LOG_ERR("LED device not ready");
	//	return;
	//}

	// displayString("12C",led);
	// int b = displaySingleNumber(3,0,led);

	//char tab [] = {"DADIVAYYYYDINISYYYY"};

	// setDegreePointState(led,ON);

	// Init clock
	digitalClockInit();

	

	
}