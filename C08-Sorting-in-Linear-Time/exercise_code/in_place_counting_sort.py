#!/usr/bin/env python
# coding=utf-8

def in_place_counting_sort(items, k):
    C = [0] * k
    for e in items:
        C[e] += 1
    for i in range(1,k):
        C[i] += C[i-1]
    i = len(items) - 1
    while i >= 0:
        print items,C
        v = items[i]
        pos = C[v] - 1
        if i > pos:
            i -= 1
        elif v != items[pos]:
            items[i],items[pos] = items[pos],items[i]
            C[v] -= 1
        else:
            C[v] -= 1


items = [2, 5, 3, 0, 2, 3, 0, 3];
print items
print "sorting --------------"
in_place_counting_sort(items, 6)
print "sorting finishing -------------"
print items
