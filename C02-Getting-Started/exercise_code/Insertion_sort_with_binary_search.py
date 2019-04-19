# Exercise 2.3-6 in book
# Standalone Python version 2.7 code
import os
import re
import math
import time
from random import randint

def insertion_sort(array):
	for j, v in enumerate(array):
		key = v
		i = j - 1
		while i > -1 and array[i] > key:
			array[i+1] = array[i]
			i = i - 1
		array[i+1] = key
		
def insertion_sort_v2(array):
	for j, v in enumerate(array):
		if j > 0:
			key = array[j]
			a = binary_search(array, key, j)
			for i in range(j, a, -1):
				array[i] = array[i-1]
			array[a] = key

def binary_search(array, searchingelement, arraypart):
	array = list(array[:arraypart])
	last = array.__len__()
	mid = int(last/2)
	min = 0
	for i in range(int(math.log(last)/math.log(2)) + 1):
		if array[mid] == searchingelement:
			return mid
		elif array[mid] < searchingelement:
			min = mid
			mid = int((last + mid) / 2)
		else:
			last = mid
			mid = int((mid + min) / 2)
	if array[mid] < searchingelement:
		return mid+1
	elif array[mid] > searchingelement:
		if mid-1 > -1:
			return mid-1
		else:
			return mid
	else:
		return mid
	
	
if __name__ == '__main__':
	array1 = []
	for i in range(10000):
		array1.append(randint(0, 1000))
	
	array = list(array1)
	t0 = time.clock()
	insertion_sort(array)
	t1 = time.clock()
	print "insertion_sort: " + str(t1-t0)

	array = list(array1)
	t0 = time.clock()
	insertion_sort_v2(array)
	t1 = time.clock()
	print "insertion_sort_v2: " + str(t1-t0)
# Test results shows that worst case of improved insertion sort is O(n * (n\2) * lg(n)) 
# Better than insertion sort but still very bad
# Tested for 1000 random elements
# insertion_sort:----0.0390096090178
# insertion_sort_v2:-0.0287921815039

# Tested for 10000 random elements
# insertion_sort:----3.76619711492
# insertion_sort_v2:-2.25984142782
# End of 2.3-6 in book
