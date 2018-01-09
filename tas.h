#ifndef TAS_H_INCLUDED
#define TAS_H_INCLUDED

typedef struct s_tas{
    void ** contents;
    int nb_layers;
} tas;


/* Alloue un tas
    Param�tres:
        nb_layers - nombre de couche dans le tas
    Retour:
        pointeur sur le tas alouer
*/
tas * tas_alloc(int nb_layers);

/* Lib�re un tas
    Param�tres:
        t - pointeur sur le tas alouer
        free_content - pointeur sur la fonction de liberation des �l�ments du tas
*/
void tas_free(tas * t, void (*free_content)(void *));

/* Retourne la capacit� du tas
    Param�tres:
        t - pointeur sur le tas alouer
    Retour:
        capacit� du tas (-1 si erreur)
*/
int tas_get_capacity(tas * t);

/* Retourne si le noeud est vide
    Param�tres:
        t - pointeur sur le tas alouer
        id - index du noeud
    Retour:
        0 si non vide, autre chose si non.
*/
int tas_node_is_empty(tas * t, int id);

/* Retourne le contenu d'un noeud
    Param�tres:
        t - pointeur sur le tas alouer
        id - index du noeud
    Retour:
        pointeur sur le contenu
*/
void * tas_get_content(tas * t, int id);

/* Affecte un contenu � un noeud
    Param�tres:
        t - pointeur sur le tas alouer
        id - index du noeud
        content - pointeur sur le contenu
*/
void tas_set_content(tas * t, int id, void * content);

/* Affiche le tas
    Param�tres:
        t - pointeur sur le tas alouer
        print_content - pointeur sur la fonction d'affichage des contenu
*/
void tas_print(tas * t, void (*print_content)(void *));


/* Retourne index du fils de gauche d'un noeud
    Param�tres:
        id - index du noeud
    Retour:
        index du fils de gauche
*/
int tas_get_left_child(int id);

/* Retourne index du fils de droite d'un noeud
    Param�tres:
        id - index du noeud
    Retour:
        index du fils de droite
*/
int tas_get_right_child(int id);

/* Retourne index du pere d'un noeud
    Param�tres:
        id - index du noeud
    Retour:
        index du pere
*/
int tas_get_father(int id);


#endif // TAS_H_INCLUDED
