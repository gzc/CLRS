#!/usr/bin/env python
# coding=utf-8

def gcd(a, b):
    while b != 0:
        tmp = b
        b = a % b
        a = tmp
    return a


print gcd(69,99)
