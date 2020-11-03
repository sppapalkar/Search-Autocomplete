#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "heap.h"

// Initialized min heap 
heap* init_heap(int size){
    heap *minheap = (heap*) malloc(sizeof(heap));
    minheap->elements = (heapnode*) calloc(size+1, sizeof(heapnode));
    minheap->size = -1;
    return minheap;
}

// Free heap space
void destroy_heap(heap* minheap){
    free(minheap->elements);
    free(minheap);
}

// Swap two elements of min heap
void swap(heap *minheap, int index1, int index2){
    heapnode temp;
    temp = minheap->elements[index1];
    minheap->elements[index1] = minheap->elements[index2];
    minheap->elements[index2] = temp; 
}

// Heapify the heap - least node becomes the root
// Recursively compares a node with its childrens and swap so that the smallest amongst the 3 is the parent 
void heapify(heap *minheap, int element){
    int left, right, smallest;
    left = 2*element;
    right = (2*element) + 1;
    smallest = element;
    // Compare with left and child
    if(left <= minheap->size && minheap->elements[left].val < minheap->elements[smallest].val){
        smallest = left;
    }
    if(right <= minheap->size && minheap->elements[right].val < minheap->elements[smallest].val){
        smallest = right;
    }
    // If the smallest element is not the parent then swap the smallest child with parent
    if(smallest != element){
        swap(minheap, smallest, element);
        heapify(minheap, smallest);
    }
}

// Add a new value to the heap
void offer(heap *minheap, char str[], int val){
    int index;
    // Add new element to the end of heap
    minheap->size++;
    minheap->elements[minheap->size].str = (char*) malloc(sizeof(str));
    strcpy(minheap->elements[minheap->size].str, str);
    minheap->elements[minheap->size].val = val;
    
    // Move the node up the tree based on its value
    index = minheap->size;
    while(minheap->elements[index/2].val > val){
        swap(minheap, index, index/2);
        index = index/2;
    }
}

// Poll the tree to remove the smallest value
char* poll(heap *minheap){
    char *min = minheap->elements[0].str;
    // Replace the last element with first and then call heapify
    minheap->elements[0] = minheap->elements[minheap->size];
    minheap->size--;
    heapify(minheap, 0);
    return min; 
}

// Returns the root of the heap
char* peek(heap *minheap){
    if(minheap->size == -1)
        return NULL;
    return minheap->elements[0].str;
}