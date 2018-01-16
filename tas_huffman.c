#include "tas_huffman.h"
#include "tas.h"


tas_huffman * tas_huffman_alloc(int nb_layers){
	tas_huffman * mon_tas_huffman = (tas_huffman *) malloc(sizeof(mon_tas_huffman));
	mon_tas_huffman->tas = tas_alloc(nb_layers);
	return mon_tas_huffman;
}


void tas_huffman_free(tas_huffman * mon_tas_huffman, void (*free_content)(void *)){
    if(mon_tas_huffman){
        if(mon_tas_huffman->tas){
            tas_free(mon_tas_huffman->tas, free_content);
        }
        free(mon_tas_huffman);
    }
}

int tas_huffman_get_min_node(tas_huffman * mon_tas_huffman, int (*cmp_content)(void *,void *)){
    int i;
    void * i_content;

    int i_min = 0;
    void * i_min_content = tas_get_content(mon_tas_huffman->tas, i_min);

    for(i=1; i <tas_get_capacity(mon_tas_huffman->tas); i++){
        //TODO : Vérifier le le noeud ne soit pas une feuille.
        i_content = tas_get_content(mon_tas_huffman->tas, i);
        if(cmp_content(i_min_content, i_content) > 0){
            i_min = i;
            i_min_content = i_content;
        }
    }

    return i_min;

}



tas_huffman * create_tas_huffman(void ** tab, int TAILLE){
    for(int i = 0; i<TAILLE; i++){
        //content_print(tab+i);
    }
    return NULL;
}
