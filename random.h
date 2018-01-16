#ifndef __RANDOM_H__
#define __RANDOM_H__

/* Tire aléatoirement une valeur entière entre a et b (b non compris)
    Paramètres:
        a - Valeur min
        b - Valeur max
    Retour:
        Valeur tirée
*/
int random_int(int a, int b);

/* Tire aléatoirement une valeur flottant entre 0.0 et 1.0
    Retour:
        Valeur tirée
*/
float random_float();

/* Tire aléatoirement une chaine de size caractères (attention  au caractères de fin de chaine)
    Paramètres:
        p_string - pointeur sur la chaine de caractères (la taille doit être au moins de size+1)
        size - Longeur de la chaine de caractères
*/
void random_string(char * p_string, int size);

#endif // __RANDOM_H__
