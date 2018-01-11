#ifndef __TAS_HUFFMAN_H__
#define __TAS_HUFFMAN_H__
#include "tas.h"

typedef struct {
    tas * tas;
} tas_huffman;

/* Alloue un tas huffman
    Paramètres:
        nb_layers - nombre de couche dans le tas
    Retour:
        pointeur sur le tas alouer
*/
tas_huffman * tas_huffman_alloc(int nb_layers);


/* Libére un tas huffman
    Paramètres:
        t - pointeur sur le tas alouer
        free_content - pointeur sur la fonction de liberation des éléments du tas
*/
void tas_huffman_free(tas_huffman * t, void (*free_content)(void *));



/* Créer un tas huffman
    Paramètres:
        tab - pointeur sur un tableau de pointeurs de valeurs triées dans l'ordre croissant
*/
tas_huffman * create_tas_huffman(void ** tab);

#endif // __TAS_HUFFMAN_H__
