#ifndef CONTENT_H_INCLUDED
#define CONTENT_H_INCLUDED


//Définition de notre contenu
typedef struct {
    int val;
} content;


/*  Fonction d'allocation de notre contenu
    Paramètres:
        val - Valeur de notre int
    Retour:
        Pointeur sur notre contenu alloué (NULL si erreur)
*/
content * content_alloc(int val);

/*  Fonction d'allocation de notre contenu, initialisé aléatoirement
    Retour:
        Pointeur sur notre contenu alloué (NULL si erreur)
*/
content * content_random_alloc();

/*  Libération de notre contenu
    Paramètres:
        pc - Pointeur sur le contenu à libérer
*/
void content_free(content *pc);

/*  Affiche de notre contenu
    Paramètres:
        pc - Pointeur sur le contenu à afficher
*/
void content_print(content *pc);

/*  Comparaisons de deux contenus
    Paramètres:
        pc1 - Pointeur sur le premier contenu
        pc2 - Pointeur sur le deuxième contenu
    Retour:
        -1 si pc1 < pc2
        +1 si pc1 > pc2
         0 si pc1 = pc2
*/
int content_comp(content *pc1, content* pc2);

#endif
