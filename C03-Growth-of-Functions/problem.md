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


### Problems 3 : Ordering by asymptotic growth rates
***
a.
Rank the following functions by order of growth; that is, find an arrangement ![](https://latex.codecogs.com/gif.latex?g_1,&space;g_2,...,g_{30}) of the functions satisfying ![](https://latex.codecogs.com/png.latex?g_1=\Omega\(g_2\),g_2=\Omega\(g_3\),...,g_{29}=\Omega\(g_{30}\)). Partition your list into equivalence classes such that functions ![](https://latex.codecogs.com/png.latex?f\(n\)) and ![](https://latex.codecogs.com/png.latex?g_i\(n\)) are in the same class if and only if ![](https://latex.codecogs.com/png.latex?f\(n\)=\Theta\(g\(n\)\)).
![](https://latex.codecogs.com/png.latex?lg\(lg^*n\)\quad&space;2^{lg^*n}\quad&space;\(\sqrt{2}\)^{lgn}\quad&space;n^2&space;\quad&space;n!\quad&space;\(lgn\)!\newline&space;\(\frac{2}{3}\)^n\quad&space;n^3\quad&space;lg^2n\quad&space;lg\(n!\)\quad&space;2^2^n\quad&space;n^{1/lgn}\newline&space;ln&space;lnn\quad&space;lg^*n\quad&space;n\cdot&space;2^n\quad&space;n^{lg&space;lgn}\quad&space;lnn\quad&space;1\newline&space;2^{lgn}\quad&space;{\(lgn\)}^{lgn}\quad&space;e^n\quad&space;4^{lgn}\quad&space;\(n&plus;1\)!\quad&space;\sqrt{lgn}\newline&space;lg^*\(lgn\)\quad&space;2^{\sqrt{2lgn}}\quad&space;n\quad&space;2^n\quad&space;nlgn\quad&space;2^{2^{n&plus;1}})

b.
Give an example of a single nonnegative function ![](https://latex.codecogs.com/png.latex?f\(n\)) such that for all functions ![](https://latex.codecogs.com/png.latex?g_i\(n\)) in part (a), ![](https://latex.codecogs.com/png.latex?f\(n\)) is neither ![](https://latex.codecogs.com/gif.latex?\O\(g_i\(n\)\)) nor  ![](https://latex.codecogs.com/gif.latex?\Omega\(g_i\(n\)\)).

### `Answer`
a.
![](https://latex.codecogs.com/gif.latex?2^{2^{n&plus;1}}\quad&space;2^{2^{n}}\newline&space;\(n&plus;1\)!\quad&space;n!\newline&space;e^n\quad&space;n\cdot&space;2^n\quad&space;2^n\quad&space;\(\frac{3}{2}\)^n\newline&space;\(lgn\)^{lgn}=n^{lglgn}\quad&space;\(lgn\)!\newline&space;n^3\quad&space;n^2=4^{lgn}\quad&space;nlgn=lg\(n!\)\quad&space;2^{lgn}=n\quad&space;\(\sqrt{2}\)^{lgn}=\sqrt{n}\quad&space;2^{\sqrt{2\cdot&space;lgn}}\newline&space;lg^{2}n\quad&space;lnn\quad&space;\sqrt{lgn}\newline&space;lnlnn\quad&space;2^{lg^{*}n}\newline&space;lg^{*}n\quad&space;lg^{*}\(lgn\)\quad&space;lg\(lg^{*}\)n\newline&space;n^{\frac{1}{lgn}}=2\quad&space;1)
![](https://latex.codecogs.com/gif.latex?\(lgn\)^{lgn}=n^{lglgn}\quad&space;because&space;of\quad&space;a^{log_bc}=c^{log_ba}\newline&space;n^{\frac{1}{lgn}}=2\quad&space;because\quad&space;n^{\frac{1}{lgn}}=2^{lgn\cdot&space;\frac{1}{lgn}}=2)

b.
![](https://latex.codecogs.com/png.latex?2^{2^\sin{n}})


***
Follow [@louis1992](https://github.com/gzc) on github to help finish this task.

