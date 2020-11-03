#ifndef AUTOCOMPLETE_MAP_HASHMAP_H_
#define AUTOCOMPLETE_MAP_HASHMAP_H_

typedef struct node{
    char key;
    void *val;
    struct node *next;
} node;

typedef struct hashmap{
    int size;
    int count;
    node **list;
}hashmap;

hashmap *initmap(int);
void put(hashmap*, char, void*);
void* get(hashmap *, char);
void del(hashmap *, char);

#endif