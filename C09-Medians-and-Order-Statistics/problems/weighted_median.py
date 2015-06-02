#!/usr/bin/env python
# coding=utf-8
import math

def select(items, n):
    med     = median(items)
    smaller = [item for item in items if item < med]
    larger  = [item for item in items if item > med]
    
    if len(smaller) == n:
        return med
    elif len(smaller) > n:
        return select(smaller, n)
    else:
        return select(list(larger), n - len(smaller) - 1)

def median(items):
    def median_index(n):
        if n % 2:
            return n // 2
        else:
            return n // 2 - 1

    def partition(items, element):
        i = 0
        
        for j in range(len(items) - 1):
            if items[j] == element:
                items[j], items[-1] = items[-1], items[j]
            
            if items[j] < element:
                items[i], items[j] = items[j], items[i]
                i += 1
    
        items[i], items[-1] = items[-1], items[i]
        
        return i

    def select(items, n):
        if len(items) <= 1:
            return items[0]
        
        medians = []
        
        for i in range(0, len(items), 5):
            group = sorted(items[i:i + 5])
            items[i:i + 5] = group
            median = group[median_index(len(group))]
            medians.append(median)
    
        pivot = select(medians, median_index(len(medians)))
        index = partition(items, pivot)
        
        if n == index:
            return items[index]
        elif n < index:
            return select(items[:index], n)
        else:
            return select(items[index + 1:], n - index - 1)

    return select(items[:], median_index(len(items)))

def weighted_median(items, w_items, start, end):
    
    def linear_weighted_median(items, start, end):
        med     = median(items)
        smaller = [item for item in items if item < med]
        larger  = [item for item in items if item > med]
    
        leftsum = 0
        rightsum = 0
        for i in range(len(smaller)):
            leftsum += m[smaller[i]]
        for i in range(len(smaller)):
            rightsum += m[larger[i]]
        
        print leftsum,rightsum

        if leftsum < 0.5 and rightsum <= 0.5:
            return med
        if leftsum >= 0.5:
            m[med] += rightsum
            smaller.append(med)
            return linear_weighted_median(smaller, start, start+len(smaller)-1)
        else:
            m[med] += leftsum
            larger.insert(0, med)
            return linear_weighted_median(larger, start+len(smaller)+1, end)
    
    m = dict()
    for i in range(len(items)):
        m[items[i]] = w_items[i]
    return linear_weighted_median(items, start, end)


weighted_array = [0.3,0.3,0.1,0.05,0.25]
array = [5,4,0,3,2]
print weighted_median(array, weighted_array, 0, 4)

