#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "tas.h"

int get_capacity(int nb_layers){
    if(nb_layers > 0)
        return pow(2, nb_layers)-1;
    return -1;
}

tas * tas_alloc(int nb_layers){
    int i;
    tas * t = NULL;
    if(nb_layers > 0){
        t = (tas *) malloc(sizeof(tas));
        if(t){
            t->nb_layers = nb_layers;
            t->contents = (void **) malloc(sizeof(void*)*get_capacity(nb_layers));
            if(t->contents){
                for(i=0 ; i<get_capacity(nb_layers) ; i++)
                    t->contents[i] = NULL;
            }
            else{
                free(t);
                t = NULL;
            }
        }
    }
    return t;
}

void tas_free(tas *t, void (*free_content)(void *)){
    int i;
    if(t){
        if(t->contents){
            if(free_content)
                for(i=0 ; i<get_capacity(t->nb_layers) ; i++){
                    if(t->contents[i]){
                        free_content(t->contents[i]);
                        t->contents[i] = NULL;
                    }
                }
            free(t->contents);
        }
        free(t);
    }
}

int tas_get_capacity(tas * t){
    if(t){
        return get_capacity(t->nb_layers);
    }
    return -1;
}

int tas_node_is_empty(tas * t, int id){
    if(t && id < get_capacity(t->nb_layers)){
        return t->contents[id] == NULL;
    }
    return -1;
}

void * tas_get_content(tas * t, int id){
    if(t && id < get_capacity(t->nb_layers)){
        return t->contents[id];
    }
    return NULL;
}

void tas_set_content(tas * t, int id, void * content){
    if(t && id < get_capacity(t->nb_layers)){
        t->contents[id] = content;
    }
}

int tas_get_first_node_id_of_layer(int layer){
    int id = 0;
    int i;
    if(layer < 0){
        return -1;
    }
    for(i=0 ; i<layer ; i++){
        id = id * 2 + 1;
    }
    return id;
}

int tas_get_nb_node_in_layer(int layer){
    if(layer < 0){
        return -1;
    }
    return pow(2, layer);
}

void tas_print(tas * t, void (*print_content)(void *)){
    int layer;
    int i;
    if(t){
        for(layer = 0 ; layer < t->nb_layers ; layer++){
            printf("LAYER - %d\n", layer);
            for(i = 0 ; i < tas_get_nb_node_in_layer(layer) ; i++){
                int id = tas_get_first_node_id_of_layer(layer) + i;
                printf("\t%d - ", id);
                if(t->contents[id]){
                    if(print_content)
                        print_content(t->contents[id]);
                    else
                        printf("%p", t->contents[id]);
                    printf("\n");
                }
                else
                    printf("NULL\n");

            }
        }
    }
}

int tas_get_left_child(int id){
    return id*2 + 1;
}

int tas_get_right_child(int id){
    return id*2 + 2;
}

int tas_get_father(int id){
    int id_father = -1;
    if(id > 0){
        if(id%2 == 0)
            id_father = (id - 2)/2;
        else
            id_father = (id - 1)/2;
    }
    return id_father;
}
