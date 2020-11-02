#include<stdio.h>
#include<stdlib.h>
#include "hashmap.h"

// Initializes the hashmap. The size is used for calculating the hashcode of a given element
hashmap* initmap(int size){
    hashmap *map = (hashmap*) malloc(sizeof(hashmap));
    map->list = (node**) calloc(size, sizeof(node));
    map->size = size;
    map->count = 0;
    return map;
}

// Uses a simple modulo function as the hash function. Works well in this situation
int hashcode(char key, int size){
    if(key>=97 && key<=122)
        return ((int)key-97)%size; 
    return ((int) key)%size;
}

// Searches if a key is present in the linklist
node* find(node* list, char key){
    node *current = list;
    // Traverse a link list till NULL
    while(current!=NULL){
        if(current->key == key)
            return current;
        current = current->next;
    }
    return NULL;
}
// Add an entry to hashmap
void put(hashmap* map, char key, void* val){
    node *current, *newnode;
    int index;
    // Get the hashcode for the given key. This will act as an index to the outer list of linkedlists
    index = hashcode(key, map->size);
    // Checks if key already exists
    current = find(map->list[index], key);

    // If key does not exist add the new key, value pair else replace the value
    if(current == NULL){
        newnode = (node*) malloc(sizeof(node));
        newnode->key = key;
        newnode->val = val;
        newnode->next = map->list[index];
        map->list[index] = newnode;
        map->count++;
    }
    else{
        current->val = val;
    }
}

// Return the value node corresponding to the given key
void* get(hashmap *map, char key){
    node *current;
    // Get the hashcode
    int index = hashcode(key, map->size);
    // Check if key exist in list and return value accordingly
    current = find(map->list[index], key);
    if(current == NULL)
        return NULL;
    return current->val;
}

// Remove an entry from the hash map
void del(hashmap *map, char key){
    node *current, *prev;
    int temp, index;
    // Find the hashcode for the given key
    index = hashcode(key, map->size);
    current = map->list[index];
    prev = NULL;
    // Search for the key in the list pointed by the hashcode
    while(current!=NULL){
        if(current->key == key)
            break;
        prev = current;
        current = current->next;
    }
    // If key found remove the element
    if(current != NULL){
        if(prev == NULL)
            map->list[index] = map->list[index]->next;
        else{
            prev->next = current->next;
        }
        // Free the node
        free(current);
        map->count--;
    }
}

