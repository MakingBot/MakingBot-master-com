/**
 *  \file HAL.c
 *  \brief implémantation de la couche d'abstraction matérielle
 *  \details This file include all driver header or wrapper but not hardware file
 */
#include <stdlib.h>
#include <string.h>
#include "include/globaletypedef.h"
#include "include/PeriphMaster.h"
#include "include/HAL.h"
#include "include/init.h"
#include "include/isr.h" //driver of interruption
#include "include/pwm.h"
#include "include/utility.h" //wrapper
#include "poppy-com/poppyNetwork.h"



















/**
 *  \brief Brief
 *
 *  \param [in] port port to change
 *  \param [in] bit bit in port to change
 *  \return nothing
 *
 *  \details Details
 */void setGpioBit(const uchar numgpio,eBool val)
 {
   switch(numgpio)
	 {
	 case 0 :
	 GPIO(0,val); //c'est une macro
	 break;
	 case 1 :
	 GPIO(1,val); //c'est une macro le premier caractére est substituer et ne peut donc par etre variable
	 break;
	 case 2 :
	 GPIO(2,val); //c'est une macro
	 break;
	 default:
	 break;
	 }
	/*if (val==true)
	setGPIO(numgpio);
	else
	resetGPIO(numgpio);*/


 }
