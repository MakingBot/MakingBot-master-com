#ifndef poppy_com_H_
#define poppy_com_H_

typedef enum {
    TX,
    RX,
    RXGC
}msg_dir_t;

typedef struct {
    // Message register
    unsigned char reg;
    // Message size
    unsigned char size;
    // Data
    unsigned char data[512];
}msg_t;

typedef void (*RX_CB) (msg_dir_t dir, msg_t *msg);
typedef void (*TX_CB) (msg_t *msg);

void poppyNetwork_init(TX_CB tx_cb,
                       RX_CB rx_cb,
                       RX_CB rxgc_cb);
unsigned char poppyNetwork_read(unsigned char addr, msg_t *msg);
unsigned char poppyNetwork_write(unsigned char addr, msg_t *msg);

/*
 **TODO**
 *
 *Les trucs relatif au boot doivent �tre vir�, cette lib doit �ttre utilis� tant du cot� bootloader qu'utilisateur...
 *
 *Evaluer l'impact m�moire de la lib et limiter au maximum les structures de donn�e lourde en interne, les d�porter au niveau utilisateur.
 *
 *Faire la doc en commentaire
 *
 *Monter clk
 *
 *Regarder comment fonctionne les lib arduino (ajout des trucs dans l'init gestion de clk et autre
 *
 *G�rer le checksum
*/

#endif /* poppy_com_H_ */
