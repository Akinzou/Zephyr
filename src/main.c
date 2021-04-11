#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>
#include <sys/printk.h>

#define LED0_NODE   DT_ALIAS(led0)
#define LED0	    DT_GPIO_LABEL(LED0_NODE, gpios)
#define LED_PIN	        DT_GPIO_PIN(LED0_NODE, gpios)
#define FLAGS	    DT_GPIO_FLAGS(LED0_NODE, gpios)


#define SW0_NODE    DT_ALIAS(sw0)
#define SW0	DT_     GPIO_LABEL(SW0_NODE, gpios)
#define SW0_PIN	    DT_GPIO_PIN(SW0_NODE, gpios)
#define SW0_FLAGS	DT_GPIO_FLAGS(SW0_NODE, gpios)

void main(void)
{
    const struct device *gpio_i = device_get_binding(LED0);
    gpio_pin_configure(gpio_i, LED_PIN, GPIO_OUTPUT);
    gpio_pin_configure(gpio_i, SW0_PIN, GPIO_INPUT);
    while (1)
    {
        gpio_pin_toggle(gpio_i, LED_PIN);
        printk("Hello World!\n");
        if(gpio_pin_get(gpio_i, SW0_PIN))
        {
            printk("Button pressed\n");
        }
        k_msleep(500);
    }
}
