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
    Retour:
*/
tas_huffman * create_tas_huffman(void ** tab);

/*
    Param�tres:
        tas_huffman - le tas huffman
        cmp_content - la fonction de comparaison
    Retour:
        -1 si n'existe pas
        sinon l'index du noeud comportant la valeur minimun
*/
int tas_huffman_get_min_node(tas_huffman * tas_huffman, int (*cmp_content)(void *,void *))

/* Cr�er un tas huffman
    Param�tres:
        tas_huffman - le tas ou l'on doit ajouter un layer et 2 content a la base.
        content1 - la premi�re valeur a ajouter au noeud de droite de l'arbre
        content2 - la seconde valeur � ajouter au noeud de droite de l'arbre
    Retour:
        Le tas avec un layer et deux valeur en plus.
*/
tas_huffman * tas_huffman_add_one_layer(tas_huffman * tas_huffman, void * content1, void * content2);

#endif // __TAS_HUFFMAN_H__
