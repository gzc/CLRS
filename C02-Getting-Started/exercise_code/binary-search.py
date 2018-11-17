#!/usr/bin/env python
# coding=utf-8
# Standalone python code, version 2.7
# I can provide older version to compare them with each other
import os
import re
import math
import time

def binary_search(array, searchingelement):
	last = array.__len__()
	mid = int(last/2)
	min = 0
	for i in range(int(math.log(last)/math.log(2)) + 1):
		if array[mid] == searchingelement:
			return str(mid) + " th index"
		elif array[mid] < searchingelement:
			min = mid
			mid = int((last + mid) / 2)
		else:
			last = mid
			mid = int((mid + min) / 2)
	return null
		
if __name__ == '__main__':
	array = []
	for i in range(1000000):
		array.append(i)
		
	t0 = time.clock()
	print binary_search(array, 345676)
	t1 = time.clock()
	print "binary_search: " + str(t1-t0)
