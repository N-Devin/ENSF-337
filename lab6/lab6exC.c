//  ENSF 337 - Lab 6 Exercise C
//  lab6exC.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab6exC.h"

char str [] = "foo";

void goodcopy(String *dest, const String *src)
{
    dest->text = (char*)malloc(strlen(src->text) + 1);
    
    if(dest -> text == NULL) {
        fprintf(stderr, "Memory Not Available...");
        exit(1);
    }
    
    dest->length = src -> length;
    
    int i;
    for(i = 0; i < src -> length; i++)
        dest->text[i] = src -> text[i];
    
    dest->text[i] = '\0';
}

void badcopy (String *dest, const String *src)
{
    *dest = *src;
    // point one
}


int main(void)
{
    String s1 = {str, (int) strlen(str)};
    
    String *s2 = (String*) malloc(sizeof(String));
    
    if(s2 == NULL) {
        fprintf(stderr, "Memory Not Available...");
        exit(1);
    }
    
    goodcopy(s2, &s1);
    
    s1.text = (char*) malloc(strlen("mars") +1);
    
    if(s1.text == NULL) {
        fprintf(stderr, "Memory Not Available...");
        exit(1);
    }
    
    strcpy(s1.text, "mars");
    
    s1.length = 4;
    
    badcopy(s2, &s1);
    
    return 0;
}

