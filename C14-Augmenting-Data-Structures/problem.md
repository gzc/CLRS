### Problems 1 : Point of Maximum Overlap
***
Suppose that we wish to keep track of a **point of maximum overlap** in a set of intervals—a point that has the largest number of intervals in the database overlapping it.

a. Show that there will always be a point of maximum overlap which is an endpoint of one of the segments.
b. Design a data structure that efficiently supports the operations INTERVAL-INSERT, INTERVAL-DELETE, and FIND-POM, which returns a point of maximum overlap. (Hint: Keep a red-black tree of all the endpoints. Associate a value of +1 with each left endpoint, and associate a value of -1 with each right endpoint. Augment each node of the tree with some extra information to maintain the point of maximum overlap.)

### `Answer`
**a.**

端点上的区间不会比其他地方的要少.

证明：假设点p被最多的区间覆盖，这些区间为I<sub>1</sub>, I<sub>2</sub>...I<sub>k</sub>, 其中I<sub>k</sub> = [l<sub>k</sub>, r<sub>k</sub>]. 由于点p被这些区间覆盖，则对任意i，有l<sub>i</sub> ≤ p ≤ r<sub>i</sub>. 下面证明存在一个区间端点，也同样被这些区间覆盖. 
取 l<sup>\*</sup> = max{l<sub>1</sub> .. l<sub>k</sub>}, 即这k个区间的左端点的最大值. 
由l<sup>\*</sup>的定义可知, 对任意i, 有l<sub>i</sub> ≤ l<sup>\*</sup> ≤ p. 另外，假设存在一个i, 使得r<sub>i</sub> < l<sup>\*</sup>, 则有l<sub>i</sub> ≤ r<sub>i</sub> < l<sup>\*</sup> ≤ p, 这与点p被区间[l<sub>i</sub>, r<sub>i</sub>]覆盖矛盾, 因此对任意i, 有l<sup>\*</sup> ≤ r<sub>i</sub>. 综上, l<sub>i</sub> ≤ l<sup>\*</sup> ≤ r<sub>i</sub>, 即端点l<sup>\*</sup>也被这k个区间覆盖, 原命题得证. ∎

**b.**

[stackoverflow](http://stackoverflow.com/questions/14780324/point-of-maximum-overlap)

a bit tricky!


down vote
accepted
quote:http://ripcrixalis.blog.com/2011/02/08/clrs-chapter-14/

Keep a RB-tree of all the endpoints. We insert endpoints one by one as a sweep line scaning from left to right. With each left endpoint e, associate a value p[e] = +1 (increasing the overlap by 1). With each right endpoint e associate a value p[e] = −1 (decreasing the overlap by 1). When multiple endpoints have the same value, insert all the left endpoints with that value before inserting any of the right endpoints with that value.

Here is some intuition. Let e1, e2, . . . , en be the sorted sequence of endpoints corresponding to our intervals. Let s(i, j) denote the sum p[ei] + p[ei+1] + · · · + p[ej] for 1 ≤ i ≤ j ≤ n. We wish to find an i maximizing s(1, i ). Each node x stores three new attributes. We store v[x] = s(l[x], r [x]), the sum of the values of all nodes in x’s subtree. We also store m[x], the maximum value obtained by the expression s(l[x], i) for any i. We store o[x] as the value of i for which m[x] achieves its maximum. For the sentinel, we define v[nil[T]] = m[nil[T]] = 0.

We can compute these attributes in a bottom-up fashion so as to satisfy the requirements of Theorem 14.1:

	v[x] = v[left[x]] + p[x] + v[right[x]] ,
	m[x] = max{
		m[left[x]] (max is in x’s left subtree),
		v[left[x]] + p[x] (max is at x),
		v[left[x]] + p[x] + m[right[x]] (max is in x’s right subtree). }
Once we understand how to compute m[x], it is straightforward to compute o[x] from the information in x and its two children.

FIND-POM: return the interval whose endpoint is represented by o[root[T]]. Because of how we have deÞned the new attributes, Theorem 14.1 says that each operation runs in O(lg n) time. In fact, FIND-POM takes only O(1) time.


### Problems 2 : Josephus Permutation
***
The Josephus problem is defined as follows. Suppose that n people are arranged in a circle and that we are given a positive integer m ≤ n. Beginning with a designated first person, we proceed around the circle, removing every mth person. After each person is removed, counting continues around the circle that remains. This process continues until all n people have been removed. The order in which the people are removed from the circle defines the (n, m)-Josephus permutation of the integers 1, 2,..., n. For example, the (7, 3)-Josephus permutation is [3, 6, 2, 7, 5, 1, 4].

a. Suppose that m is a constant. Describe an O(n)-time algorithm that, given an integer n, outputs the (n, m)-Josephus permutation.
b. Suppose that m is not a constant. Describe an O(n lg n)-time algorithm that, given integers n and m, outputs the (n, m)-Josephus permutation.


### `Answer`

**a.** 使用循环列表. [implementation](./exercise_code/m-Josephus.cpp)

**b.**

应用顺序统计量树(OST)。假设在某一轮中, 还剩下k个人，且被移除的其中的第j大的人. 则下一轮中, 被移除的是剩下的人中第(j + m -1)大的人，这里假设 j + m ≤ k, -1是因为第j大的人已被移除. 具体地,

1. k个排好序的人中, 第j大的人的编号是( (j-1)%k + 1 ). (假设编号从1开始, 且j可以为任意大的数).
2. 由上面分析可知, 若某一轮被移除的第j大的人, 则下一轮将要被移除的是第(j + m -1)大的, 代入上式, 可得下一轮被移除的是((j + m -2)%k + 1 ). 当然, 每一轮过后, k都要减一. 详见代码.

````
JOSEPHUS(n,m)
	initialize T to be empty
	for j ← 1 to n
		do create a node x with key[x] = j
			OS-INSERT(T, x)
	j ← 1
	for k ← n downto 1
		do j ← (( j + m − 2) mod k) + 1
			x ← OS-SELECT(root[T ], j )
			print key[x]
			OS-DELETE(T, x)
````
***
Follow [@louis1992](https://github.com/gzc) on github to help finish this task.

