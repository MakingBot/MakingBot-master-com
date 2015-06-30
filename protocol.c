/**
 *  \file protocol.h
 *  \brief traitement des message i2c
 *
 */

#include "poppy-com/poppyNetwork.h"
 #include "include/protocol.h"
 #include "include/HAL.h"
 #include "include/PeriphMaster.h"

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
     uchar gpionum,temp;
    switch (msg->reg)
    {
    case LED_COLOR :
        system_data.led.R = msg->data[0];
        system_data.led.G = msg->data[1];
        system_data.led.B = msg->data[2];
        system_data.led.A = msg->data[3];
        break;
    case PINGI2C :
        msg->size = 1;
        msg->data[0] = ADRESSE;
        break;
    case GPIOBIT :  // num IO // etat
    for (unsigned char i = msg->size;i>0;i--)
        {
        system_data.periphstate[i]=msg->data[i];  // un octoct à 0 ou 1 pour commender la voie correspondante
        }
        break;
    case GPIOPORT:

        gpionum = 0;
        while(msg->size)
        {
            for (unsigned char bit=0; bit<8; bit++)
            {

                system_data.periphstate[gpionum] = bit << msg->data[msg->size];
                setGpioBit(gpionum,system_data.periphstate[gpionum]);
                gpionum++;
            }
            msg->size--;
        }
    case CURRENTCHANNEL :
        break;
    default:
        gpionum = msg->reg;
        temp = GPIOBIT;
        gpionum = gpionum - temp;
        setGpioBit(gpionum,(eBool)msg->data[0]);
        system_data.periphstate[gpionum]=(eBool)msg->data[0];
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
