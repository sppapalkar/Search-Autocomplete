#ifndef AUTOCOMPLETE_SEARCH_SEARCH_H_
#define AUTOCOMPLETE_SEARCH_SEARCH_H_
#include "../trie/trie.h"
#include "../heap/heap.h"

typedef struct string{
    int size;
    int index;
    char *str;
}string;

char** get_suggestions(trienode*, char[], int);
#endif