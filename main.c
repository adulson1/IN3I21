#include <stdlib.h>
#include <stdio.h>
#include "content.h"

int main()
{
    printf("Hello les bgey");
    test_content_print();
    return 0;
}

void test_content_print(){
    int TAILLE = 5;
    content** tab = (content**) malloc(5*sizeof(*content));

    int i;
    for(i=0; i<TAILLE; i++){
        tab[i]= content_random_alloc();
        content_print(*tab + i);
    }
}
