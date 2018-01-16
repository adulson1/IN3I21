
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int random_int(int a, int b)
{
    return a+rand()%(b-a);
}

float random_float()
{
    return (1.0*rand())/RAND_MAX;
}

void random_string(char * p_string, unsigned int size)
{
    unsigned int i;
    for( i = 0 ; i < size ; i++ )
    {
        p_string[i] = 'a' + random_int(0,26);
    }
    p_string[size] = '\0';
}
