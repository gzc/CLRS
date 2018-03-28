/*************************************************************************
	> File Name: p_queue.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Sun Jan  4 19:28:46 2015
 ************************************************************************/

#include "p_queue.h"
#include <limits>

p_queue::p_queue(int *A, int n)
{
    for(int i = 0;i < n;i++)
    {
        a[i] = A[i];
    }
    size = n;
    buildMaxHeap(a, size);
}

void p_queue::insert(int x)
{
    size++;
    a[size-1] = x;
    int i = size-1;
    while(i > 0 && a[parent(i)] < a[i])
    {
        std::swap(a[i], a[parent(i)]);
        i = parent(i);
    }
}

int p_queue::maximum()
{
    if(size <= 0)
    {
        std::cerr << "heap overflow" << std::endl;
        return -1;
    }
    return a[0];
}

int p_queue::extract_max()
{
    if(size <= 0)
    {
        std::cerr << "heap overflow" << std::endl;
        return -1;
    }
    int max = a[0];
    a[0] = a[size-1];
    size--;
    maxHeapify(a, size, 0);
    return max;
}

void p_queue::increase_key(int i, int x) {
    a[i] = std::max(a[i], x);

    while (i > 0 && a[parent(i)] < a[i]) {
        std::swap(a[parent(i)], a[i]);
        i = parent(i);
    }
}

int p_queue::parent(int i)
{
    return (i-1)/2;
}

int p_queue::left(int i)
{
    return 2*i+1;
}

int p_queue::right(int i)
{
    return 2*i+2;
}

void p_queue::maxHeapify(int A[], int n, int i)
{
    int l = left(i);
    int r = right(i);
    int largest(0);
    if (l <= (n-1) && A[l] > A[i])
        largest = l;
    else
        largest = i;
    if (r <= (n-1) && A[r] > A[largest])
        largest = r;
    if(largest != i)
    {
        std::swap(A[i], A[largest]);
        maxHeapify(A, n, largest);
    }
}

void p_queue::buildMaxHeap(int A[], int n)
{
    for(int i = n/2-1;i >= 0;i--)
        maxHeapify(A, n, i);
}

void p_queue::heapsort(int A[], int n)
{
    buildMaxHeap(A, n);
    for(int i = n-1;i > 0;i--)
    {
        std::swap(A[0],A[i]);
        maxHeapify(A, --n, 0);
    }
}




