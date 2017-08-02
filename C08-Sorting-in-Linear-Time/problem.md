### Problems 1 : Average-case lower bounds on comparison sorting
***
In this problem, we prove an Ω(n lg n) lower bound on the expected running time of any deterministic or randomized comparison sort on n distinct input elements. We begin by examining a deterministic comparison sort A with decision tree TA. We assume that every permutation of A's inputs is equally likely.
			   			   		
**a.** Suppose that each leaf of TA is labeled with the probability that it is reached given a random input. Prove that exactly n! leaves are labeled 1/n! and that the rest are labeled 0.

**b.** Let D(T) denote the external path length of a decision tree T ; that is, D(T) is the sum of the depths of all the leaves of T. Let T be a decision tree with k > 1 leaves, and let LT and RT be the left and right subtrees of T. Show that D(T) = D(LT) + D(RT) + k.

**c.** Let d(k) be the minimum value of D(T) over all decision trees T with k > 1 leaves. Show that

![](http://latex.codecogs.com/gif.latex?%0d%0ad\(k\)%20=%20\\min_{1%20\\le%20i%20\\le%20k-1}\\{d\(i\)%20+%20d\(k-i\)%20+%20k\\}%20)

(Hint: Consider a decision tree T with k leaves that achieves the minimum. Let i0 be the number of leaves in LT and k - i0 the number of leaves in RT.)

**d.** Prove that for a given value of k > 1 and i in the range 1 ≤ i ≤ k-1,the function ilgi+ (k - i)lg(k - i) is minimized at i = k/2. Conclude that d(k) = Θ(klgk).

The PARTITION procedure in Section 7.1 separates the pivot value (originally in A[r]) from the two partitions it forms. The HOARE-PARTITION procedure, on the other hand, always places the pivot value (originally in A[p]) into one of the two partitions A[p...j] and A[j + 1...r]. Since p ≤ j < r, this split is always nontrivial.

**e.** Prove that D(TA) = Θ(n! lg(n!)), and conclude that the expected time to sort n elements is Θ(n lg n).

Now, consider a randomized comparison sort B. We can extend the decision-tree model to handle randomization by incorporating two kinds of nodes: ordinary comparison nodes and "randomization" nodes. A randomization node models a random choice of the form RANDOM(1, r) made by algorithm B; the node has r children, each of which is equally likely to be chosen during an execution of the algorithm.

**f.** Show that for any randomized comparison sort B, there exists a deterministic comparison sort A that makes no more comparisons on the average than B does.


### `Answer`
**a.**

总共有n!个排列，也就是n!种可能，所以概率当然是1/n!.

**b.**

因为T比RT和LT高度少1，所以有多少叶子节点，就需要多加这么多个1.很好思考～

**c.**

由前一小题可知，有k个节点的树有关系式D(T)=D(LT)+D(RT)+k.

那么很自然可以知道，就是左子树的叶子节点从1到k-1这么多可能.

![](http://latex.codecogs.com/gif.latex?%0d%0ad\(k\)%20=%20D\(T\)%20=%20D\(LT\)%20+%20D\(RT\)%20+%20k%20=%20\\min_{1%20\\le%20i%20\\le%20k-1}\\{d\(i\)%20+%20d\(k-i\)%20+%20k\\}%20)

**d.**

比较简单的求导.

![](http://latex.codecogs.com/gif.latex?%0d%0af\(i\)%20=%20i\\lg{i}%20+%20\(k-i\)\\lg\(k-i\)%20\\\\%20~%20\\hspace{6%20mm}%0d%0a%20%20%20%20%20f'\(i\)%20=%20\\lg{i}%20+%201%20-%20\\lg\(k-i\)%20-%201%20=%20\\lg\\frac{i}{k-i}%20\\\\%20~%20\\hspace{6%20mm}%0d%0a%20%20%20%20%20f'\(i\)%20=%200%20%20\\Leftrightarrow%20\\lg\\frac{i}{k-i}%20=%200%20\\Rightarrow%20i/\(k-i\)%20=%201%20\\Rightarrow%20i%20=%20\\frac{k}{2}%20)

**e.**

TA一共有n!个叶子节点，所以有D(T) > d(n!) = Ω(n!lg(n!))

我们已经求出了外路径长度，总共有n!个概率相同的节点,所以最终有

![](http://latex.codecogs.com/gif.latex?%0d%0a\\frac{\\Omega\(n!\\lg\(n!\)\)}{n!}%20=%20\\Omega\(\\lg\(n!\)\)%20=%20\\Omega\(n\\lg{n}\)%20)

**f.**
非随机化版本有n!种路径，囊括了所有可能. 而任何一种随机化都肯定在这n!里面，而且少了random的操作.


### Problems 2 : Sorting in place in linear time
***
Suppose that we have an array of n data records to sort and that the key of each record has the value 0 or 1. An algorithm for sorting such a set of records might possess some subset of the following three desirable characteristics:


1. The algorithm runs in O(n) time.

2. The algorithm is stable.

3. The algorithm sorts in place, using no more than a constant amount of storage space in addition to the original array.

**a.** Give an algorithm that satisfies criteria 1 and 2 above.

**b.** Give an algorithm that satisfies criteria 1 and 3 above.

**c.** Give an algorithm that satisfies criteria 2 and 3 above.

**d.**
Can any of your sorting algorithms from parts (a)-(c) be used to sort n records with b- bit keys using radix sort in O(bn) time? Explain how or why not.

**e.**

Suppose that the n records have keys in the range from 1 to k. Show how to modify counting sort so that the records can be sorted in place in O(n + k) time. You may use O(k) storage outside the input array. Is your algorithm stable? (Hint: How would you do it for k = 3?)


### `Answer`
**a.** 

计数排序就可以.

**b.**

Using HOARE-PARTITION can do it.More details in [Exercise7.1](https://github.com/gzc/CLRS/blob/master/C07-Quicksort/7.1.md)

**c.**

merge-sort就可以

[stable in-place sort](http://www.codeproject.com/Articles/26048/Fastest-In-Place-Stable-Sort)

**d.**

1. The first one can be used.
2. The second is not stable.
3. The third takes `Theta(nlgn)`.
   
**e.**

[implementation](./exercise_code/in_place_counting_sort.py)

我的实现不是stable的


### Problems 3 : Sorting variable-length items
***
a. You are given an array of integers, where different integers may have different numbers of digits, but the total number of digits over all the integers in the array is n. Show how to sort the array in O(n) time.

b. You are given an array of strings, where different strings may have different numbers of characters, but the total number of characters over all the strings is n. Show how to sort the strings in O(n) time.

(Note that the desired order here is the standard alphabetical order; for example, a < ab < b.)
	
### `Answer`

**a.**

For the nubers, we can do this:

- Group the nunbers by number of digits and order  groups.
- RADIX sort each group.
    
We let the `Gi` be the group of numbers with i digits and ci = |Gi|, thus: we can multiply the `n*Ci` with `i`, then sum from `i = 1` to `i = highest digit`. We can get the 

![](http://latex.codecogs.com/gif.latex?T\(n\)=%20\\sum_{i%20=%201}nc_i%20\\cdot%20i%20=%20n%20)


**b.**

reverse所有的字符串，用RADIX-SORT.当当遍历到某一个字符串超过其大小时,用空格代替(空格 > 其他字母),并且将该数字放在该组正常有数字的前面，以后不要迭代.排序后reverse回来. 保证了O(n)的时间.
 
假设我们要排序字符串d,c,b,bcd,bc,bd,bdc.过程如下:


0 | 1 | 2 | 3 | 4 | result | reverse
:----: | :----: | :----: | :----: | :----: | :----: | :----:
d | **b** | b |  |  | b | b 
c | dc**b** | d**c**b | cb | | cb | bc
b | c**b** | **c**b | **d**cb | dcb | dcb | bcd
dcb | d**b** | **d**b | db | | db | bd
cb | cd**b** | c**d**b | **c**db | cdb |cdb | bdc
db | **c** | c | | | c | c
cdb | **d** | d | | | d | d

### Problems 4 : Water jugs
***
Suppose that you are given n red and n blue water jugs, all of different shapes and sizes. All red jugs hold different amounts of water, as do the blue ones. Moreover, for every red jug, there is a blue jug that holds the same amount of water, and vice versa.
It is your task to find a grouping of the jugs into pairs of red and blue jugs that hold the same amount of water. To do so, you may perform the following operation: pick a pair of jugs in which one is red and one is blue, fill the red jug with water, and then pour the water into the blue jug. This operation will tell you whether the red or the blue jug can hold more water, or if they are of the same volume. Assume that such a comparison takes one time unit. Your goal is to find an algorithm that makes a minimum number of comparisons to determine the grouping. Remember that you may not directly compare two red jugs or two blue jugs.

a. Describe a deterministic algorithm that uses Θ(n2) comparisons to group the jugs into pairs.

b. Prove a lower bound of Θ(n lg n) for the number of comparisons an algorithm solving this problem must make.

c. Give a randomized algorithm whose expected number of comparisons is O(n lg n), and prove that this bound is correct. What is the worst-case number of comparisons for your algorithm?

### `Answer`
**a.**

二重循环，比较所有的.

**b.**

决策树的每个node都有3个sub-node(A < B | A = B | A > B).总共有n!个输出.所以有

![](http://latex.codecogs.com/gif.latex?3^h%20\\ge%20n!%20\\Rightarrow%20h%20\\ge%20\\lg{n!}%20\\Rightarrow%20h%20=%20\\Omega\(n\\lg{n}\))

**c.**

key idea : 跟快速排序是一样的

[implementation](./exercise_code/water-jugs.py)


### Problems 5 : Average sorting
***
Suppose that, instead of sorting an array, we just require that the elements increase on average. More precisely, we call an n-element array A k-sorted if, for all i = 1, 2, . . ., n - k, the following holds:

![](http://latex.codecogs.com/gif.latex?%20\\frac{\\sum_{j%20=%20i}^{i+k-1}}{k}A[j]%20\\le%20\\frac{\\sum_{j%20=%20i+1}^{i+k}}{k}A[j])

**a.** What does it mean for an array to be 1-sorted?

**b.** Give a permutation of the numbers 1, 2, . . ., 10 that is 2-sorted, but not sorted.

**c.** Provethatann-elementarrayisk-sortedifandonlyifA[i]≤A[i+k]foralli=1,2,..
., n - k.

**d.** Give an algorithm that k-sorts an n-element array in O(n lg(n/k)) time.

**e.** Show that a k-sorted array of length n can be sorted in O(n lg k) time. (Hint: Use the solution to Exercise 6.5-8.)

**f.** Show that when k is a constant, it requires Θ(n lg n) time to k-sort an n-element array. (Hint: Use the solution to the previous part along with the lower bound on comparison sorts.)

### `Answer`
**a.**

该数组完全排好序.

**b.**

[2,1,3,4,5,6,7,8,9,10]
 
**c.**

这个证明很简单，移项就能得到.

**d.**

把数组分为k组，用heapsort/mergesort.

T = k * O((n/k)log(n/k)) = O(nlg(n/k)) 

**e.**

确实跟[练习6.5.8](https://github.com/gzc/CLRS/blob/master/C06-Heapsort/6.5.md#exercises-65-8)是一样的

**f.**

我们有d的结果，因为k是常量，所以可以忽略.

### Problems 6 : Lower bound on merging sorted lists
***

The problem of merging two sorted lists arises frequently. It is used as a subroutine of MERGE-SORT, and the procedure to merge two sorted lists is given as MERGE in Section 2.3.1. In this problem, we will show that there is a lower bound of 2n - 1 on the worst-case number of comparisons required to merge two sorted lists, each containing n items.

First we will show a lower bound of 2n - o(n) comparisons by using a decision tree.

**a.** Show that, given 2n numbers, there are ￼![](http://latex.codecogs.com/gif.latex?C_{2n}^n) possible ways to divide them into two sorted lists, each with n numbers.

**b.** Using a decision tree, show that any algorithm that correctly merges two sorted lists uses at least 2n - o(n) comparisons.

Now we will show a slightly tighter 2n - 1 bound.

**c.** Show that if two elements are consecutive in the sorted order and from opposite lists, then they must be compared.

**d.** Use your answer to the previous part to show a lower bound of 2n - 1 comparisons for merging two sorted lists.


### `Answer`

这个题目在[leetcode](https://leetcode.com/problems/merge-two-sorted-lists/)出现过

**a.**

很自然，从2n数字中可以选n种.

**b.**

![](http://latex.codecogs.com/gif.latex?%202^h%20\\ge%20%20C_{2n}^n%20\\\\%20~%20\\hspace{6%20mm}%0d%0a2^h%20\\ge%20\\frac{2n!}{\(n!\)^2}%20%20\\\\%20~%20\\hspace{8%20mm}%0d%0ah%20\\ge%20\\log{2n!}%20-2\\log{n!}%20\\\\%20~%20\\hspace{10%20mm}%0d%0a=%20\\Theta\(2n\\log{2n}\)%20-%202\\Theta\(n\\log{n}\)%20\\\\~%20\\hspace{10%20mm}%0d%0a=%20\\log{2}\\Theta\(2n\)%20\\\\~%20\\hspace{10%20mm}%0d%0a=%20\\Theta\(2n\))

树的高度是2n级别的，因此最少需要2n-o(n)次

**c.**

这不是废话嘛...只有来自同一列表的前后元素才不用比较.

**d.**

根据c,在已排号序的链表中，只有前后元素才有**可能**比较过，因此最多是2n-1次.
 
***
Follow [@louis1992](https://github.com/gzc) on github to help finish this task.

