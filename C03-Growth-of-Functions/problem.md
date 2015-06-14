### Problems 1 : Asymptotic behavior of polynomials
***


### `Answer`
显而易见.



### Problems 2 : Relative asymptotic growths
***
Indicate for each pair of expressions (A,B) in the table below, whether A is O, o, Ω, ω, or Θ of B. Assume that k≥1, ϵ>0, and c>1 are constants. Your answer should be in the form of the table with "yes" or "no" written in each box.

### `Answer`
A | B | O | o | Ω | ω | Θ 
:----:|:----:|:----:|:----:|:----:|:----:|:----:
![](http://latex.codecogs.com/gif.latex?\\lg^kn) | ![](http://latex.codecogs.com/gif.latex?n^\\epsilon) | yes | yes | no | no | no
![](http://latex.codecogs.com/gif.latex?\\n^k) | ![](http://latex.codecogs.com/gif.latex?c^n) | yes | yes | no | no | no
![](http://latex.codecogs.com/gif.latex?\\sqrt{n}) | ![](http://latex.codecogs.com/gif.latex?n^\\sin{n}) | no | no | no | no | no
![](http://latex.codecogs.com/gif.latex?\\2^n) | ![](http://latex.codecogs.com/gif.latex?2^{n/2}) | no | no | yes | yes | no
![](http://latex.codecogs.com/gif.latex?n^\\lg{c}) | ![](http://latex.codecogs.com/gif.latex?c^\\lg{n}) | yes | no | yes | no | yes
![](http://latex.codecogs.com/gif.latex?\\lg{\(n!\)}) | ![](http://latex.codecogs.com/gif.latex?\\lg{\(n^n\)}) | yes | no | yes | no | yes

### Problems 3 : Ordering by asymptotic growth rates
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
b. What array with elements from the set {1, 2, . . . , n} has the most inversions? Howmany does it have?
c. What is the relationship between the running time of insertion sort and the number ofinversions in the input array? Justify your answer.
d. Give an algorithm that determines the number of inversions in any permutation on nelements in Θ(n lg n) worst-case time. (Hint: Modify merge sort.)

### `Answer`
**a.**
⟨2,1⟩, ⟨3,1⟩, ⟨8,6⟩, ⟨8,1⟩ 和 ⟨6,1⟩.

**b.**
数组[n,n-1,n-2,...,3,2,1]有最大的逆序数对. <br />
一共是(n-1) + (n-2) + …… + 3 + 2 + 1 = n(n-1)/2

**c.**
插入排序中移动元素的次数就是逆序数的对数.

**d.**
[code](./exercise_code/inversions.py)

***
Follow [@louis1992](https://github.com/gzc) on github to help finish this task.

