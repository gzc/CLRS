#!/usr/bin/env python
# coding=utf-8

def ee(a, b):
    if b == 0:
        return (a, 1, 0)
    res = ee(b, a % b)
    return (res[0], res[2], res[1] - a/b*res[2])

print ee(99, 78)
print ee(899, 493)
print ee(2,1)
print ee(3,2)
print ee(5,3)
print ee(8,5)
print ee(13,8)
