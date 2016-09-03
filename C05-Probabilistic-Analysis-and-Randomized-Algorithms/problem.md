### Problems 1 : Probabilistic counting
***
With a b-bit counter, we can ordinarily only count up to 2b - 1. With R. Morris's probabilistic counting, we can count up to a much larger value at the expense of some loss of precision.￼￼￼￼￼￼￼￼￼￼￼
We let a counter value of i represent a count of ni for i = 0, 1,..., 2b -1, where the ni form an increasing sequence of nonnegative values. We assume that the initial value of the counter is 0, representing a count of n0 = 0. The INCREMENT operation works on a counter containing the value i in a probabilistic manner. If i = 2b - 1, then an overflow error is reported. Otherwise, the counter is increased by 1 with probability 1/(ni+1 - ni), and it remains unchanged with probability 1 - 1/(ni+1 - ni).
If we select ni = i for all i ≥ 0, then the counter is an ordinary one. More interesting situations arise if we select, say, ni = 2i-1 for i > 0 or ni = Fi (the ith Fibonacci number-see Section 3.2).
For this problem, assume that ￼n_(2^b-1) is large enough that the probability of an overflow error is negligible.
a. Show that the expected value represented by the counter after n INCREMENT operations have been performed is exactly n.
b. The analysis of the variance of the count represented by the counter depends on the sequence of the ni. Let us consider a simple case: ni = 100i for all i ≥ 0. Estimate the variance in the value represented by the register after n INCREMENT operations have been performed.

### `Answer`
**a.**
每一次递增操作增加的期望为

![](http://latex.codecogs.com/gif.latex? E = 0 \\cdot \(1-\\frac{1}{n_{i+1}-n_i}\) + 1\\cdot \(n_{i+1}-n_i\) \\cdot \\frac{1}{n_{i+1}-n_i} = 1 )

**b.**

![](http://latex.codecogs.com/gif.latex? X_j \\quad\\text {stands for jth increment} \\\\ Var[X_j] = E[X_j^2] - E^2[X_j] = \(0^2 \\cdot \\frac{99}{100} + 100^2\\cdot\\frac{1}{100}\) - 1^2 = 99 \\\\ 
Var[X] = \\sum_{i= 1}^{n}Var[X_i] = 99n)


### Problems 2 : Searching an unsorted array
***
Thus problem examines three algorithms for searching for a value x in an unsorted array A consisting of n elements.
Consider the following randomized strategy: pick a random index i into A. If A[i] = x, then we terminate; otherwise, we continue the search by picking a new random index into A. We continue picking random indices into A until we find an index j such that A[j] = x or until we have checked every element of A. Note that we pick from the whole set of indices each time, so that we may examine a given element more than once.
**a.** Write pseudocode for a procedure RANDOM-SEARCH to implement the strategy above. Be sure that your algorithm terminates when all indices into A have been picked.
**b.** Suppose that there is exactly one index i such that A[i] = x. What is the expected number of indices into A that must be picked before x is found and RANDOM- SEARCH terminates?
**c.** Generalizing your solution to part (b), suppose that there are k ≥ 1 indices i such that A[i] = x. What is the expected number of indices into A that must be picked before x is found and RANDOM-SEARCH terminates? Your answer should be a function of n and k.
**d.** Suppose that there are no indices i such that A[i] = x. What is the expected number of indices into A that must be picked before all elements of A have been checked and RANDOM-SEARCH terminates?
Now consider a deterministic linear search algorithm, which we refer to as DETERMINISTIC-SEARCH. Specifically, the algorithm searches A for x in order,￼considering A[1], A[2], A[3],..., A[n] until either A[i] = x is found or the end of the array is reached. Assume that all possible permutations of the input array are equally likely.
**e.** Suppose that there is exactly one index i such that A[i] = x. What is the expected running time of DETERMINISTIC-SEARCH? What is the worst-case running time of DETERMINISTIC-SEARCH?
**f.** Generalizing your solution to part (e), suppose that there are k ≥ 1 indices i such that A[i] = x. What is the expected running time of DETERMINISTIC-SEARCH? What is the worst-case running time of DETERMINISTIC-SEARCH? Your answer should be a function of n and k.
**g.** Suppose that there are no indices i such that A[i] = x. What is the expected running time of DETERMINISTIC-SEARCH? What is the worst-case running time of DETERMINISTIC-SEARCH?
Finally, consider a randomized algorithm SCRAMBLE-SEARCH that works by first randomly permuting the input array and then running the deterministic linear search given above on the resulting permuted array.
**h.** Letting k be the number of indices i such that A[i] = x, give the worst-case and expected running times of SCRAMBLE-SEARCH for the cases in which k = 0 and k = 1. Generalize your solution to handle the case in which k ≥ 1.
**i.** Which of the three searching algorithms would you use? Explain your answer.
### `Answer`
**a.**
	RANDOM-SEARCH(A, v):
		B = new array[n]
		count = 0
		while(count < n):
			r = RANDOM(1, n)
			if A[r] == v:
				return r
			if B[r] == false:
				count += 1
				B[r] = true
		return false
		
**b.**
就是几何分布～n

**c.**
还是几何分布～n/k

**d.**
Section5.4.2,在每个盒子里至少有一个球前，要投多少个球.

n(lnn+O(1))

**e.**
平均查找时间是n/2,最坏查找时间是n

**f.**
最坏运行时间是n-k+1.平均运行时间是n/(k+1)

**g.**
都是n

**h.**
跟DETERMINISTIC-SEARCH是一样的，这时候的期望就是平均.

**i.**
自然是**DETERMINISTIC-SEARCH**	


***
Follow [@louis1992](https://github.com/gzc) on github to help finish this task.

