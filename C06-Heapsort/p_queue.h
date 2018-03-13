/*************************************************************************
	> File Name: p_queue.h
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Sun Jan  4 19:16:19 2015
 ************************************************************************/
#ifndef _P_QUEUE_H
#define _P_QUEUE_H
#endif

#include <iostream>

class p_queue
{
public:
    p_queue(int *A, int n);
    void insert(int x);
    int maximum(void);
    int extract_max(void);
    void increase_key(int i, int x);
    
private:
    int a[10000];
    int size;
    
    int parent(int i);
    int left(int i);
    int right(int i);
    void maxHeapify(int A[], int n, int i);
    void buildMaxHeap(int A[], int n);
    void heapsort(int A[], int n);
};
