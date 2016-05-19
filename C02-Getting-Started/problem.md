### Problems 1 : Insertion sort on small arrays in merge sort
***
Although merge sort runs in Θ(n lg n) worst-case time and insertion sort runs in Θ(n^2) worst- case time, the constant factors in insertion sort make it faster for small n. Thus, it makes sense to use insertion sort within merge sort when subproblems become sufficiently small. Consider a modification to merge sort in which n/k sublists of length k are sorted using insertion sort and then merged using the standard merging mechanism, where k is a value to be determined.

a. Show that the n/k sublists, each of length k, can be sorted by insertion sort in Θ(nk) worst-case time.

b. Show that the sublists can be merged in Θ(n lg (n/k) worst-case time.

c. Given that the modified algorithm runs in Θ(nk + n lg (n/k)) worst-case time, what is
the largest asymptotic (Θnotation) value of k as a function of n for which the modified
algorithm has the same asymptotic running time as standard merge sort?

d. How should k be chosen in practice?

### `Answer`
a. 总共有n/k个长度为k的列表，所以![](http://latex.codecogs.com/gif.latex?T\(n\) = n/k * \\Theta\(k^2\) = \\Theta\(nk\) )

b. 因为现在的层数为lg(n/k),所以是Θ(n lg (n/k))

c. 要么是Θ(nk) = Θ(nlgn),要么是Θ(nlg(n/k)) = Θ(nlgn).前者k = lgn,后者k = n^0.5.但是后者不成立，因为nk = n^1.5 > nlgn. 所以k = lgn.

d. [Exercise 1.2.2](https://github.com/gzc/CLRS/blob/master/C01-The-Role-of-Algorithms-in-Computing/1.2.md)当 n>43 mergesort 好于 insertion sort. 所以可以选40.



### Problems 2 : Correctness of bubblesort
***
Bubblesort is a popular sorting algorithm. It works by repeatedly swapping adjacent elements that are out of order.

### `Answer`
a. 我们还需要证明数组里面的元素就是原来的那些元素

b. **每次循环前，子数组A[j..]的最小元素是A[j]** <br />
Initialization:刚开始的时候，子数组只有一个元素，是A的最后一个元素，循环不变式自然成立 <br />
Maintenance:每个迭代，会比较A[j]和A[j-1]的大小，并把小的往前放 <br />
Termination:迭代结束时，j = i,A[i]是子数组A[i..]最小的元素 <br />

c. **每次循环前，A[1,i-1]是一个排序好的数组，且小于等于A[i..]中的元素**
Initialization:刚开始的时候，子数组为空，循环不变式自然成立 <br />
Maintenance:每个迭代，A[i]会变成A[i..]中的最小元素 <br />
Termination:迭代结束时，i = n, 我们获得了一个排序好的数组 <br />

d. **bubblesort**的最坏运行时间与**insertion sort**一样都是Θ(n^2)，但是一般来说**bubblesort**会慢点，因为它有许多的**swap**操作.


### Problems 3 : Correctness of Horner's rule
***
### `Answer`

**a.** Θ(n)

**b.**
Naive-Poly-Eval:

	y = 0
	for i = 0 to n
    	m = 1
    	for k = 1 to i
        	m = m·x
    	y = y + aᵢ·m
运行时间是Θ(n2),非常慢

**c.** 

**Initialization:** 一开始没有项，y = 0 

**Maintenance:**根据循环不变式，第i次迭代结束有

![](http://latex.codecogs.com/gif.latex? y = a_i + x\\sum_{k = 0}^{n-\(i+1\)}a_{k+i+1}x^k = 
a_ix^0 + \\sum_{k = 0}^{n-i-1}a_{k+i+1}x^{k+1} =
\\sum_{k = -1}^{n-i-1}a_{k+i+1}x^{k+1} =
\\sum_{k = 0}^{n-i}a_{k+i}x^k   )

**Termination:**循环结束时 i = -1, 将i = 0代入
![](http://latex.codecogs.com/gif.latex? y = \\sum_{k = 0}^{n}a_{k}x^k)

**d.**
前面已经证明了循环不变式，结论自然是成立的.


### Problems 4 : Inversions
***
Let A[1..n] be an array of n distinct numbers. If i < j and A[i] > A[j], then the pair (i, j) is called an inversion of A.

a. List the five inversions of the array 2, 3, 8, 6, 1.

b. What array with elements from the set {1, 2, . . . , n} has the most inversions? How
many does it have?

c. What is the relationship between the running time of insertion sort and the number of
inversions in the input array? Justify your answer.

d. Give an algorithm that determines the number of inversions in any permutation on n
elements in Θ(n lg n) worst-case time. (Hint: Modify merge sort.)

### `Answer`
**a.**
⟨2,1⟩, ⟨3,1⟩, ⟨8,6⟩, ⟨8,1⟩ 和 ⟨6,1⟩.

**b.**
数组[n,n-1,n-2,...,3,2,1]有最大的逆序数对. <br />
一共是(n-1) + (n-2) + …… + 3 + 2 + 1 = n(n-1)/2

**c.**
插入排序中移动元素的次数就是逆序数的对数.

设第i(1<=i<=n)个元素和它前面的元素构成逆序数的对数为k_i，k_1 + k_2 +...+ k_n = k

则插入排序的运行时间为Θ(n + k)

这是因为对于第i个元素，比较次数为初始的1次加上由于逆序导致的比较成功从而多出的k_i次

（对于第1个元素略有不同，但是影响的次数为常数，不影响渐进的阶）

**d.**
[code](./exercise_code/inversions.py)

[cppcode](./exercise code/inversions.cpp)

***
Follow [@louis1992](https://github.com/gzc) on github to help finish this task.

