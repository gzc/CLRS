/*************************************************************************
	> File Name: d-ary-heaps.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Tue Jun 23 19:22:21 2015
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;

#define PARENT(i,d) ((i - 1) / d)
#define CHILD(i,c,d) (d * i + c + 1)

typedef struct {
    int *elements;
    int d;
    int heap_size;
} heap_t;

void max_heapify(heap_t *heap, int i) {
    int largest = i;
    int basechild = CHILD(i, 0, heap->d);
    
    for (int k = 0; k < heap->d; k++) {
        int child = basechild+k;
        if (child < heap->heap_size && heap->elements[child] > heap->elements[largest])
            largest = child;
    }
    
    if (largest != i) {
        swap(heap->elements[i],heap->elements[largest]);
        max_heapify(heap, largest);
    }
}

int extract_max(heap_t *heap) {
    int max = heap->elements[0];
    heap->elements[0] = heap->elements[heap->heap_size - 1];
    heap->heap_size--;
    max_heapify(heap, 0);
    return max;
};

void increase_key(heap_t *heap, int i, int key) {
    if (key < heap->elements[i]) {
        cerr << "new key is smaller than current key" << endl;
        exit(-1);
    }
    
    while (i > 0 && heap->elements[PARENT(i,heap->d)] < key) {
        heap->elements[i] = heap->elements[PARENT(i,heap->d)];
        i = PARENT(i,heap->d);
    }
    
    heap->elements[i] = key;
}

void insert(heap_t *heap, int key) {
    heap->heap_size++;
    heap->elements[heap->heap_size - 1] = INT_MIN;
    increase_key(heap, heap->heap_size - 1, key);
}