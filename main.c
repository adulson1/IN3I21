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

    int i , taille1 = 2 , taille2 = 3;
    content **ptr;

    ptr = malloc(taille1 * sizeof(*ptr));
    if(ptr == NULL){
    //TODO
    }
    for(i=0 ; i < taille1 ; i++){
        ptr[i] = content_random_alloc();
        if(ptr[i] == NULL){
        //TODO
        }
        content_print(ptr[i]);
    }
}
