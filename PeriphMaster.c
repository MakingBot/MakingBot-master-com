/**
 *  \file PeriphMaster.c
 *  \brief application carteperiph
 *  \details this file is the main application it don't must any reference to any hardware
 */

/**
 * This is the minimal include you will need to use poppy-com in a module
 * application
 */
#include "poppy-com/poppyNetwork.h"
#include "include/protocol.h"
#include "include/HAL.h" // Hardware abstraction layer
#include "include/globaletypedef.h"
#include "include/PeriphMaster.h"
#include "include/utility.h"
#include "include/init.h"
#include "include/pwm.h"
#include "include/isr.h" //driver of interruption



extern struct data system_data;


/**
 *  \brief main
 *
 *  \return none
 *
 *  \details Details
 */int main(void)
{

    cli();
    init();
    pwm_init();
    isr_init();

    system_data.led.A=0xff;

    sei();
    poppyNetwork_init(tx_cb, rx_cb, rxgc_cb);
    while(1)
    {




        set_color_s(system_data.led);




    }
}
