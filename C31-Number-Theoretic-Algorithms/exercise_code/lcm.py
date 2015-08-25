#!/usr/bin/env python
# coding=utf-8

def gcd(a, b):
    while b != 0:
        tmp = b
        b = a % b
        a = tmp
    return a


def lcm(items):
    while True:
        if len(items) == 1:
            return items[0]
        else:
            a = items[-1]
            b = items[-2]
            del items[-1]
            del items[-1]
            items.append(a*b/gcd(a,b))

print lcm([9,12,15])
