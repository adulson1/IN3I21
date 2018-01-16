#include "main.h"
#include <string.h>
#include <stdlib.h>

int main()
{
    char* string = "Vanhove est un magnnnnnnnnnifique génie";
    dictionary* tab = getSortedTab(string);
    free(tab);
}

dictionary* getSortedTab(char* word)
{
    int sizeString = strlen(word);
    dictionary* tab = (dictionary*) malloc(sizeof(dictionary)*sizeString);
    int sizeTab =0;
    for(int i=0;i<sizeString;i++){
        if(letterInTab(word[i],tab,sizeTab) == 0)
        {  
            dictionary dic;
            dic.letter = word[i]; 
            int occurrence = 0;
            for(int k=i;k<sizeString;k++)
            {
                if(word[i]==word[k])
                {
                    occurrence++;
                }
            }
            dic.numberOfOccurrence = occurrence;
            tab[sizeTab] = dic;
            sizeTab++;
        }
    }
    dictionary* finalTab = (dictionary*) malloc(sizeof(dictionary)*sizeTab);
    finalTab = tab;
    for(int i = 0;i<sizeTab;i++)
    {
        for(int k=i+1;k<sizeTab;k++)
        {
            if(tab[i].numberOfOccurrence>tab[k].numberOfOccurrence)
            {
                dictionary temp = finalTab[i];
                finalTab[i] = finalTab[k];
                finalTab[k] = temp;
            }                
        }
    }
    return finalTab;
}

int letterInTab(char letter, dictionary* tab , int sizeTab)
{
   for(int j=0;j<sizeTab;j++)
   {
       if(letter == tab[j].letter)
           return 1;
   }
   return 0;
}
