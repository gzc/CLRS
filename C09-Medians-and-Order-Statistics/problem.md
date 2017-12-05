### Problems 1 : Largest i numbers in sorted order
***

Given a set of *n* numbers, we wish to find the *i* largest in sorted order using a comparison- based algorithm. Find the algorithm that implements each of the following methods with the best asymptotic worst-case running time, and analyze the running times of the algorithms in terms of *n* and *i*.


a. Sort the numbers, and list the *i* largest.
b. Build a max-priority queue from the numbers, and call EXTRACT-MAX *i* times.
c. Use an order-statistic algorithm to find the *i*th largest number, partition around that number, and sort the *i* largest numbers.

### `Answer`
a和b的代码在这里.[code](./problems/i-largest.py).
如果先排序的话，就需要O(nlgn)+O(i)的时间.
用堆的话，需要O(n)+O(ilogn)的时间.

对于c，[code](./problems/i-largest.cpp)
利用顺序统计量的话，找到这个值需要O(n)的时间，然后需要对i个数排序需要O(ilogi)时间.


### Problems 2 : Weighted median
***
For n distinct elements ![](http://latex.codecogs.com/gif.latex?x_1,%20x_2,%20...,%20x_n) with positive weights ![](http://latex.codecogs.com/gif.latex?w_1,%20w_2,%20...,%20w_n) such that 
![](http://latex.codecogs.com/gif.latex?\\sum_{i=1}^{n}w_i%20=%201)
,**the weighted (lower)** median is the element ![](http://latex.codecogs.com/gif.latex?x_k) satisfying

![](http://latex.codecogs.com/gif.latex?\\sum_{x_i%20<%20x_k}w_i%20<%20\\frac{1}{2}%20%20%20%20%20)

and

![](http://latex.codecogs.com/gif.latex?\\sum_{x_i%20>%20x_k}w_i%20\\le%20\\frac{1}{2})

a. Argue that the median of x1, x2, ..., xn is the weighted median of the xi with weights wi = 1/n for i = 1,2, ..., n.

b. Show how to compute the weighted median of n elements in O(n lg n) worst-case time using sorting.

c. Show how to compute the weighted median in Θ(n) worst-case time using a linear- time median algorithm such as SELECT from Section 9.3.

The **post-office location problem** is defined as follows. We are given *n* points p1, p2, ..., pn with associated weights w1, w2, ..., wn. We wish to find a point p (not necessarily one of the input points) that minimizes the sum 

![](http://latex.codecogs.com/gif.latex?\\sum_{i%20=%201}^{n}w_id\(p,p_i\)%0d%0a)
where *d*(a, b) is the distance between points a and b.

d. Argue that the weighted median is a best solution for the 1-dimensional post-office location problem, in which points are simply real numbers and the distance between points a and b is *d*(a, b) = |a - b|.

e. Find the best solution for the 2-dimensional post-office location problem, in which the points are (x, y) coordinate pairs and the distance between points a = (x1, y1) and b = (x2, y2) is the **Manhattan distance** given by d(a, b) = |x1 - x2| + |y1 - y2|.


### `Answer`
a. 好显然TAT.

b. 先排序，然后开始遍历，直到加上某一个数字的权重 ≥ 1/2.

c. [code](./problems/weighted_median.py)

d. 假设p是带权中位数，只要偏离p,距离就会越来越大

e. 分别找x和y方向的带权中位数，因为用的是曼哈顿距离，x和y是独立的，所以可以分开对待.


### Problems 3 : Small order statistics
***
The worst-case number T(n) of comparisons used by SELECT to select the ith order statistic from n numbers was shown to satisfy T(n) = Θ(n), but the constant hidden by the Θ-notation is rather large. When i is small relative to n, we can implement a different procedure that uses SELECT as a subroutine but makes fewer comparisons in the worst case.

a. Describe an algorithm that uses Ui(n) comparisons to find the ith smallest of n elements, where
![image](./repo/p/o.png)(Hint: Begin with 
![](http://latex.codecogs.com/gif.latex?%20\\lfloor%20n/2%20\\rfloor%20)
disjoint pairwise comparisons, and recurse on the set containing the smaller element from each pair.)

b. Show that, if i < n/2, then Ui(n) = n + O(T (2i) lg(n/i)).

c. Show that if i is a constant less than n/2, then Ui(n) = n + O(lg n).

d. Show that if *i* = n/k for k≥2,then Ui(n) = n+O(T(2n/k)lgk).

### `Answer`
a. 
	1. 如果i ≥ n/2,直接调用SELECT(n, i)
	2. 如果i < n/2,那么就两个两个比较，生成了小的一组，同时也记录大的一组（比如可以用map映射起来）
	3. 对小的一组递归调用这个函数
	4. 当调用回来时，能找到这小的一组的第i个数，这个数左边都是比它小的数字，再从map中找到这i个数字对应的数字，这样总共有2i个数字，再对这2i个数字调用SELECT.
	很tricky的一点是为什么最后要调用T(2i),看下面这个数字[1,2,3,4],order-2是2，可是分组完后较小元素是[1,3],所以还要对另外i个数字进行比较.

b. 	![](http://latex.codecogs.com/gif.latex?%0d%0a%09U_i\(n\)%20=%20\\lfloor%20n/2%20\\rfloor%20%20+%20U_i\(\\lceil%20n/2%20\\rceil\)%20+%20T\(2i\)%20\\nonumber%20\\\\%20%20~%0d%0a\\hspace{16%20mm}%20=%20\\lfloor%20n/2%20\\rfloor%20%20+%20\\lceil%20n/2%20\\rceil%20+%20O\(T\(2i\)\\lg\(\\lfloor%20n/2%20\\rfloor%20/%20i\)\)+T\(2i\)%09%20\\\\%20%20~%0d%0a\\hspace{16%20mm}%20=%20n%20+%20O\(T\(2i\)\\lg\(n%20/%20i\)\)%20+%20T\(2i\)%20\\\\%20%20~%0d%0a\\hspace{16%20mm}=%20n%20+%20O\(T\(2i\)\\lg\(n%20/%20i\)\)%0d%0a)

c. ![](http://latex.codecogs.com/gif.latex?U_i\(n\)%20=%20n%20+%20O\(T\(2i\)\\lg\(n%20/%20i\)\)%20\\\\%20%20~\\hspace{16%20mm}%20=%20n%20+%20O\(O\(1\)\\lg\(n%20/%20i\)\)%20\\\\%20%20~%0d%0a\\hspace{16%20mm}%20=%20n%20+%20O\(\\lg\(n\)%20-%20\\lg\(i\)\)%20\\\\%20%20~%0d%0a\\hspace{16%20mm}%20=%20n%20+%20O\(\\lg\(n\)%20-%20O\(1\)\)%20\\\\%20%20~%0d%0a\\hspace{16%20mm}%20=%20n%20+%20O\(\\lg\(n\)\)%20\\\\%20%20~%0d%0a)

d. ![](http://latex.codecogs.com/gif.latex?U_i\(n\)%20=%20n%20+%20O\(T\(2i\)\\lg\(n%20/%20i\)\)%20\\\\%20%20%20%20%20%20%20~\\hspace{16%20mm}%20=%20n%20+%20O\(T\(2n/k\)\\lg\(n%20/%20\(n/k\)\)\)%20\\\\%20%20%20%20%20%20%20~%0d%0a\\hspace{16%20mm}%20=%20n%20+%20O\(T\(2n/k\)\\lg\(k\)\)%0d%0a)


***
Follow [@louis1992](https://github.com/gzc) on github to help finish this task
