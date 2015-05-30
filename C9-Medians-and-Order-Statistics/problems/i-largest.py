#!/usr/bin/env python
# coding=utf-8

from Queue import PriorityQueue

def sort1(items, i):
    items = sorted(items,reverse=True)
    return items[:i]

def sort2(items, i):
    pq = PriorityQueue()
    for element in items:
        pq.put((-element, element))
    array = []
    for k in range(i):
        array.append(pq.get()[1])
    return array



items = [3,0,7,8,-2,12]
print sort1(items, 3)
print sort2(items, 3)