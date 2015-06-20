#!/usr/bin/env python
# coding=utf-8

def findmissing(items, i) :
    if len(items) == 0:
        return 0
    
    numone = numzero = 0
    itemone = []
    itemzero = []
    for e in items:
        if (e >> i) & 1 == 0:
            numzero += 1
            itemzero.append(e)
        else:
            numone += 1
            itemone.append(e)

    if numone >= numzero:
        #remove 0
        return 2 * findmissing(itemzero, i+1)
    else:
        #remove 1
        return 2 * findmissing(itemone, i+1) + 1



items = [0,1,2,3,5,6,7,8]
print findmissing(items, 0)
