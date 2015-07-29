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
 */int main()
{

   cli();
     init();
     pwm_init();
     isr_init();
     #ifdef __DEBUG__
    set_color(0,0,255,255); //a priori 25ms d'execution
    #endif // __DEBUG__
system_data.led.A=0xff;
    // launchCom();
   sei();
    poppyNetwork_init(tx_cb, rx_cb, rxgc_cb);
   while(1)
   {


  #ifdef __DEBUG__
   // set_color(0,0,255,255); //a priori 25ms d'execution
    #endif // __DEBUG__

set_color_s(system_data.led);

  #ifdef __DEBUG__
    //set_color(255,0,0,255); //a priori 25ms d'execution
    #endif // __DEBUG__



   }
}
