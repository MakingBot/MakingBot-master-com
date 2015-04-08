#ifndef POPPY_COM_H_
#define POPPY_COM_H_

#include <avr/io.h>

#define MAINCLOCK 8000000

void poppyNetwork_init(void (*tx_cb)(volatile uint8_t *data),
                       void (*rx_cb)(volatile uint8_t data),
                       void (*rxgc_cb)(volatile uint8_t data));
uint8_t poppyNetwork_Read(uint8_t addr,
                          uint8_t *data,
                          uint8_t size);
uint8_t poppyNetwork_Write(uint8_t addr,
                           uint8_t *data,
                           uint8_t size);

/*
 **TODO**
 *
 *Dans le mode slave il doit y avoir un certain nombre de message qui seront r�serv� a l'utilisation
 *du protocole en lui m�me. C'est requettes la devrons �tre filtr� pour �tre soit g�r� par le driver
 *lui m�me soit redirig� vers une CB sp�cifique.
 *La liste est a d�finir
 *
 *Les trucs relatif au boot doivent �tre virer, cette lib doit �ttre utilis� tant du cot� bootloader qu'utilisateur...
 *
 *Evaluer l'impact m�moire de la lib et limiter au maximum les structures de donn�e lourde en interne, les d�porter au niveau utilisateur.
 *
 *Rendre ce code compilable et flashable sur linux (faire un makefile propre)
 *
 *CODING STANDARDS (cpplint)
 *
 *Choir un compilo de doc (a priori Doxygen)
 *
 *Faire la doc en commentaire
 *
 *Tester le Read
 *
 *Tester le GC
 *
 *Monter clk
 *
 *Regarder comment fonctionne les lib arduino (ajout des trucs dans l'init gestion de clk et autre
 *
 *gitter tous �a!
*/

#endif /* POPPY_COM_H_ */
