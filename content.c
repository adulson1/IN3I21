#include <stdio.h>
#include <stdlib.h>

#include "content.h"

content * content_alloc(int val){
    content *pc = (content*)malloc(sizeof(content));
    if(pc)
        pc->val = val;
    return pc;
}

//content * content_random_alloc(){
//    return content_alloc(random_int(1,100));
//}

void content_free(content *pc){
    if(pc)
        free(pc);
}

void content_print(content *pc){
    if(pc)
        printf("%d", pc->val);
}

int content_comp(content *pc1, content* pc2){
    if(pc1 && pc2)
        return pc1->val - pc2->val;
    else
        return 0;
}
