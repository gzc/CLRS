/*
 * maximum contiguous subsequence. 
 * A contiguous subsequence of a list S is a subsequence made up of consecutive elements of S.
 * For instance, if S is 5, 15, −30, 10, −5, 40, 10,
 * then 15, −30, 10 is a contiguous subsequence but 5, 15, 40 is not.
 * Give a linear-time algorithm for the following task:
 * Input: A list of numbers, a1, a2, . . . , an.
 * Output: The contiguous subsequence of maximum sum (a subsequence of length zero has sum zero).
 * For the preceding example, the answer would be 10, −5, 40, 10, with a sum of 55.
 *
 */













/*
 * Solution:
 * we construct a f(n)
 * f(n) = f(n-1)+a(n)    if  f(n-1) >= 0
 *	    = an			 if  f(n-1) < 0
 *	    = a1             if  n = 1
 *
 *	    for example
 *
 *	    a(n)      5 15 -30 10 -5 40 10
 *	    f(n)	  5 20 -10 10 5  45 55
 *	    and we find the max in f(n) is 55,and we can easily compute the sequence
 *	    All operations can be done in O(n)
 *
 */


