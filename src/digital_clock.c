#include "digital_clock.h"
#include "buttons.h"

#define LED_NODE     DT_COMPAT_GET_ANY_STATUS_OKAY(holtek_ht16k33)
#define DISPLAY_SIZE 4;

/* global variables */

/*CONTROLERS*/
const struct device *display  = DEVICE_DT_GET(LED_NODE);
static const struct gpio_dt_spec incrementbutton = GPIO_DT_SPEC_GET(DT_NODELABEL(incrementbutton), gpios);

static struct gpio_callback button_cb_data;

/* variables to send to display modules*/
uint32_t minutes = 55;
uint32_t hour = 0;

void setMinutes(uint32_t minute)
{
	minutes++;
	printk("incrementbutton pressed at %d \n", minutes);
}





void setHour(uint32_t hour)
{
}

bool digitalClockInit()
{
	
	/*display initialisation*/
	if (!device_is_ready(display)) 
    {
		return false;
	}

	/*increment*/

	if (!device_is_ready(incrementbutton.port)) {
		return false;
	}

	int ret = gpio_pin_configure_dt(&incrementbutton, GPIO_INPUT);

	if (ret != 0) {
		return false;
	}


	ret = gpio_pin_interrupt_configure_dt(&incrementbutton, GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		return false;
	}

	gpio_init_callback(&button_cb_data, setMinutes, BIT(incrementbutton.pin));
	gpio_add_callback(incrementbutton.port, &button_cb_data);

	/*Initial animation*/

	for (int k = 0; k < 4; k++)
    {
		displayString("INIT", display);
		k_msleep(100);
		displayString("YYYY", display);
		k_msleep(100);
	}

	displayNum(0, display);
	setStateCentralPoint(display, ON);
	return true;
}