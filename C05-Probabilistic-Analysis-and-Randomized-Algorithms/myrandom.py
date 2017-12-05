#! /usr/bin/env python
# -*- coding: utf-8 -*-

import numpy as np
from math import log
from random import randint
from collections import Counter
import matplotlib.pyplot as plt

def _m_random(b):
    n = int(log(b, 2)) + 1
    while True:
        r = 0
        for i in range(n):
            r = 2*r + randint(0, 1)
        if r <= b:
            return r

def m_random(a, b):
    return _m_random(b - a) + a

def main():
   result = Counter()
   for i in xrange(10000):
       temp = m_random(1,7)
       result.update('{}'.format(temp))
   key, value = zip(*result.items())
   indexes = np.arange(len(key))
   width = 1
   plt.bar(indexes,value,width)
   plt.xticks(indexes + 0.5 * width, key)
   plt.show()

if __name__ == '__main__':
    main()
