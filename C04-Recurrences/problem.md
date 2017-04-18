### Problems 1 : Recurrence examples
***
Throughout this book, we assume that parameter passing during procedure calls takes constant time, even if an N-element array is being passed. This assumption is valid in most systems because a pointer to the array is passed, not the array itself. This problem examines the implications of three parameter-passing strategies:

1. An array is passed by pointer. Time = Θ(1).

2. An array is passed by copying. Time = Θ(N), where N is the size of the array.

3. An array is passed by copying only the subrange that might be accessed by the called
procedure. Time = Θ(q - p + 1) if the subarray A[p...q] is passed.


**a.** Consider the recursive binary search algorithm for finding a number in a sorted array (see Exercise 2.3-5). Give recurrences for the worst-case running times of binary search when arrays are passed using each of the three methods above, and give good upper bounds on the solutions of the recurrences. Let N be the size of the original problem and n be the size of a subproblem.

**b.** Redo part (a) for the MERGE-SORT algorithm from Section 2.3.1.

### `Answer`
1. Θ(n^4)

2. Θ(n)

3. Θ(n^2lgn)

4. Θ(n^2)

5. ![](http://latex.codecogs.com/gif.latex? \\Theta\(n^{\\log_{2}{7}}\) )

6. ![](http://latex.codecogs.com/gif.latex? \\sqrt{n} \\lg{n} )

7. Θ(n^3)



### Problems 2 : Finding the missing integer
***
An array A[1...n] contains all the integers from 0 to n except one. It would be easy to determine the missing integer in O(n) time by using an auxiliary array B[0...n] to record which numbers appear in A. In this problem, however, we cannot access an entire integer in A with a single operation. The elements of A are represented in binary, and the only operation we can use to access them is "fetch the jth bit of A[i]," which takes constant time.

Show that if we use only this operation, we can still determine the missing integer in O(n) time.

### `Answer`
* 00000
* 00001
* 00010
* 00011
* 00101
* 00110
* 00111
* 01000

[code](./exercise_code/findMissing.py)

我们用上面的8个数字当作例子，[0，8]缺4. <br \>

	1.第一次迭代发现最末位1出现4次0出现3次，所以missnum的最后一位是4，排除掉末位为1的数字
	2.然后一次次迭代

### Problems 3 : Parameter-passing costs

Throughout this book, we assume that parameter passing during procedure calls takes constant time, even if an N-element array is being passed. This assumption is valid in most systems because a pointer to the array is passed, not the array itself. This problem examines the implications of three parameter-passing strategies:


1. An array is passed by pointer. Time = Θ(1).


2. An array is passed by copying. Time = Θ(N), where N is the size of the array.


3. An array is passed by copying only the subrange that might be accessed by the calledprocedure. Time = Θ(q - p + 1) if the subarray A[p...q] is passed.

**a.** Consider the recursive binary search algorithm for finding a number in a sorted array (see Exercise 2.3-5). Give recurrences for the worst-case running times of binary search when arrays are passed using each of the three methods above, and give good upper bounds on the solutions of the recurrences. Let N be the size of the original problem and n be the size of a subproblem.

**b.** Redo part (a) for the MERGE-SORT algorithm from Section 2.3.1.


### `Answer`

**a.** <br \>

1. T(n) = T(n/2) + 2, O(lgN)

2. T(n) = T(n/2) + N, O(NlgN)

3. T(n) = T(n/2) + n, O(N)


**b.** <br />

1. T(n) = 2T(n/2) + n + 2, O(NlgN)

2. T(n) = 2T(n/2) + n + 2N, O(2^{lgN})

3. T(N) = 2T(n/2) + n + 2n, O(Nlg^**2**N)


### Problems 4 : More recurrence examples

**a.** <br \>
![](http://latex.codecogs.com/gif.latex? T\(n\) = 3T\(n/2\) + \\lg{n} \\\\ 
by~applying~master~method~\\Theta\(n^{\\log_3{4}}\)) 
***
**b.** <br \>
![](http://latex.codecogs.com/gif.latex? T\(n\) = 5T\(n/5\) + n/\\lg{n} \\\\
T\(n\) = 5T\(n/5\) + \\frac{n}{\\lg{n}} = 25T\(n/25\) + 5\\frac{n/5}{\\lg\(n/5\)} + \\frac{n}{\\lg{n}} = 25T\(n/25\) + \\frac{n}{\\lg{n}-\\lg{5}} + \\frac{n}{\\lg{n}} = nT\(1\)+\\sum_{i = 0}^{\\lg{n}-1}\\frac{n}{\\lg{n}-i\\lg{5}}  = nT\(1\)+n\\sum_{i = 1}^{\\lg{n}}\\frac{1}{\\lg{n}} = \\Theta\(n\\lg{\\lg{n}}\)) 
***
**c.** <br \>
![](http://latex.codecogs.com/gif.latex? T\(n\) = 4T\(n/2\)+n^2\\sqrt{n} \\\\
by ~applying~master~method~ \\Theta\(n^2\\sqrt{n}\) )
***
**d.** <br \>
![](http://latex.codecogs.com/gif.latex? T\(n\) = 3T\(n/3+5\) + n/2 \\\\
by ~applying~master~method~ \\Theta\(n\\lg{n}\) 
)
***
**e.** <br \>
The same as b
***
**f.** <br \>
![](http://latex.codecogs.com/gif.latex? T\(n\) = T\(n/2\) + T\(n/4\) + T\(n/8\) + n\\\\
Let's ~ guess ~ \\Theta\(n\) \\\\
T\(n\) = cn/2 + cn/4 + cn/8 \\le cn = O\(n\) \\\\
T\(n\) = cn/2 + cn/4 + cn/8 \\ge cn = \\Omega\(n\)
)
***
**g.** <br \>
![](http://latex.codecogs.com/gif.latex? T\(n\) = T\(n-1\) + 1/n \\\\
T\(n\) = \\sum_{i = 1}^{n}\\frac{1}{i} = \\Theta\(lg{n}\)
)
***
**h.** <br \>
![](http://latex.codecogs.com/gif.latex? T\(n\) = T\(n-1\) + \\lg{n} \\\\
T\(n\) = \\sum_{i=1}^{n}\\lg{i} = \\lg{n!} = \\Theta\(n\\lg{n}\) ~ remember ~we ~prove ~it ~in ~section~1
)
***
**i.** <br \>
![](http://latex.codecogs.com/gif.latex? T\(n\) = T\(n-2\) + 2\\lg{n} ~ The ~same
)
***
**j.** <br \>
![](http://latex.codecogs.com/gif.latex? T\(n\) = \\sqrt{n}T\(\\sqrt{n}\)+n \\\\
Let's ~ guess ~ \\Theta\(cn\\lg{\\lg{n}}\) \\\\
T\(n\) \\le \\sqrt{n}c\\sqrt{n}\\lg{\\lg{\\sqrt{n}}}+n \\\\
= cn\\lg{\\lg{\\sqrt{n}}}+n \\\\
= cn\\lg{\\frac{\\lg{n}}{2}}+n \\\\
= cn\\lg{\\lg{n}} - cn\\lg{2}+n \\\\
= cn\\lg{\\lg{n}} + \(1-c\)n    \\\\
\\le cn\\lg{\\lg{n}} ~~~~~~~~~ if ~ c > 1 \\\\
= \\Theta\(cn\\lg{\\lg{n}}\)
)


### Problems 5 : Fibonacci numbers
***
This problem develops properties of the Fibonacci numbers, which are defined by recurrence (3.21). We shall use the technique of generating functions to solve the Fibonacci recurrence. Define the generating function (or formal power series) F as

![](http://latex.codecogs.com/gif.latex? \\mathcal{F}\(z\) = \\sum_{i=0}^{\\infty}F\_iz^i \\\\
= 0 + z + z^2 + 2z^3 + 3z^4 + 5z^5 + 8z^6 + 13z^7 + 21z^8 + \\ldots \\\\
where~ F_i ~is ~the~ ith ~Fibonacci~ number.)

a. Show that ![](http://latex.codecogs.com/gif.latex? \\mathcal{F}\(z\) = z + z\mathcal{F}\(z\) + z^2\mathcal{F}\(z\))

b. Show that ![](http://latex.codecogs.com/gif.latex? \\mathcal{F}\(z\) = \\frac{z}{1-z-z^2} = \\frac{z}{\(1-\\phi{z}\)\(1-\\widehat\\phi{z}\)} = \\frac{1}{\\sqrt{5}}\(\\frac{1}{1-\\phi{z}}-\\frac{1}{1-\\widehat\\phi{z}}\)
)

c. Show that Show that ![](http://latex.codecogs.com/gif.latex? \\mathcal{F}\(z\) = \\sum_{i=0}^{\\infty}\\frac{1}{\\sqrt{5}}\(\\phi^i - \\widehat\\phi^i\)z^i )

d. Prove that ![](http://latex.codecogs.com/gif.latex? \\mathcal{F}\(z\) = \\phi^i/\\sqrt{5}) for i > 0 , rounded to the nearest integer.

e. Prove that ![](http://latex.codecogs.com/gif.latex? F_{i+2} \\ge \\phi i) for i ≥ 0.

### `Answer`
**a.**

![](http://latex.codecogs.com/gif.latex? z + z\mathcal{F}\(z\) + z^2\mathcal{F}\(z\) \\\\
= z + z\\sum_{i=0}^{\\infty}F\_iz^i + z^2\\sum_{i=0}^{\\infty}F\_iz^i \\\\
= z + z\\sum_{i=1}^{\\infty}F\_{i-1}z^i + z^2\\sum_{i=2}^{\\infty}F\_{i-2}z^i \\\\
= z + F_1z + \\sum_{i=2}^{\\infty}\(F_{i-1}+F_{i-2}\)z^i \\\\
= z + F_1z + \\sum_{i=2}^{\\infty}F_iz^i \\\\
= \\mathcal{F}\(z\))

**b.**
这个结论的证明还是很straight-forward的，就不写公式啦.

**c.**

![](http://latex.codecogs.com/gif.latex? 
\\quad\\text{First, we have } \\frac{1}{1 - x} = \\sum_{k=0}^{\\infty}x^k \\quad\\text{when } |x| < 1 \\\\
\\mathcal{F}\(n\) = \\frac{1}{\\sqrt5}\\Big\(\\frac{1}{1 - \\phi z} - \\frac{1}{1 - \\hat\\phi z}\\Big\) = \\frac{1}{\\sqrt5}\\Big\(\\sum_{i=0}^{\\infty}\\phi^i z^i - \\sum_{i=0}^{\\infty}\\hat{\\phi}^i z^i\\Big\)= \\sum_{i=0}^{\\infty}\\frac{1}{\\sqrt5}\(\\phi^i - \\hat{\\phi}^i\) z^i
)

**d.**

![](http://latex.codecogs.com/gif.latex?
\\mathcal{F}\(z\) = \\sum_{i=0}^{\\infty}\\alpha_iz^i \\quad\\text{ where } \\alpha_i = \\frac{\\phi^i - \\hat{\\phi}^i}{\\sqrt5} \\\\
\\quad\\text{ so we have } \\alpha_i = F_i \\\\
F_i = \\frac{\\phi^i - \\hat{\\phi}^i}{\\sqrt5}  = \\frac{\\phi^i}{\\sqrt5} - \\frac{\\hat{\\phi}^i}{\\sqrt5} \\\\
\\quad\\text{because } |\\hat\\phi| < 1 \\quad\\text{, so } \\frac{|\\hat\\phi^i|}{\\sqrt{5}} < 0.5
)

**e.**
[we had prove it previously](https://github.com/gzc/CLRS/blob/master/C03-Growth-of-Functions/3.2.md#exercises-32-7)

### Problems 6 : VLSI chip testing
***
Professor Diogenes has n supposedly identical VLSI[1] chips that in principle are capable of testing each other. The professor's test jig accommodates two chips at a time. When the jig is loaded, each chip tests the other and reports whether it is good or bad. A good chip always reports accurately whether the other chip is good or bad, but the answer of a bad chip cannot be trusted. Thus, the four possible outcomes of a test are as follows:

Chip A says | Chip B says | Conclusion
:----:|:----:|:----:
￼￼B is good | A is good | both are good, or both are bad
B is good | A is bad | at least one is bad
B is bad | A is good | at least one is bad
B is bad | A is bad | at least one is bad


a. Show that if more than n/2 chips are bad, the professor cannot necessarily determine which chips are good using any strategy based on this kind of pairwise test. Assume that the bad chips can conspire to fool the professor.

b. Consider the problem of finding a single good chip from among n chips, assuming that
more than n/2 of the chips are good. Show that ⌊n/2⌋ pairwise tests are sufficient to
reduce the problem to one of nearly half the size.

c. Show that the good chips can be identified with Θ(n) pairwise tests, assuming that
more than n/2 of the chips are good. Give and solve the recurrence that describes the number of tests.


### `Answer`
a. 如果超过一半是坏的，那么我们可以从这些坏的中取出一组数量和好的一样多的，他们的表现能和好的一样.

b. 将所有的芯片两两配对，如果报告是both are good or bad,那么就从中随机选一个留下来，否则全部扔掉. 一直这样递归下去，最后剩下的是好的.

c. T(n) = T(n/2)+n/2,是Θ(n)的.


### Problems 7 : Monge arrays
***
An m × n array A of real numbers is a **Monge array** if for all i, j, k, and l such that 1 ≤ i < k ≤ m and 1 ≤ j < l ≤ n, we have

A[i, j] + A[k, l] ≤ A[i, l] + A[k, j].

In other words, whenever we pick two rows and two columns of a Monge array and consider the four elements at the intersections of the rows and the columns, the sum of the upper-left and lower-right elements is less or equal to the sum of the lower-left and upper-right elements. For example, the following array is Monge:

![](http://latex.codecogs.com/gif.latex?  \\begin{matrix}
   10 & 17 & 13 & 28 & 23 \\\\
   17 & 22 & 16 & 29 & 23 \\\\
   24 & 28 & 22 & 34 & 24 \\\\
   11 & 13 &  6 & 17 &  7 \\\\
   45 & 44 & 32 & 37 & 23 \\\\
   36 & 33 & 19 & 21 &  6 \\\\
   75 & 66 & 51 & 53 & 34
   \\end{matrix})
   
a. Prove that an array is Monge if and only if for all i = 1,2,...,m-1 and j = 1,2,...,n- 1, we have <br \>
A[i, j] + A[i + 1, j + 1] ≤ A[i, j + 1] + A[i + 1, j]. <br \>
Note (For the "only if" part, use induction separately on rows and columns.)


b. The following array is not Monge. Change one element in order to make it Monge.
![](http://latex.codecogs.com/gif.latex?  \\begin{matrix}
   37 & 23 & 22 & 72  \\\\
   21 & 6 & 7 & 10  \\\\
   53 & 34 & 30 & 31 \\\\
   32 & 13 &  9 & 6  \\\\
   43 & 21 & 15 & 8  \\\\
   \\end{matrix})
   
   
c. Let f(i) be the index of the column containing the leftmost minimum element of row i. Prove that f(1) ≤ f(2) ≤ ··· ≤ f(m) for any m × n Monge array.

d. Here is a description of a divide-and-conquer algorithm that computes the left-most minimum element in each row of an m × n Monge array A: <br \>
Construct a submatrix A′ of A consisting of the even-numbered rows of A. Recursively determine the leftmost minimum for each row of A′. Then compute the leftmost minimum in the odd-numbered rows of A. <br \>
Explain how to compute the leftmost minimum in the odd-numbered rows of A (given that the leftmost minimum of the even-numbered rows is known) in O(m + n) time.


e. Write the recurrence describing the running time of the algorithm described in part (d). Show that its solution is O(m + n log m).

### `Answer`
**a.**

![](http://latex.codecogs.com/gif.latex? 
A[i, j] + A[k, l] \\le A[i, l] + A[k, j]
   \\ \xrightarrow[k = i+1]{l = j+1}
   A[i,j] + A[i+1, j+1] \\le A[i, j+1] + A[i+1,j])
***
![](http://latex.codecogs.com/gif.latex?   \\quad\\text{assume } A[i,j]+A[k,j+1] \\le A[i,j+1]+A[k,j] \\\\
\\quad\\text{to prove }   A[i,j]+A[k+1,j+1] \\le A[i,j+1]+A[k+1,j] \\\\ \\\\
A[k,j]+A[k+1,j+1] \\le A[k,j+1]+A[k+1,j] \\\\
\\rightarrow A[i, j] + A[k, j+1] + A[k, j] + A[k+1, j+1] \\le
   A[i, j+1] + A[k, j] + A[k, j+1] + A[k+1, j] \\\\
   \\rightarrow \\
   A[i, j] + A[k+1, j+1] \\le A[i, j+1] + A[k+1, j])
   
**b.**

![](http://latex.codecogs.com/gif.latex?  \\begin{matrix}
   37 & 23 & \\textbf{24} & 72  \\\\
   21 & 6 & 7 & 10  \\\\
   53 & 34 & 30 & 31 \\\\
   32 & 13 &  9 & 6  \\\\
   43 & 21 & 15 & 8  \\\\
   \\end{matrix})
   
**c.** **反证法**

如果i < j,f(i) >= f(j)

A[i,f(j)]+A[j,f(i))] <= A[i,f(i)]+A[j,f(j)] 但是A[i,f(i)]和A[j,f(j)]是两行最小的元素，等式不成立.

**d.**根据c可以知道第i行的左端最小值落在f(i-1)和f(i+1)之间. 总共有n/2个奇数行，总共需要比较m次，所以是O(m+n).

**e.**
T(m) = T(m/2) + cn + dm = O(nlgm + m)

[code](./exercise_code/findIndex.py)



***
Follow [@louis1992](https://github.com/gzc) on github to help finish this task.

