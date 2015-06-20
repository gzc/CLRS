#!/usr/bin/env python
# coding=utf-8


def mergeindex(items, evens):
    res = []
    l = len(items[0])
    for i in range(len(items)):
        left = evens[i]
        right = -1
        if i == len(items)-1 and len(evens) == len(items):
            right = l - 1
        else:
            right = evens[i+1]

        minimum = items[i][left]
        pos = left
        for j in range(left, right+1):
            if items[i][j] < minimum:
                minimum = items[i][j]
                pos = j
        res.append(evens[i])
        res.append(pos)
    
    if len(evens) > len(items):
        res.append(evens[-1])
    return res


    

def findindex(items):

    if len(items) == 1:
        res = 0
        minimum = 2**31-1
        for i in range(len(items[0])):
            if items[0][i] < minimum:
                minimum = items[0][i]
                res = i
        return [res]
            
    evens = items[::2]
    evenres = findindex(evens)
    res = mergeindex(items[1::2], evenres)
    return res


items=[[37,23,24,32],[21,6,7,10],[53,34,30,31],[32,13,9,6],[43,21,15,8]]
print findindex(items)
