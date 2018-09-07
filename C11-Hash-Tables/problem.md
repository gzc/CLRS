### Problems 1 : Longest-probe bound for hashing
***
A hash table of size m is used to store n items, with n ≤ m/2. Open addressing is used for collision resolution.

**a.**Assuming uniform hashing, show that for i=1,2,…,n, the probability is at most 2^−k that the ith insertion requires strictly more than k probes.


**b.**Show that for i=1,2,…,n, the probability is O(1/n^2) that the ith insertion requires more than 2lgn probes.

Let the random variable Xi denote the number of probes required by the ith insertion. You have shown in part (b) that 
![](http://latex.codecogs.com/gif.latex?%0d%0a\\Pr\\{X_i%20>%202\\lg{n}\\}%20=%0d%0aO\(1/n^2\)%20)
. Let the random variable 
![](http://latex.codecogs.com/gif.latex?%0d%0aX%20=%20max_{1%20\\le%20i%20\\le%20n}X_i)
denote the maximum number of probes required by any of the n insertions.

**c.**Show that Pr{X > 2lgn}=O(1/n).

**d.**Show that the expected length E[X] of the longest probe sequence is O(lgn).

### `Answer`
**a.**

P = (n/m)^k < (1/2)^k = 2^-k

**b.**

代入a中的结论即可

**c.**

![](http://latex.codecogs.com/gif.latex?P%20=%20\\prod_{i=0}^{2\\lg{n}}\\frac{m/2-i}{m}%20<%20\\prod_{i=0}^{2\\lg{n}}%20\\frac{1}{2}%20=%20\\frac{1}{2}^{2\\lg{n}}%20=%20\\frac{1}{4}^{\\lg{n}}%20=%204^{\\lg{n^{-1}}}%20=%20O\(n^{-1}\)%20)

**d.**

该题可以参考5.4.2节的关于**球与盒子**的结论和5.4.3节的关于**序列**的结论.

我们把每次的概率放大为1/2(实际上是≤ 1/2的) 

所以是O(lgn)



### Problems 2 : Slot-size bound for chaining
***
Suppose that we have a hash table with n slots, with collisions resolved by chaining, and suppose that n keys are inserted into the table. Each key is equally likely to be hashed to each slot. Let M be the maximum number of keys in any slot after all the keys have been inserted. Your mission is to prove an O(lg n/lg lg n) upper bound on E[M], the expected value of M.

**a.**
Argue that the probability Qk that exactly k keys hash to a particular slot is given by

![](http://latex.codecogs.com/gif.latex?%20Q_k%20=%20\(\\frac{1}{n}^k%20\)%20\(1-\\frac{1}{n}\)^{n-k}%20C_k^n)


### `Answer`



***
Follow [@louis1992](https://github.com/gzc) on github to help finish this task.

