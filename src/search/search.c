#include<stdio.h>
#include<stdlib.h>
#include "search.h"

// Assign more space to string
void expand_string(string *s){
    s->str = (char*) realloc(s->str, sizeof(char)*(s->size*2));
    s->size = s->size*2;
}

// Finds the suggestions for the given string using dfs with backtracking
int dfs(trienode* current, heap *minheap, string *s, int k){
    // If index = max capacity of string
    if(s->size == s->index){
        expand_string(s);
    }
    // If current node is the terminal node add the string and the frequency count to min heap
    if(get(current->children, '*') != NULL){
        trienode *tnode = get(current->children, '*');
        *(s->str+s->index) = '\0';
        offer(minheap, s->str, tnode->freq);
        // Remove an element from heap if size = k 
        if(minheap->size == k)
            poll(minheap);
    }
    trienode *child;
    int i;
    // Check if a-z or ' ' is present as the child of current node
    for(i = 97; i<=122; i++){
        child = get(current->children, (char)i);
        if(child != NULL){
            // Append the character to s
            *(s->str+s->index) = (char) i;
            s->index++;
            dfs(child, minheap, s, k);
            // Remove character from s
            s->index--;
        }
    }
    // Similarly, check for ' '
    child = get(current->children, ' ');
    if(child != NULL){
        *(s->str+s->index) = ' ';
        s->index++;
        dfs(child, minheap, s, k);
        s->index--;
    }
}

char** get_suggestions(trienode* root, char str[], int k){
    char **suggestions;
    heap *minheap; trienode *current;
    int index; string s;
    
    // Initialize char double pointer to store list of strings
    suggestions = (char**) calloc(k,sizeof(char*));
    minheap = init_heap(k);
    
    // Initialize string for storing string during dfs
    s.str = (char *)malloc(sizeof(char)*2);
    s.size = 2;
    s.index = 0;

    // Traverse the given string in trie
    current = traverse(root, str);
    if(current == NULL)
        return suggestions; // No suggestions found
    
    // DFS to find all the suggestions
    dfs(current, minheap, &s, k);
    index = minheap->size;

    // Remove the suggestions one-by-one from min heap and add to suggestions
    while(minheap->size >= 0){
        *(suggestions+index) = (char*)malloc(sizeof(peek(minheap)));
        strcpy(*(suggestions+index), poll(minheap));
        index--;
    }
    return suggestions;
}
