#include <zephyr.h>
#include <device.h>
#include <drivers/gpio.h>
/* 1000 msec = 1 sec */

const s32_t SLEEP_TIME = 1000;

void main(void)
{
	u32_t cnt = 0;
	struct device *dev;
	dev = device_get_binding("GPIOI");
	/* Set LED pin as output */
	gpio_pin_configure(dev, 1, GPIO_DIR_OUT);
	while (1) 
	{
		/* Set pin to HIGH/LOW every 1 second */
		gpio_pin_write(dev, 1, cnt % 2);
		cnt++;

		k_msleep(SLEEP_TIME);
	}
}



