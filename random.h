#ifndef __RANDOM_H__
#define __RANDOM_H__

/* Tire al�atoirement une valeur enti�re entre a et b (b non compris)
    Param�tres:
        a - Valeur min
        b - Valeur max
    Retour:
        Valeur tir�e
*/
int random_int(int a, int b);

/* Tire al�atoirement une valeur flottant entre 0.0 et 1.0
    Retour:
        Valeur tir�e
*/
float random_float();

/* Tire al�atoirement une chaine de size caract�res (attention  au caract�res de fin de chaine)
    Param�tres:
        p_string - pointeur sur la chaine de caract�res (la taille doit �tre au moins de size+1)
        size - Longeur de la chaine de caract�res
*/
void random_string(char * p_string, int size);

#endif // __RANDOM_H__
