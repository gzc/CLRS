#!/usr/bin/env python
# coding=utf-8

def merge(items, p, q, r):
    L = items[p:q+1]
    R = items[q+1:r+1]
    i = j = 0
    k = p
    inversions = 0
    while i < len(L) and j < len(R):
        if(L[i] < R[j]):
            items[k] = L[i]
            i += 1
        else:
            items[k] = R[j]
            j += 1
            inversions += (len(L) - i)
        k += 1
    if(j == len(R)):
        items[k:r+1] = L[i:]
    return inversions



def mergesort(items, p, r):
    inversions = 0
    if(p < r):
        q = (p+r)/2
        inversions += mergesort(items, p, q)
        inversions += mergesort(items, q+1, r)
        inversions += merge(items, p, q, r)
    return inversions


items = [4,3,2,1,17]
inversions = mergesort(items, 0, len(items)-1)
print items,inversions