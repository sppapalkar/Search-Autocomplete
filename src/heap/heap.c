#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "heap.h"

heap* init_heap(int size){
    heap *minheap = (heap*) malloc(sizeof(heap));
    minheap->elements = (heapnode*) calloc(size+1, sizeof(heapnode));
    minheap->size = -1;
    return minheap;
}

void swap(heap *minheap, int index1, int index2){
    heapnode temp;
    temp = minheap->elements[index1];
    minheap->elements[index1] = minheap->elements[index2];
    minheap->elements[index2] = temp; 
}

void heapify(heap *minheap, int element){
    int left, right, smallest;
    left = 2*element;
    right = (2*element) + 1;
    smallest = element;

    if(left <= minheap->size && minheap->elements[left].val < minheap->elements[smallest].val){
        smallest = left;
    }
    if(right <= minheap->size && minheap->elements[right].val < minheap->elements[smallest].val){
        smallest = right;
    }
    if(smallest != element){
        swap(minheap, smallest, element);
        heapify(minheap, smallest);
    }
}

void offer(heap *minheap, char str[], int val){
    int index;
    minheap->size++;
    minheap->elements[minheap->size].str = str;
    minheap->elements[minheap->size].val = val;

    index = minheap->size;
    while(minheap->elements[index/2].val > val){
        swap(minheap, index, index/2);
        index = index/2;
    }
}

char* poll(heap *minheap){
    char *min = minheap->elements[0].str;
    minheap->elements[0] = minheap->elements[minheap->size];
    minheap->size--;
    heapify(minheap, 0);
    return min; 
}
