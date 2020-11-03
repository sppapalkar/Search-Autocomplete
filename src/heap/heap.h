#ifndef AUTOCOMPLETE_HEAP_HEAP_H_
#define AUTOCOMPLETE_HEAP_HEAP_H_

typedef struct heapnode{
    char *str;
    int val;
}heapnode;

typedef struct heap{
    int size;
    heapnode *elements;
}heap;

heap* init_heap(int);
void heapify(heap *, int);
void offer(heap *, char[], int);
char* poll(heap *);
char* peek(heap *);

#endif