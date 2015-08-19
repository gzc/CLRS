#!/usr/bin/env python
# coding=utf-8

def b2d(binary, base):
    l = len(binary)
    if l == 1:
        return int(binary)*base;
    mid = l/2
    high = binary[:mid]
    low = binary[mid:]
    return b2d(high, base*(2**(l-mid)))+b2d(low, base)

binary = "1111"
print b2d(binary,1)