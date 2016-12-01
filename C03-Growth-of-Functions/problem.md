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

For this problem, some people point out that

for 0 < epsilon < 1,

lg^k n > n^epsilon

and for epsilon >= 1,

lg^k n) < n^epsilon

Therefore, the correct answer is
YES YES YES YES YES

[issue 103](https://github.com/gzc/CLRS/issues/103)

***
Follow [@louis1992](https://github.com/gzc) on github to help finish this task.

