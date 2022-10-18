from pkgutil import iter_modules
from wsgiref.validate import PartialIteratorWrapper


def quicksort(items, p, r):
    if p < r:
        q = partition(items, p, r)
        quicksort(items, p, q-1)
        quicksort(items, q+1, r)

def partition(items, p, r):
    x = items[r] # pivot
    i = p-1 # insert index
    high = r # last index of the searching
    count = 0 # count of value such as pivot

    j = p # loop count
    while j < high :
        # if value is same to pivot, move it to end of the non-searching
        if items[j] == x :
            high -= 1
            count += 1
            items[j], items[high] = items[high], items[j]
        
        else :
            if items[j] < x :
                i += 1
                items[i], items[j] = items[j], items[i]
            j += 1
    # move pivots to appropriate index
    for x in range(0, count + 1) :
        items[i + 1 + x], items[high + x] = items[high + x], items[i + 1 + x]

    # return mid index of pivots
    return int(i + 1 + count/2)



items = [1, 4, 3, 3, 9, 3, 2, 10, 5, 8, -1, 3]
print(quicksort(items, 0, len(items) - 1))
