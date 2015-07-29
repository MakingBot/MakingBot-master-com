/**
 *  \file PeriphMaster.h
 *  \brief header must be updated for remove hardware ref
 */
 #ifndef PERIPHMASTER_H_INCLUDED
#define PERIPHMASTER_H_INCLUDED
#include <avr/io.h>
#include "include/globaletypedef.h"
#include "include/pwm.h"

//#define F_CPU 1000000UL // 1 MHz
#define CYAN		0x45	// 0b01000010
#define JAUNE        0x46
#define WHITE       0x47
#define RED	    0x42
#define GREEN   0x44
#define BLUE    0x41


#define PERIPH_LED_PORT             PORTA
#define PERIPH_LED_DDR              DDRA
#define PERIPH_RED_PIN              PORT1
#define PERIPH_GREEN_PIN            PORT2
#define PERIPH_BLUE_PIN             PORT0

#define PERIPH_POWERUP_DDR			DDRA
#define PERIPH_POWERUP_PORT			PORTA
#define PERIPH_POWERUP_PIN			PORTA6

#define BUTTON_PUSH_DDR					DDRE
#define BUTTON_PUSH_PORT				PINE
#define BUTTON_PUSH_PIN					PIN4
#define ADRESSE							0x48

#define GPIO0_PORT                  PORTC
#define GPIO1_PORT                  PORTC
#define GPIO2_PORT                  PORTC
//portc
#define GPIO0BIT                    PORT0
#define GPIO1BIT                    PORT1
#define GPIO2BIT                    PORT2
#define GPIO3BIT                    PORT3
#define GPIO4BIT                    PORT4
//portF
#define GPIO5BIT                    PORT0
#define GPIO6BIT                    PORT1
#define GPIO7BIT                    PORT2
#define GPIO8BIT                    PORT3
#define GPIO9BIT                    PORT4
//PORTE
#define GPIO10BIT                    PORT3
#define GPIO11BIT                    PORT2
#define GPIO12BIT                    PORT5
#define GPIO13BIT                    PORT6
//PORTB
#define GPIO14BIT                    PORT0
//portD
#define GPIO15BIT                    PORT0
#define GPIO16BIT                    PORT1
#define GPIO17BIT                    PORT2
#define GPIO18BIT                    PORT3
#define GPIO19BIT                    PORT4

//portc
#define GPIO0_PORT                    PORTC
#define GPIO1_PORT                    PORTC
#define GPIO2_PORT                    PORTC
#define GPIO3_PORT                    PORTC
#define GPIO4_PORT                    PORTC
//portF
#define GPIO5_PORT                    PORTF
#define GPIO6_PORT                    PORTF
#define GPIO7_PORT                    PORTF
#define GPIO8_PORT                    PORTF
#define GPIO9_PORT                    PORTF
//PORTE
#define GPIO10_PORT                    PORTE
#define GPIO11_PORT                    PORTE
#define GPIO12_PORT                    PORTE
#define GPIO13_PORT                    PORTE
//PORTB
#define GPIO14_PORT                    PORTB
//portD
#define GPIO15_PORT                    PORTD
#define GPIO16_PORT                    PORTD
#define GPIO17_PORT                    PORTD
#define GPIO18_PORT                    PORTD
#define GPIO19_PORT                    PORTD
//portc
#define GPIO0_DDR                    DDRC
#define GPIO1_DDR                    DDRC
#define GPIO2_DDR                    DDRC
#define GPIO3_DDR                    DDRC
#define GPIO4_DDR                    DDRC
//DDRF
#define GPIO5_DDR                    DDRF
#define GPIO6_DDR                    DDRF
#define GPIO7_DDR                    DDRF
#define GPIO8_DDR                    DDRF
#define GPIO9_DDR                    DDRF
//DDRE
#define GPIO10_DDR                    DDRE
#define GPIO11_DDR                    DDRE
#define GPIO12_DDR                    DDRE
#define GPIO13_DDR                    DDRE
//DDRB
#define GPIO14_DDR                    DDRB
//DDRD
#define GPIO15_DDR                    DDRD
#define GPIO16_DDR                    DDRD
#define GPIO17_DDR                    DDRD
#define GPIO18_DDR                    DDRD
#define GPIO19_DDR                    DDRD
struct data
 {
	eBool periphstate[20];  //�tat des p�riph�riques true allum� false �teint
	uchar periphcurrent[20]; //valeur de courant des p�riph�rique
	eBool power; //�tat du syst�me true allum� false �teint
	led_power led;

 }system_data;


#endif // MAIN_H_INCLUDED
