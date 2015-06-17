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
#include <stdint.h>
#include "include/HAL.h" // Hardware abstraction layer
#include "include/globaletypedef.h"
#include "include/PeriphMaster.h"
#include "include/utility.h"
#include "include/init.h"
#include "include/pwm.h"
#include "include/isr.h" //driver of interruption
#include "include/protocole.h"


extern struct data system_data;

/**
 * \fn void rx_cb(msg_dir_t dir, msg_t *msg)
 * \brief Callback function for Slave mode messages reception.
 *
 * \param dir Message direction. (That will be remove!)
 * \param msg Received message.
 */
void rx_cb(msg_dir_t dir, msg_t *msg) {
    /*
     * Add your RX code here.
     */
    switch (msg->reg)
    {
    case LED_COLOR :
        system_data.led.R = msg->data[0];
        system_data.led.G = msg->data[1];
        system_data.led.B = msg->data[2];
        system_data.led.A = msg->data[3];
        break;
    default:
        break;

    }


}

/**
 * \fn void rxgc_cb(msg_dir_t dir, msg_t *msg)
 * \brief Callback function for Slave mode messages reception with general call.
 * \brief Callback function for Slave mode messages reception with general call.
 *
 * \param dir Message direction. (That will be remove!)
 * \param msg Received message.
 */
void rxgc_cb(msg_dir_t dir, msg_t *msg) {
    /*
     * Add your RX general call code here.
     */
    /*
     * Add your RX general call code here.
     */

}

/**
 * \fn void tx_cb(msg_t *msg)
 * \brief Callback function for Slave mode messages transmission.
 *
 * \param msg Transmitted message. You have to put something in this msg_t.
 */
void tx_cb(msg_t *msg) {
    msg->reg=0b00001111;
    msg->size =0x8;
    msg->data[0]= 0x55;
    msg->data[7]= 0xAA;
      set_color(0,255,0,255);
}
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
