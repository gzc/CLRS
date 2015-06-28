#!/usr/bin/env python
# coding=utf-8

def quicksort(items, p, r):
    if p < r:
        q = partition(items, p, r)
        quicksort(items, p, q-1)
        quicksort(items, q+1, r)

def partition(items, p, r):
    x = items[r]
    i = p-1
    for j in range(p, r):
        if items[j] <= x:
            i = i + 1
            items[i],items[j] = items[j],items[i]

    items[i+1],items[r] = items[r],items[i+1]
    return i+1



items = [2,5,9,3,7,0,-1]
quicksort(items, 0, len(items)-1)
print items
