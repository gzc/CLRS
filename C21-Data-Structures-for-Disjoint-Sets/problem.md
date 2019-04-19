### Problems 1 : Off-line minimum
***

The off-line minimum problem asks us to maintain a dynamic set T of elements from the domain {1, 2, ..., n} under the operations INSERT and EXTRACT-MIN. We are given a sequence S of n INSERT and m EXTRACT-MIN calls, where each key in {1, 2, ..., n} is inserted exactly once. We wish to determine which key is returned by each EXTRACT-MIN call. Specifically, we wish to fill in an array extracted[1..m], where for i = 1, 2, ..., m, extracted[i] is the key returned by the ith EXTRACT-MIN call. The problem is "off-line" in the sense that we are allowed to process the entire sequence S before determining any of the returned keys.

a. In the following instance of the off-line minimum problem, each INSERT is represented by a number and each EXTRACT-MIN is represented by the letter E:
4, 8, E, 3, E, 9, 2, 6, E, E, E, 1, 7, E, 5.
Fill in the correct values in the extracted array.
To develop an algorithm for this problem, we break the sequence S into homogeneous
subsequences. That is, we represent S by I1, E, I2, E, I3, ..., Im, E, Im+1,
        
where each E represents a single EXTRACT-MIN call and each Ij represents a (possibly empty) sequence of INSERT calls. For each subsequence Ij, we initially place the keys inserted by these operations into a set Kj , which is empty if Ij is empty. We then do the following.

```
OFF-LINE-MINIMUM(m, n)
    for i <- 1 to n
        do determine j such that i ∈ K[j]
        if j != m + 1
            extracted[j] = i
            let l be the smallest value greater than j for which set K[l] exists
            K[l] = K[j] ∪ K[l], destroying K[j]
    return extracted
```

b. Argue that the array extracted returned by OFF-LINE-MINIMUM is correct.

c. Describe how to implement OFF-LINE-MINIMUM efficiently with a disjoint-set data
structure. Give a tight bound on the worst-case running time of your implementation.

### `Answer`

a. Each E returns the smallest value before it that hasn't been returned yet, therefore the array extracted will be [4,3,2,6,8,1].

b. The algorithm determines the values returned by extract-min one by one, one extraction at a time.

We shall prove that every integer ` i ` inserted in the extracted table by the algorithm is correct, and that the table is entirely filled. This shall prove that the table is entirely filled correctly at the end.

Suppose the ` i-1 >= 0 ` first integers have been treated correctly, the algorithm then treats ` i `. For that, it determines ` j ` such that ` i \in K_j ` (which does exist since there are always more insertions than extractions at any given point), which means that ` i ` is inserted during the sequence ` I_j ` by definition. If ` j = m+1 ` then ` i ` is not written into the extracted array, which is indeed correct since it has been inserted after all extractions. Suppose now ` j <= m `.

Therefore, the ` j `th extraction, which occurs right after ` I_j `, must return ` i ` since every value smaller than ` i ` has already been attributed a correct extraction and ` i ` could not have been returned by any previous extraction since it is inserted during ` I_j `.

Afterwards, the algorithm get rids of extraction ` j `: to do that, it removes the E of index j in the sequence by merging the values inserted during ` I_j ` and ` I_l ` for ` l >j ` which has not been merged itself yet. This gives us a new sequence which is equivalent in the sense that the remaining extractions will have the same values as prior. Indeed, we know the extractions we have removed have their correct return values ` 1,...,i ` recorded in the extracted table, and the remaining values to be extracted are in the remaining sequences. The merge means that the values occuring in sequence ` I_j ` can only be returned during the extractions following ` j ` which have not yet been removed, which explains why we look for the smallest ` l > j ` for which we have not yet merged the set ` I_l `.

The new sequence thus yields the same extractions, and therefore all extractions yielded by the algorithm are correct.

Finally, we have to prove the array is entirely filled. Suppose ` j ` is the smallest value for which the array is not filled at any step, and let i be the correct value it should hold. Since every extraction before ` j ` is filled with the correct value, none of them are filled with ` i `. Upon treating the integer ` i `, the set ` K_j ` has not been removed (otherwise the value extracted[j] would've been filled). The integer ` i ` is in one of the insertion sequences before ` j `, so finds itself currently in one of the sets ` K_1, ..., K_j `. If it is in a set ` K_k ` other than ` K_j ` then the algorithm will now set extracted[k] to i, which is absurd since we have supposed all of the extractions before j to be filled in (and proven above that they are done so correctly). Therefore, ` i \in K_j `, and the algorithm fills in extracted[j] correctly, which concludes the proof.

c. We shall make us of a disjoint-set data structure, but we add three pieces of information to the representative of each set: an integer ` j ` to denote the number of the set as a ` K_j `, and two integers "prev" and "next" to denote the previous and next sets that have not yet been merged (thus we store the sets in a doubly linked list). The way we initialize these values is obvious, with the previous of ` 0 ` being ` -1 ` and the next of ` m+1 ` being ` -1 ` (to indicate they don't exist).

Determining the ` j ` at line 2 of the algorithm now simply requires a FIND operation followed by the retrieval of the number assigned to the representative (which is ` j ` by definition).

Finding the smallest ` l ` is simply a matter of consulting the "next" assigned to the representative of ` K_j `, which will point to the next set we haven't deleted yet by definition (and will exist since ` j \neq m+1 ` at this point).

Finally, line 6 requires us to do an union operation. For that, we first follow the integer "prev" of the representative and set the "next"  of that previous set (if it exists) to the next of the representative of ` K_j `: the next set of the previous set is now the next set of the current set. Then, we do the same on the other side by setting the "prev" of the next set to the "prev" of the set we're deleting ` K_j `. Finally, we do a traditional UNION of the sets, which is correct by definition and preserves the next and prev values.

All of this tinkering means that each loop of the algorithm does at most one FIND and one UNION operation. As a matter of fact, we can be more precise since there are exactly ` n ` FIND operations being carried out, and precisely ` m ` UNION operations being done (since each ` K_j ` is deleted once and exactly once during the algorithm).

If we add the initial `n` makeset operations, we have an algorithm that has complexity ` O(n + (n+m)\alpha(n)) = O(n\alpha(n)) `.
