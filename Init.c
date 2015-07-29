#include <stdint.h>
#include <avr/io.h>
#include "include/init.h"
#include "include/PeriphMaster.h"
#include "include/globaletypedef.h"


void periph_power_on(void)
{
    PERIPH_POWERUP_PORT |= (1<<PERIPH_POWERUP_PIN);
    system_data.power=true;
}

void init(void)
{
    PERIPH_POWERUP_DDR |= (1<<PERIPH_POWERUP_PIN);	// Powerup pin as output
    periph_power_on();

    BUTTON_PUSH_DDR &= ~(1<<BUTTON_PUSH_PIN);		// Button pin as input

    PERIPH_LED_DDR |= (1<<PERIPH_BLUE_PIN) |(1<<PERIPH_GREEN_PIN) |(1<<PERIPH_RED_PIN);
    	// LED Output
    PERIPH_LED_PORT|= RED;

    GPIO0_DDR |=(1<<GPIO0BIT);
    GPIO1_DDR |=(1<<GPIO1BIT);
    GPIO2_DDR |=(1<<GPIO2BIT);
    GPIO3_DDR |=(1<<GPIO3BIT);
    GPIO4_DDR |=(1<<GPIO4BIT);
    GPIO5_DDR |=(1<<GPIO5BIT);
    GPIO6_DDR |=(1<<GPIO6BIT);
    GPIO7_DDR |=(1<<GPIO7BIT);
    GPIO8_DDR |=(1<<GPIO8BIT);
    //GPIO9_DDR |=(1<<GPIO9BIT);  //TCK
    GPIO10_DDR |=(1<<GPIO10BIT);
    GPIO11_DDR |=(1<<GPIO11BIT);
    GPIO12_DDR |=(1<<GPIO12BIT);
    GPIO13_DDR |=(1<<GPIO13BIT);
    GPIO14_DDR |=(1<<GPIO14BIT);
    //GPIO15_DDR |=(1<<GPIO15BIT); //I2C
    //GPIO16_DDR |=(1<<GPIO16BIT); //I2C
    GPIO17_DDR |=(1<<GPIO17BIT);
    GPIO18_DDR |=(1<<GPIO18BIT);
    GPIO19_DDR |=(1<<GPIO19BIT);

}
