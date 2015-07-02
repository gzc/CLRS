#!/usr/bin/env python
# coding=utf-8
import random

def match(reds, blues):
    if not reds:
        return
    r = random.randint(0,len(reds)-1)
    v = reds[r]
    smaller_red = [item for item in reds if item < v]
    larger_red  = [item for item in reds if item > v]
    smaller_blue = [item for item in blues if item < v]
    larger_blue  = [item for item in blues if item > v]
    print v,v
    match(smaller_red,smaller_blue)
    match(larger_red,larger_blue)

reds = [3,2,1,5,4]
blues = [2,3,5,1,4]
match(reds, blues)