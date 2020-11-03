#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include "trie.h"
// Initializes the trienode
trienode* init_trienode(char ch){
    trienode *node = (trienode*) malloc(sizeof(trienode));
    node->ch = ch;
    node->children = initmap(26);
    node->freq = 0;
}

// Inserts a node to trie
void insert(trienode *root, char str[], int freq){
    trienode *current, *child;
    int index = 0;
    current = root;
    // Iterate through each character and add it to trie
    while(str[index] != '\0'){
        str[index] = tolower(str[index]);
        // Check if character is a-z or ' ' 
        if((str[index] < 97 || str[index] > 122) && str[index] != ' ')
            continue;
        // Get the already existing node for the chracter else create new node
        child = (trienode*) get(current->children, str[index]);
        if(child == NULL){
            child = init_trienode(str[index]);
            put(current->children, str[index], child);
        }

        current = child;
        index+=1; 
    }
    // Last node will be '*' and frequency
    child = init_trienode('*');
    child->freq = freq;
    put(current->children, '*', child);
}
