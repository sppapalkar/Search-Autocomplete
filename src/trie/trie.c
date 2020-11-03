#include<stdio.h>
#include<stdlib.h>
#include "trie.h"

trienode* init_trienode(char ch){
    trienode *node = (trienode*) malloc(sizeof(trienode));
    node->ch = ch;
    node->children = initmap(26);
    node->freq = 0;
}

void insert(trienode *root, char str[], int freq){
    trienode *current, *child;
    int index = 0;
    current = root;

    while(str[index] != '\0'){
        child = (trienode*) get(current->children, str[index]);

        if(child == NULL){
            child = init_trienode(str[index]);
            put(current->children, str[index], child);
        }

        current = child;
        index+=1; 
    }
    child = init_trienode('*');
    child->freq = freq;
    put(current->children, '*', child);
}
