#!/usr/bin/env python
# coding=utf-8
import random
import copy

def intersects(a, b):
    return a[0] <= b[1] and b[0] <= a[1]

def before(a, b):
    return a[1] < b[0]

def partition(items, p, r):
    pick = random.randint(p, r)
    items[pick], items[r] = items[r], items[pick]
    intersection = copy.deepcopy(items[r]);
    
    for i in range(p, r):
        if intersects(intersection, items[i]):
            if items[i][0] > intersection[0]:
                intersection[0] = items[i][0]
            if items[i][1] < intersection[1]:
                intersection[1] = items[i][1]

    s = p
    for i in range(p, r):
        if before(items[i], intersection):
            items[i], items[s] = items[s], items[i]
            s += 1

    items[r], items[s] = items[s], items[r]


    t = s + 1
    while t <= i:
        if intersects(items[i], intersection):
            items[t], items[i] = items[i], items[t]
            t += 1
        else:
            i -= 1

    return (s, t)


def fuzzy_sort(items, p, r):
    if (p < r):
        pivot = partition(items, p, r);
        fuzzy_sort(items, p, pivot[0]);
        fuzzy_sort(items, pivot[1], r);


items = [[2,4],[0,1],[3,5],[-1,-2],[0,99]]
print items
fuzzy_sort(items, 0, len(items)-1)
print items
