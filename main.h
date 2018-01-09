#include <stdio.h>

typedef struct{
    char letter;
    int numberOfOccurrence;
} dictionary;

dictionary* getSortedTab(char* word);

int letterInTab(char letter, dictionary* tab, int sizeTab);
