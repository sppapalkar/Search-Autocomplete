#ifndef AUTOCOMPLETE_TRIE_TRIE_H_
#define AUTOCOMPLETE_TRIE_TRIE_H_
#include "../map/hashmap.h"

typedef struct trienode{
    char ch;
    int freq;
    hashmap *children;
}trienode;

trienode* init_trienode(char);
void insert(trienode*, char[], int freq);

#endif