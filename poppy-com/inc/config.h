/*
 * This file contain default configuration of the project.
 */

#include "mod_list.h"

#define DEFAULTID 0x01

#define ADDRESS 0x48

#ifndef MODULETYPE
    #define MODULETYPE DEV_BOARD
#endif

//#ifndef MCU
    #define MCU atmega64
//#endif

#ifndef MAINCLOCK
    #define MAINCLOCK 8000000
#endif

#ifndef SCLFREQ
    #define SCLFREQ 400000
#endif

#ifndef MAX_TRIES
    #define MAX_TRIES 5
#endif



    #define HAL "../atmega64/hal.h"

