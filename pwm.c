/*
 * pwm.c
 *
 * Created: 31/10/2014
 *  Author:Damien
 */
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/cpufunc.h>
#include "include/globaletypedef.h"
#include "include/PeriphMaster.h"
#include "include/pwm.h"

static uint PowerledR,PowerledV,PowerledB;

void pwm_init()
{
    //disable interruption


    //TCCR1A : COM1A1 COM1A0 COM1B1 COM1B0 COM1C1 COM1C0 WGM11 WGM10
    TCCR1A  = 0b0000011;   //fast pwm 10 bits
    //TCCR1B : ICNC1 ICES1 – WGM13 WGM12 CS12 CS11 CS10
    TCCR1B  = 0b0001010; //presaler clk/64 mode fast pwm
    OCR1A   = 0x0000;    //12%
    OCR1B   = 0x0000;
    OCR1C   = 0x0000;
    //TIMSK : OCIE2 TOIE2 TICIE1 OCIE1A OCIE1B TOIE1 OCIE0 TOIE0
    TIMSK   = 0b00011100; // validation interruption sur comparateur A et B et overflow
    //ETIMSK : – – TICIE3 OCIE3A OCIE3B TOIE3 OCIE3C OCIE1C
    ETIMSK  = 0b00000001; //validation interruption sur comparateur C
	//jetonPwm = 1; //jeton pris par defaut


}

ISR(TIMER1_COMPC_vect,ISR_NAKED)
{
__asm__("cbi 0x1b,0" );

reti();
}

ISR(TIMER1_COMPB_vect,ISR_NAKED)
{
 __asm__("cbi	0x1b,2" );

reti();
}

ISR(TIMER1_COMPA_vect,ISR_NAKED)
{
__asm__("cbi	0x1b,1" );

reti();
}

ISR(TIMER1_OVF_vect) 
{
//l'ajout des instruction retarde l'allumage des leds et permet de masquer la latence à vérifier
OCR1A   = PowerledR; //mise à jour systématique
OCR1B   = PowerledV;
OCR1C   = PowerledB;
if (systeme_data.led.R!=0)
PERIPH_LED_PORT|= _BV(PERIPH_RED_PIN);
if (systeme_data.led.V!=0)
PERIPH_LED_PORT|= _BV(PERIPH_GREEN_PIN);
if (systeme_data.led.B!=0)
PERIPH_LED_PORT|= _BV(PERIPH_BLUE_PIN);

}
// calcul la valeur à donneé a la pwm
uint set_color(uint R,uint G,uint B,uint Alpha)
{
	
	PowerledR = R*Alpha/64;//todo corriger le type de R en uint
	PowerledV = G*Alpha/64;
	PowerledB = B*Alpha/64;
	

uint erreur = 0;
return erreur;
}

void set_color_s(led_power lp)
{
	set_color(lp.R,lp.G,lp.B,Lp.A);
}

