#ifndef CONTENT_H_INCLUDED
#define CONTENT_H_INCLUDED


//D�finition de notre contenu
typedef struct {
    int val;
} content;


/*  Fonction d'allocation de notre contenu
    Param�tres:
        val - Valeur de notre int
    Retour:
        Pointeur sur notre contenu allou� (NULL si erreur)
*/
content * content_alloc(int val);

/*  Fonction d'allocation de notre contenu, initialis� al�atoirement
    Retour:
        Pointeur sur notre contenu allou� (NULL si erreur)
*/
content * content_random_alloc();

/*  Lib�ration de notre contenu
    Param�tres:
        pc - Pointeur sur le contenu � lib�rer
*/
void content_free(content *pc);

/*  Affiche de notre contenu
    Param�tres:
        pc - Pointeur sur le contenu � afficher
*/
void content_print(content *pc);

/*  Comparaisons de deux contenus
    Param�tres:
        pc1 - Pointeur sur le premier contenu
        pc2 - Pointeur sur le deuxi�me contenu
    Retour:
        -1 si pc1 < pc2
        +1 si pc1 > pc2
         0 si pc1 = pc2
*/
int content_comp(content *pc1, content* pc2);

#endif
