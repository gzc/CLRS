#!/usr/bin/env python
# coding=utf-8

def quicksort(items, p, r):
    if p < r:
        q = partition(items, p, r)
        quicksort(items, p, q)
        quicksort(items, q+1, r)

def partition(items, p, r):
    x = items[p]
    i = p - 1
    j = r + 1
    while True:
        
        while True:
            j = j - 1
            if items[j] <= x:
                break
        while True:
            i = i + 1
            if items[i] >= x:
                break
        if i < j:
            items[i],items[j] = items[j],items[i]
        else:
            return j


items = [13,19,9,5,12,8,7,4,11,2,6,21]
quicksort(items, 0, len(items)-1)
print items
