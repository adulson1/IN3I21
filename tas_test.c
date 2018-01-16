#include <stdio.h>
#include <stdlib.h>

#include "tas_test.h"
#include "content.h"
#include "tas.h"
#include "tas_huffman.h"

void tas_huffman_menu(){
    printf("A faire!\n");
}

void tas_menu(){

    tas * my_tas = NULL;
    content * my_content = NULL;
    int index_current = -1;
    int index;

    int choise;

    while(1)
    {
        printf("Menu test tas :\n");
        printf("\t 1) Allouer un tas\n");
        printf("\t 2) Afficher la capacité du tas\n");
        printf("\t 3) Affecter un contenu au noeud courent\n");
        printf("\t 4) Supprimer le contenu du noeud courent\n");
        printf("\t 5) Afficher le contenu du noeud courent\n");
        printf("\t 6) Descendre au fils de gauche du noeud courent\n");
        printf("\t 7) Descendre au fils de droit du noeud courent\n");
        printf("\t 8) Remonter au pere du noeud courent\n");
        printf("\t 9) Afficher le tas\n");
        printf("\t10) Libérer un tas\n");
        printf("\t11) Quitter\n");
        printf("Choix :");
        scanf("%d",&choise);
        switch(choise)
        {
            case 1:
                printf("Allocation d'un tas de 4 couches\n");
                my_tas = tas_alloc(4);
                index_current = 0;
            break;
            case 2:
                printf("La capacité du tas est %d\n", tas_get_capacity(my_tas));
            break;
            case 3:
                if(my_tas)
                    tas_set_content(my_tas, index_current, content_random_alloc());
            break;
            case 4:
                my_content = tas_get_content(my_tas, index_current);
                if(my_content)
                    content_free(my_content);
                tas_set_content(my_tas, index_current, NULL);
            break;
            case 5:
                my_content = tas_get_content(my_tas, index_current);
                if(my_content)
                    printf("Le contenu du noeux courent est ");
                    content_print(my_content);
                printf("\n");
            break;
            case 6:
                index = tas_get_left_child(index_current);
                if(index >= tas_get_capacity(my_tas))
                    printf("le noeud courent n'a pas de fils\n");
                else
                    index_current = index;
            break;
            case 7:
                index = tas_get_right_child(index_current);
                if(index >= tas_get_capacity(my_tas))
                    printf("le noeud courent n'a pas de fils\n");
                else
                    index_current = index;
            break;
            case 8:
                index = tas_get_father(index_current);
                if(index < 0)
                    printf("le noeud courent n'a pas de pere\n");
                else
                    index_current = index;
            break;
            case 9:
                tas_print(my_tas, (void(*)(void*)) content_print );
            break;
            case 10:
                tas_free(my_tas, (void(*)(void*)) content_free);
                my_tas = NULL;
                index_current = -1;
            break;
            case 11:
                return;
            break;
        }
        printf("L'index du noeud courent est %d\n", index_current);
    }
}

void content_menu()
{
    content * my_content = NULL, * my_content_a = NULL, * my_content_b = NULL;

    int choise;

    while(1)
    {
        printf("Menu test content :\n");
        printf("\t1) Test allocation\n");
        printf("\t2) Test fonction : content_print\n");
        printf("\t3) Test fonction : content_comp\n");
        printf("\t4) Quitter\n");
        printf("Choix :");
        scanf("%d",&choise);
        switch(choise)
        {
            case 1:
                printf("Allocation d'un contenu\n");
                my_content = content_random_alloc();
                printf("Allocation effectuée\nLibération du contenu alloué\n");
                content_free(my_content);
                printf("Libération effectuée\n");
            break;
            case 3:
                my_content_a = content_random_alloc();
                my_content_b = content_random_alloc();
                content_print(my_content_a);
                if(content_comp(my_content_a, my_content_b) < 0)
                    printf(" est plus petit que ");
                else if (content_comp(my_content_a, my_content_b) > 0)
                    printf(" est plus grand que ");
                else
                    printf(" est égale à ");
                content_print(my_content_b);
                printf("\n");
                content_free(my_content_a);
                content_free(my_content_b);
                my_content_a = NULL;
                my_content_b = NULL;
            break;
            case 2:
                my_content = content_random_alloc();
                content_print (my_content);
                printf("\n");
                content_free(my_content);
                my_content = NULL;
            break;
            case 4:
                return;
            break;
        }
    }
}


void main_menu()
{
    int choise;

    while(1)
    {
        printf("Menu prinsipal\n\t1) Test content\n\t2) Test tas\n\t3) Test tas huffman\n\t4) Quitter\n");
        printf("Choix :");
        scanf("%d",&choise);
        switch(choise)
        {
            case 1:
                content_menu();
            break;
            case 2:
                tas_menu();
            break;
            case 3:
                tas_huffman_menu();
            break;
            case 4:
                return;
            break;
        }
    }
}

