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
 */eBool setGpioBit(const uchar numgpio,eBool val)
 {
 eBool error = false;
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
	 case 3 :
	 GPIO(3,val); //c'est une macro
	 break;
	 case 4 :
	 GPIO(4,val); //c'est une macro
	 break;
	 case 5 :
	 GPIO(5,val); //c'est une macro
	 break;
	 case 6 :
	 GPIO(6,val); //c'est une macro
	 break;
	 case 7 :
	 GPIO(7,val); //c'est une macro
	 break;
	 case 8 :
	 GPIO(8,val); //c'est une macro
	 break;
	 case 9 :
	 GPIO(9,val); //c'est une macro
	 break;
	 case 10 :
	 GPIO(10,val); //c'est une macro
	 break;
	 case 11 :
	 GPIO(11,val); //c'est une macro le premier caractére est substituer et ne peut donc par etre variable
	 break;
	 case 12 :
	 GPIO(12,val); //c'est une macro
	 break;
	 case 13 :
	 GPIO(13,val); //c'est une macro
	 break;
	 case 14 :
	 GPIO(14,val); //c'est une macro
	 break;
	 case 15 :
	 GPIO(15,val); //c'est une macro
	 break;
	 case 16 :
	 GPIO(16,val); //c'est une macro
	 break;
	 case 17 :
	 GPIO(17,val); //c'est une macro
	 break;
	 case 18 :
	 GPIO(18,val); //c'est une macro
	 break;
	 case 19 :
	 GPIO(9,val); //c'est une macro
	 break;

	 default:
	 error = true;
	 break;
	 }



 }

 void updateGpio(void)
 {
 //TODO (ou pas!) faire une fonction qui lit system_data et qui met à jourles ggio en fonction
 }
