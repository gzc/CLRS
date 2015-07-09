### Problems 1 : Comparisons among lists
***
For each of the four types of lists in the following table, what is the asymptotic worst-case running time for each dynamic-set operation listed?
### `Answer`
<table class="table table-bordered table-striped table-compact">
<thead>
<tr>
<th style="text-align: left"></th>
<th style="text-align: center">unsorted, singly linked</th>
<th style="text-align: center">sorted, singly linked</th>
<th style="text-align: center">unsorted, doubly linked</th>
<th style="text-align: center">sorted, doubly linked</th>
</tr>
</thead>
<tbody>
<tr>
<td style="text-align: left"><code>SEARCH(L, k)</code></td>
<td style="text-align: center">linear</td>
<td style="text-align: center">linear</td>
<td style="text-align: center">linear</td>
<td style="text-align: center">linear</td>
</tr>
<tr>
<td style="text-align: left"><code>INSERT(L, x)</code></td>
<td style="text-align: center">constant</td>
<td style="text-align: center">linear</td>
<td style="text-align: center">constant</td>
<td style="text-align: center">linear</td>
</tr>
<tr>
<td style="text-align: left"><code>DELETE(L, x)</code></td>
<td style="text-align: center">linear</td>
<td style="text-align: center">linear</td>
<td style="text-align: center">constant</td>
<td style="text-align: center">constant</td>
</tr>
<tr>
<td style="text-align: left"><code>SUCCESSOR(L, x)</code></td>
<td style="text-align: center">linear</td>
<td style="text-align: center">constant</td>
<td style="text-align: center">linear</td>
<td style="text-align: center">constant</td>
</tr>
<tr>
<td style="text-align: left"><code>PREDECESSOR(L, x)</code></td>
<td style="text-align: center">linear</td>
<td style="text-align: center">linear</td>
<td style="text-align: center">linear</td>
<td style="text-align: center">constant</td>
</tr>
<tr>
<td style="text-align: left"><code>MINIMUM(L, k)</code></td>
<td style="text-align: center">linear</td>
<td style="text-align: center">constant</td>
<td style="text-align: center">linear</td>
<td style="text-align: center">constant</td>
</tr>
<tr>
<td style="text-align: left"><code>MAXIMUM(L, k)</code></td>
<td style="text-align: center">linear</td>
<td style="text-align: center">linear</td>
<td style="text-align: center">linear</td>
<td style="text-align: center">linear</td>
</tr>
</tbody>
</table>

### Problems 2 : Mergeable heaps using linked lists
***
A **mergeable heap** supports the following operations: MAKE-HEAP (which creates an empty mergeable heap), INSERT, MINIMUM, EXTRACT-MIN, and UNION. Show how to implement mergeable heaps using linked lists in each of the following cases. Try to make each operation as efficient as possible. Analyze the running time of each operation in terms of the size of the dynamic set(s) being operated on.
a. Lists are sorted.
b. Lists are unsorted.
c. Lists are unsorted, and dynamic sets to be merged are disjoint.

### `Answer`


***
Follow [@louis1992](https://github.com/gzc) on github to help finish this task.

