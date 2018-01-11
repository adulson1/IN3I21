#ifndef __TAS_HUFFMAN_H__
#define __TAS_HUFFMAN_H__
#include "tas.h"

typedef struct {
    tas * tas;
} tas_huffman;

/* Alloue un tas huffman
    Param�tres:
        nb_layers - nombre de couche dans le tas
    Retour:
        pointeur sur le tas alouer
*/
tas_huffman * tas_huffman_alloc(int nb_layers);


/* Lib�re un tas huffman
    Param�tres:
        t - pointeur sur le tas alouer
        free_content - pointeur sur la fonction de liberation des �l�ments du tas
*/
void tas_huffman_free(tas_huffman * t, void (*free_content)(void *));



/* Cr�er un tas huffman
    Param�tres:
        tab - pointeur sur un tableau de pointeurs de valeurs tri�es dans l'ordre croissant
*/
tas_huffman * create_tas_huffman(void ** tab);

#endif // __TAS_HUFFMAN_H__
