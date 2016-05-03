/*
 * This file contain default configuration of the project.
 */

<<<<<<< HEAD
#include "mod_list.h"
=======
#ifndef CONFIG_H_
#define CONFIG_H_

#include "poppy-com/inc/mod_list.h"
>>>>>>> update

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

<<<<<<< HEAD


    #define HAL "../atmega64/hal.h"

=======
#if MCU == atmega328p
    #define HAL "poppy-com/hal/atmega328p/hal.h"
#elif MCU == stub
    #define HAL "poppy-com/hal/stub/hal.h"
#elif MCU== atmega64
    #define HAL "poppy-com/hal/atmega64/hal.h"
#endif

#endif /* CONFIG_H_ */
>>>>>>> update
