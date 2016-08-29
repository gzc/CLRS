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

Actually we need not imitate the implementation of min-heap by array. And since we do not have `A->last`, it is not a big issue if the linked list is singly linked or doubly linked.

For unsorted linked list,

1. `MAKE-HEAP`: O(1).
	````
	MAKE-HEAP()
		return MAKE-LINKED-LIST()
	````

2. `INSERT`: O(1).
	````
	INSERT(A, x)
		LIST-INSERT'(A->L, x)
	````

3. `MINIMUM`: O(n). We need iterate the whole linked list.
	````
	MINIMUM(A)
		return LIST-MINIMUM(A->L)
	````

4. `EXTRACT-MIN(A)`: O(n). Mainly due to `MINIMUM`.
	````
	EXTRACT-MIN(A)
		x = LIST-MINIMUM(A->L)
		LIST-DELETE(A->L, x)
		return x
	````

5. `UNION`: O(n). Since the linked lists here does not have `L->last`. We need O(n) to find the last element.
	````
	UNION(A, B)
		A.last->next = B.first
	````

For sorted linked list,

1. `MAKE-HEAP`: O(1). Nothing different.
	````
	MAKE-HEAP()
		return MAKE-LINKED-LIST()
	````

2. `INSERT`: O(n). We need find the position.
	````
	INSERT(A, x)
		LIST-INSERT'(A->L, x)
	````

3. `MINIMUM`: O(1).
	````
	MINIMUM(A)
		return A->L.first
	````

4. `EXTRACT-MIN(A)`: O(1).
	````
	EXTRACT-MIN(A)
		x = A->L.first
		LIST-DELETE(A->L, A->L.first)
		return x
	````

5. `UNION`: O(n). Use algorithm like `MERGE` in merge sort.
	````
	UNION(A, B)
		Merge(A, B)
	````


In conclusion, we find

| Method | unsorted | sorted |
| ------ | -------- | ------ |
| `MAKE-HEAP()` | O(1) | O(1) |
| `INSERT(A, x)` | O(1) | O(n) |
| `MINIMUM(A)` | O(n) | O(1) |
| `EXTRACT-MIN(A)` | O(n) | O(1) |
| `UNION(A, B)` | O(n) | O(n) |


***
Follow [@louis1992](https://github.com/gzc) on github to help finish this task.
