/**
 *  \file HAL.h
 *  \brief fichier d'entête de la couche d'abstraction matériel
 */
#ifndef HAL_H
#define HAL_H
#include "globaletypedef.h"
#define READ false
#define WRITE true
// definition of datatype length
#define PINGLENGHT 0
#define GPIOBITLENGTH 2
#define GPIOPORTLENGTH 2
#define CURRENTCHANNELLENGTH 2
//macros

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
typedef enum
{
    PINGI2C = MINAPPCMD,  
    GPIOBIT = MINAPPCMD + 1,
    GPIOPORT= MINAPPCMD + 2,
    CURRENTCHANNEL = MINAPPCMD + 3
} AppReg_t;






/**
 *  \brief Brief
 *
 *  \param [in] port port to change
 *  \param [in] bit bit in port to change
 *  \return nothing
 *
 *  \details Details
 */void setGpioBit(const uchar numgpio,eBool val);


#endif //a bouger en fin de fichier
