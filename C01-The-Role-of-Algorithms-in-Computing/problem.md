### Problems 1 : Comparison of running times
***
For each function **f**(n) and time t in the following table, determine the largest size n of a problem that can be solved in time t, assuming that the algorithm to solve the problem takes **f**(n) microseconds.

### `Answer`
Item | 1 second | 1 miniute | 1 hour | 1 day | 1 month | 1 year | 1 century
:----:|----:|----:|----:|----:|----:|----:|----:
![](http://latex.codecogs.com/gif.latex?\\lg{n}) | ![](http://latex.codecogs.com/gif.latex?\\2^{10^6}})  | ![](http://latex.codecogs.com/gif.latex?\\2^{6*10^7}}) | ![](http://latex.codecogs.com/gif.latex?\\2^{36*10^8}}) | ![](http://latex.codecogs.com/gif.latex?\\2^{864*10^8}}) | ![](http://latex.codecogs.com/gif.latex?\\2^{25920*10^8}}) | ![](http://latex.codecogs.com/gif.latex?\\2^{315360*10^8}}) | ![](http://latex.codecogs.com/gif.latex?\\2^{31556736*10^8}})
![](http://latex.codecogs.com/gif.latex?\\/{n}^{1/2}) | ![](http://latex.codecogs.com/gif.latex?\\10^{12}) | ![](http://latex.codecogs.com/gif.latex?\\36*10^{14}) | ![](http://latex.codecogs.com/gif.latex?\\1296*10^{16}) | ![](http://latex.codecogs.com/gif.latex?\\746496*10^{16}) | ![](http://latex.codecogs.com/gif.latex?\\6718464*10^{18}) | ![](http://latex.codecogs.com/gif.latex?\\994519296*10^{18}) | ![](http://latex.codecogs.com/gif.latex?\\995827586973696*10^{16}) 
![](http://latex.codecogs.com/gif.latex?\\/{n}) | ![](http://latex.codecogs.com/gif.latex?\\10^6)  | ![](http://latex.codecogs.com/gif.latex?6*10^7) | ![](http://latex.codecogs.com/gif.latex?36*10^8) | ![](http://latex.codecogs.com/gif.latex?864*10^8) | ![](http://latex.codecogs.com/gif.latex?2592*10^9) | ![](http://latex.codecogs.com/gif.latex?31536*10^9) | ![](http://latex.codecogs.com/gif.latex?31556736*10^8)
![](http://latex.codecogs.com/gif.latex?\\/{n}\\lg{n}) | 62746 | 2801417 | 133378058 | 2755147513| 71870856404 | 797633893349 | 68654697441062
![](http://latex.codecogs.com/gif.latex?\\/{n}^2) | 1000 | 7745 | 60000 | 293938 | 1609968 | 5615692 | 56175382
![](http://latex.codecogs.com/gif.latex?\\/{n}^3) | 100 | 391 | 1532 | 4420 | 13736 | 31593 | 146677
![](http://latex.codecogs.com/gif.latex?\\2^n) | 19 | 25 | 31 | 36 | 41 | 44 | 51
![](http://latex.codecogs.com/gif.latex?\\/{n}!) | 9 | 11 | 12 | 13 | 15 | 16 | 17


***
Follow [@louis1992](https://github.com/gzc) on github to help finish this task.

