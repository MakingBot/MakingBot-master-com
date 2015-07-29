/**
 *  \file HAL.h
 *  \brief fichier d'entête de la couche d'abstraction matériel
 */
#ifndef HAL_H
#define HAL_H
#include "globaletypedef.h"
#define DO_PRAGMA(x) _Pragma (#x)
#define TODO(x) DO_PRAGMA(message ("TODO - " #x))
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)



#define READ false
#define WRITE true
// definition of datatype length
#define PINGLENGHT 0
#define GPIOBITLENGTH 2
#define GPIOPORTLENGTH 2
#define CURRENTCHANNELLENGTH 2
#define MINAPPCMD 10
#define PINGI2C     MINAPPCMD
#define GPIO0_7     MINAPPCMD        + 1
#define GPIO8_15    MINAPPCMD       + 2
#define GPIO16_19   MINAPPCMD   + 3
#define CURRENTCHANNEL  MINAPPCMD + 4
#define LED_COLOR MINAPPCMD     + 5
#define GPIOBIT  MINAPPCMD  + 6 //correspon,d à la GPIO0 les 19 suivante sont utilisé
//reservé
#define GPIOPORT    MINAPPCMD +26
//macros
#pragma message "adresse of MINAPPCMD = " STR(MINAPPCMD)
#pragma message "adresse of PINGI2C = " STR(PINGI2C)
#pragma message "adresse of GPIO0_7 = " STR(GPIO0_7)
#pragma message "adresse of CURRENTCHANNEL = " STR(CURRENTCHANNEL)
#pragma message "adresse of LED_COLOR = " STR(LED_COLOR)
#pragma message "adresse of GPIOBIT = " STR(GPIOBIT)
#pragma message "adresse of GPIOPORT = " STR(GPIOPORT)

 #define GPIO(num,val)\
 if (!val )\
 GPIO ## num ## _PORT &= ~(1<<GPIO ## num ## BIT);\
 else\
 GPIO ## num ## _PORT |=(1<<GPIO ## num ## BIT);
//supression car devenue inutile avec gpio.c
/******************************************
 *  définition des type enuméré
 */

// /brief type de data

//longueur data 0
//longueur data 2 1er octect numéro gpio, 2eme etat gpio type bool
// numéro du port suivi data la dir est fixé dans le code
//voie courant suivie de la valeur
//liste des registre de l'application







/**
 *  \brief Brief
 *
 *  \param [in] port port to change
 *  \param [in] bit bit in port to change
 *  \return nothing
 *
 *  \details Details
 */eBool setGpioBit(const uchar numgpio,eBool val);

 void updateGpio(void);

#endif //a bouger en fin de fichier
