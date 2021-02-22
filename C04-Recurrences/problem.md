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

5. ![](http://latex.codecogs.com/gif.latex?%20\\Theta\(n^{\\log_{2}{7}}\)%20)

6. ![](http://latex.codecogs.com/gif.latex?%20\\sqrt{n}%20\\lg{n}%20)

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

1. ![](http://latex.codecogs.com/gif.latex?T%28n%29%20%3D%202T%28%5Cfrac%7Bn%7D%7B2%7D%29%20&plus;%20n%20&plus;%202%2C%20O%28NlgN%29)

2. ![](http://latex.codecogs.com/gif.latex?T%28n%29%20%3D%202T%28%5Cfrac%7Bn%7D%7B2%7D%29%20&plus;%20n%20&plus;%202N%2C%20%5CTheta%282%5E%7Blg%7BN%7D%7DN%29%20%3D%20%5CTheta%28N%5E2%29)

3. ![](http://latex.codecogs.com/gif.latex?T%28N%29%20%3D%202T%28%5Cfrac%7Bn%7D%7B2%7D%29%20&plus;%20n%20&plus;%202n%2C%20O%28NlgN%29)


### Problems 4 : More recurrence examples

**a.** <br \>
![](http://latex.codecogs.com/gif.latex?%20T\(n\)%20=%203T\(n/2\)%20+%20\\lg{n}%20\\\\%20%0d%0aby~applying~master~method~\\Theta\(n^{\\log_3{4}}\)) 
***
**b.** <br \>
![](http://latex.codecogs.com/gif.latex?%20T\(n\)%20=%205T\(n/5\)%20+%20n/\\lg{n}%20\\\\%0d%0aT\(n\)%20=%205T\(n/5\)%20+%20\\frac{n}{\\lg{n}}%20=%2025T\(n/25\)%20+%205\\frac{n/5}{\\lg\(n/5\)}%20+%20\\frac{n}{\\lg{n}}%20=%2025T\(n/25\)%20+%20\\frac{n}{\\lg{n}-\\lg{5}}%20+%20\\frac{n}{\\lg{n}}%20=%20nT\(1\)+\\sum_{i%20=%200}^{\\lg{n}-1}\\frac{n}{\\lg{n}-i\\lg{5}}%20%20=%20nT\(1\)+n\\sum_{i%20=%201}^{\\lg{n}}\\frac{1}{\\lg{n}}%20=%20\\Theta\(n\\lg{\\lg{n}}\)) 
***
**c.** <br \>
![](http://latex.codecogs.com/gif.latex?%20T\(n\)%20=%204T\(n/2\)+n^2\\sqrt{n}%20\\\\%0d%0aby%20~applying~master~method~%20\\Theta\(n^2\\sqrt{n}\)%20)
***
**d.** <br \>
![](http://latex.codecogs.com/gif.latex?%20T\(n\)%20=%203T\(n/3+5\)%20+%20n/2%20\\\\%0d%0aby%20~applying~master~method~%20\\Theta\(n\\lg{n}\)%20%0d%0a)
***
**e.** <br \>
The same as b
***
**f.** <br \>
![](http://latex.codecogs.com/gif.latex?%20T\(n\)%20=%20T\(n/2\)%20+%20T\(n/4\)%20+%20T\(n/8\)%20+%20n\\\\%0d%0aLet's%20~%20guess%20~%20\\Theta\(n\)%20\\\\%0d%0aT\(n\)%20=%20cn/2%20+%20cn/4%20+%20cn/8%20\\le%20cn%20=%20O\(n\)%20\\\\%0d%0aT\(n\)%20=%20cn/2%20+%20cn/4%20+%20cn/8%20\\ge%20cn%20=%20\\Omega\(n\)%0d%0a)
***
**g.** <br \>
![](http://latex.codecogs.com/gif.latex?%20T\(n\)%20=%20T\(n-1\)%20+%201/n%20\\\\%0d%0aT\(n\)%20=%20\\sum_{i%20=%201}^{n}\\frac{1}{i}%20=%20\\Theta\(lg{n}\)%0d%0a)
***
**h.** <br \>
![](http://latex.codecogs.com/gif.latex?%20T\(n\)%20=%20T\(n-1\)%20+%20\\lg{n}%20\\\\%0d%0aT\(n\)%20=%20\\sum_{i=1}^{n}\\lg{i}%20=%20\\lg{n!}%20=%20\\Theta\(n\\lg{n}\)%20~%20remember%20~we%20~prove%20~it%20~in%20~section~1%0d%0a)
***
**i.** <br \>
![](http://latex.codecogs.com/gif.latex?%20T\(n\)%20=%20T\(n-2\)%20+%202\\lg{n}%20~%20The%20~same%0d%0a)
***
**j.** <br \>
![](http://latex.codecogs.com/gif.latex?%20T\(n\)%20=%20\\sqrt{n}T\(\\sqrt{n}\)+n%20\\\\%0d%0aLet's%20~%20guess%20~%20\\Theta\(cn\\lg{\\lg{n}}\)%20\\\\%0d%0aT\(n\)%20\\le%20\\sqrt{n}c\\sqrt{n}\\lg{\\lg{\\sqrt{n}}}+n%20\\\\%0d%0a=%20cn\\lg{\\lg{\\sqrt{n}}}+n%20\\\\%0d%0a=%20cn\\lg{\\frac{\\lg{n}}{2}}+n%20\\\\%0d%0a=%20cn\\lg{\\lg{n}}%20-%20cn\\lg{2}+n%20\\\\%0d%0a=%20cn\\lg{\\lg{n}}%20+%20\(1-c\)n%20%20%20%20\\\\%0d%0a\\le%20cn\\lg{\\lg{n}}%20~~~~~~~~~%20if%20~%20c%20>%201%20\\\\%0d%0a=%20\\Theta\(cn\\lg{\\lg{n}}\)%0d%0a)


### Problems 5 : Fibonacci numbers
***
This problem develops properties of the Fibonacci numbers, which are defined by recurrence (3.21). We shall use the technique of generating functions to solve the Fibonacci recurrence. Define the generating function (or formal power series) F as

![](http://latex.codecogs.com/gif.latex?%20\\mathcal{F}\(z\)%20=%20\\sum_{i=0}^{\\infty}F\_iz^i%20\\\\%0d%0a=%200%20+%20z%20+%20z^2%20+%202z^3%20+%203z^4%20+%205z^5%20+%208z^6%20+%2013z^7%20+%2021z^8%20+%20\\ldots%20\\\\%0d%0awhere~%20F_i%20~is%20~the~%20ith%20~Fibonacci~%20number.)

a. Show that ![](http://latex.codecogs.com/gif.latex?%20\\mathcal{F}\(z\)%20=%20z%20+%20z\mathcal{F}\(z\)%20+%20z^2\mathcal{F}\(z\))

b. Show that ![](http://latex.codecogs.com/gif.latex?%20\\mathcal{F}\(z\)%20=%20\\frac{z}{1-z-z^2}%20=%20\\frac{z}{\(1-\\phi{z}\)\(1-\\widehat\\phi{z}\)}%20=%20\\frac{1}{\\sqrt{5}}\(\\frac{1}{1-\\phi{z}}-\\frac{1}{1-\\widehat\\phi{z}}\)%0d%0a)

c. Show that Show that ![](http://latex.codecogs.com/gif.latex?%20\\mathcal{F}\(z\)%20=%20\\sum_{i=0}^{\\infty}\\frac{1}{\\sqrt{5}}\(\\phi^i%20-%20\\widehat\\phi^i\)z^i%20)

d. Prove that ![](http://latex.codecogs.com/gif.latex?%20\\mathcal{F}\(z\)%20=%20\\phi^i/\\sqrt{5}) for i > 0 , rounded to the nearest integer.

e. Prove that ![](http://latex.codecogs.com/gif.latex?%20F_{i+2}%20\\ge%20\\phi%20i) for i ≥ 0.

### `Answer`
**a.**

![](http://latex.codecogs.com/gif.latex?%20z%20+%20z\mathcal{F}\(z\)%20+%20z^2\mathcal{F}\(z\)%20\\\\%0d%0a=%20z%20+%20z\\sum_{i=0}^{\\infty}F\_iz^i%20+%20z^2\\sum_{i=0}^{\\infty}F\_iz^i%20\\\\%0d%0a=%20z%20+%20z\\sum_{i=1}^{\\infty}F\_{i-1}z^i%20+%20z^2\\sum_{i=2}^{\\infty}F\_{i-2}z^i%20\\\\%0d%0a=%20z%20+%20F_1z%20+%20\\sum_{i=2}^{\\infty}\(F_{i-1}+F_{i-2}\)z^i%20\\\\%0d%0a=%20z%20+%20F_1z%20+%20\\sum_{i=2}^{\\infty}F_iz^i%20\\\\%0d%0a=%20\\mathcal{F}\(z\))

**b.**
这个结论的证明还是很straight-forward的，就不写公式啦.

**c.**

![](http://latex.codecogs.com/gif.latex?%20%0d%0a\\quad\\text{First,%20we%20have%20}%20\\frac{1}{1%20-%20x}%20=%20\\sum_{k=0}^{\\infty}x^k%20\\quad\\text{when%20}%20|x|%20<%201%20\\\\%0d%0a\\mathcal{F}\(n\)%20=%20\\frac{1}{\\sqrt5}\\Big\(\\frac{1}{1%20-%20\\phi%20z}%20-%20\\frac{1}{1%20-%20\\hat\\phi%20z}\\Big\)%20=%20\\frac{1}{\\sqrt5}\\Big\(\\sum_{i=0}^{\\infty}\\phi^i%20z^i%20-%20\\sum_{i=0}^{\\infty}\\hat{\\phi}^i%20z^i\\Big\)=%20\\sum_{i=0}^{\\infty}\\frac{1}{\\sqrt5}\(\\phi^i%20-%20\\hat{\\phi}^i\)%20z^i%0d%0a)

**d.**

![](http://latex.codecogs.com/gif.latex?%0d%0a\\mathcal{F}\(z\)%20=%20\\sum_{i=0}^{\\infty}\\alpha_iz^i%20\\quad\\text{%20where%20}%20\\alpha_i%20=%20\\frac{\\phi^i%20-%20\\hat{\\phi}^i}{\\sqrt5}%20\\\\%0d%0a\\quad\\text{%20so%20we%20have%20}%20\\alpha_i%20=%20F_i%20\\\\%0d%0aF_i%20=%20\\frac{\\phi^i%20-%20\\hat{\\phi}^i}{\\sqrt5}%20%20=%20\\frac{\\phi^i}{\\sqrt5}%20-%20\\frac{\\hat{\\phi}^i}{\\sqrt5}%20\\\\%0d%0a\\quad\\text{because%20}%20|\\hat\\phi|%20<%201%20\\quad\\text{,%20so%20}%20\\frac{|\\hat\\phi^i|}{\\sqrt{5}}%20<%200.5%0d%0a)

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

中文版

a. 如果超过一半是坏的，那么我们可以从这些坏的中取出一组数量和好的一样多的，他们的表现能和好的一样.

b. 将所有的芯片两两配对，如果报告是both are good or bad,那么就从中随机选一个留下来，否则全部扔掉. 一直这样递归下去，最后剩下的是好的.

c. T(n) = T(n/2)+n/2,是Θ(n)的.

English Version

a. consider the situation that at least half chips are bad. Denote good chip number is N. 
**We can choice more than N bad chips, and make them act as same as GOOD one.**
In this situation, we cannot distinguish whether is GOOD or BAD.(The BAD chips are always major and perfectly confuse information GOOD chips make)

b. Let make floor(N / 2) pairs arbitrarily. We **focus the pairs that both of it report opponent is GOOD.**
Because at least half chips are GOOD, **the pairs both report opponent is GOOD contains at least half GOOD-GOOD pairs.** Next, **we discard one chip of the GOOD-GOOD pair, per every GOOD-GOOD pairs.** After all, **we operate the remained chips as same as this action.**(make pairs -> focus GOOD-GOOD reported pairs -> discard one chip per pairs)
We can decrease the target chips by half by discarding, and **after discarding we can still assure that target chips contains at least half GOOD chips.** As a conclusion, if we make this actions till the last chip remained, the last must be GOOD.

c. The recurrence is

T(n) = T(n / 2) + n / 2

This is Θ(n) admittedly.

日本語版

a. 過半数のチップがbadの時、**goodのチップより多くのbadチップに、goodチップと同じ挙動をしてもらえばよい。**
そのとき、判別者はどれがgoodでどれがbadチップなのかを判別できない。

b. 任意にfloor(N / 2)ペア組んで、その中で「どちらもGOOD」のペアに着目する。この時、**必ず過半数のペアはGOOD-GOODである(つまり、BAD-BADよりもGOOD-GOODの方が必ず多い)**
次に、その「どちらもGOOD」の各ペアのうち片方のチップを除外する。この操作後でも、着目するチップのうち、GOODチップはBADチップより必ず多くなる。
よって、その半分にする作業を最後の1つになるまで繰り返せば、残ったチップはGOODだと確定する。(常にGOODチップは
BADチップより多いため)

c. T(n)は、n / 2回のペア判別と捨てるを行った後、T(n / 2)の計算に移るので、漸化式は

T(n) = T(n / 2) + n / 2

この漸化式は明らかに、Θ(n)の式となる。

### Problems 7 : Monge arrays
***
An m × n array A of real numbers is a **Monge array** if for all i, j, k, and l such that 1 ≤ i < k ≤ m and 1 ≤ j < l ≤ n, we have

A[i, j] + A[k, l] ≤ A[i, l] + A[k, j].

In other words, whenever we pick two rows and two columns of a Monge array and consider the four elements at the intersections of the rows and the columns, the sum of the upper-left and lower-right elements is less or equal to the sum of the lower-left and upper-right elements. For example, the following array is Monge:

![](http://latex.codecogs.com/gif.latex?%20%20\\begin{matrix}%0d%0a%20%20%2010%20&%2017%20&%2013%20&%2028%20&%2023%20\\\\%0d%0a%20%20%2017%20&%2022%20&%2016%20&%2029%20&%2023%20\\\\%0d%0a%20%20%2024%20&%2028%20&%2022%20&%2034%20&%2024%20\\\\%0d%0a%20%20%2011%20&%2013%20&%20%206%20&%2017%20&%20%207%20\\\\%0d%0a%20%20%2045%20&%2044%20&%2032%20&%2037%20&%2023%20\\\\%0d%0a%20%20%2036%20&%2033%20&%2019%20&%2021%20&%20%206%20\\\\%0d%0a%20%20%2075%20&%2066%20&%2051%20&%2053%20&%2034%0d%0a%20%20%20\\end{matrix})
   
a. Prove that an array is Monge if and only if for all i = 1,2,...,m-1 and j = 1,2,...,n- 1, we have <br \>
A[i, j] + A[i + 1, j + 1] ≤ A[i, j + 1] + A[i + 1, j]. <br \>
Note (For the "only if" part, use induction separately on rows and columns.)


b. The following array is not Monge. Change one element in order to make it Monge.
![](http://latex.codecogs.com/gif.latex?%20%20\\begin{matrix}%0d%0a%20%20%2037%20&%2023%20&%2022%20&%2072%20%20\\\\%0d%0a%20%20%2021%20&%206%20&%207%20&%2010%20%20\\\\%0d%0a%20%20%2053%20&%2034%20&%2030%20&%2031%20\\\\%0d%0a%20%20%2032%20&%2013%20&%20%209%20&%206%20%20\\\\%0d%0a%20%20%2043%20&%2021%20&%2015%20&%208%20%20\\\\%0d%0a%20%20%20\\end{matrix})
   
   
c. Let f(i) be the index of the column containing the leftmost minimum element of row i. Prove that f(1) ≤ f(2) ≤ ··· ≤ f(m) for any m × n Monge array.

d. Here is a description of a divide-and-conquer algorithm that computes the left-most minimum element in each row of an m × n Monge array A: <br \>
Construct a submatrix A′ of A consisting of the even-numbered rows of A. Recursively determine the leftmost minimum for each row of A′. Then compute the leftmost minimum in the odd-numbered rows of A. <br \>
Explain how to compute the leftmost minimum in the odd-numbered rows of A (given that the leftmost minimum of the even-numbered rows is known) in O(m + n) time.


e. Write the recurrence describing the running time of the algorithm described in part (d). Show that its solution is O(m + n log m).

### `Answer`
**a.**

![](http://latex.codecogs.com/gif.latex?%20%0d%0aA[i,%20j]%20+%20A[k,%20l]%20\\le%20A[i,%20l]%20+%20A[k,%20j]%0d%0a%20%20%20\\%20\xrightarrow[k%20=%20i+1]{l%20=%20j+1}%0d%0a%20%20%20A[i,j]%20+%20A[i+1,%20j+1]%20\\le%20A[i,%20j+1]%20+%20A[i+1,j])
***
![](http://latex.codecogs.com/gif.latex?%20%20%20\\quad\\text{assume%20}%20A[i,j]+A[k,j+1]%20\\le%20A[i,j+1]+A[k,j]%20\\\\%0d%0a\\quad\\text{to%20prove%20}%20%20%20A[i,j]+A[k+1,j+1]%20\\le%20A[i,j+1]+A[k+1,j]%20\\\\%20\\\\%0d%0aA[k,j]+A[k+1,j+1]%20\\le%20A[k,j+1]+A[k+1,j]%20\\\\%0d%0a\\rightarrow%20A[i,%20j]%20+%20A[k,%20j+1]%20+%20A[k,%20j]%20+%20A[k+1,%20j+1]%20\\le%0d%0a%20%20%20A[i,%20j+1]%20+%20A[k,%20j]%20+%20A[k,%20j+1]%20+%20A[k+1,%20j]%20\\\\%0d%0a%20%20%20\\rightarrow%20\\%0d%0a%20%20%20A[i,%20j]%20+%20A[k+1,%20j+1]%20\\le%20A[i,%20j+1]%20+%20A[k+1,%20j])
   
**b.**

![](http://latex.codecogs.com/gif.latex?%20%20\\begin{matrix}%0d%0a%20%20%2037%20&%2023%20&%20\\textbf{24}%20&%2072%20%20\\\\%0d%0a%20%20%2021%20&%206%20&%207%20&%2010%20%20\\\\%0d%0a%20%20%2053%20&%2034%20&%2030%20&%2031%20\\\\%0d%0a%20%20%2032%20&%2013%20&%20%209%20&%206%20%20\\\\%0d%0a%20%20%2043%20&%2021%20&%2015%20&%208%20%20\\\\%0d%0a%20%20%20\\end{matrix})
   
**c.** **反证法**

如果i < j,f(i) >= f(j)

A[i,f(j)]+A[j,f(i))] <= A[i,f(i)]+A[j,f(j)] 但是A[i,f(i)]和A[j,f(j)]是两行最小的元素，等式不成立.

**d.**根据c可以知道第i行的左端最小值落在f(i-1)和f(i+1)之间. 总共有n/2个奇数行，总共需要比较m次，所以是O(m+n).

**e.**
T(m) = T(m/2) + cn + dm = O(nlgm + m)

[code](./exercise_code/findIndex.py)



***
Follow [@louis1992](https://github.com/gzc) on github to help finish this task.

