/*
InterviewBit : Maximum Absolute Difference

Link : https://www.interviewbit.com/problems/maximum-absolute-difference/


You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

For example,

A=[1, 3, -1]

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.


*/

/***************************************
		EXPLANATION FOUND ON INTERVIEWBIT

We can split this maximization task into four cases, corresponding to the two possibilities for the sign of each of the two absolute value expressions.

1: A[i] < A[j], i < j: (A[j] - A[i]) + (j - i)
2: A[i] < A[j], i >= j: (A[j] - A[i]) + (i - j)
3: A[i] >= A[j], i < j: (A[i] - A[j]) + (j - i)
4: A[i] >= A[j], i >= j: (A[i] - A[j]) + (i - j)
Normally, each of these cases would be valid only for those i, j satisfying its respective constraint. However, remembering that our task is maximization, we note that for some arbitrary i, j, the formula for the case whose constraint is met by the chosen i, j happens to also yield the maximum value out of all four possibilities. Thus, we no longer need to worry about choosing the specific case satisfied by a particular choice of i, j during our optimization process. We can instead simply evaluate all four cases over all possible choices of i, j and choose the result with maximum value. That is, our task becomes that of maximizing each of the following, for all 1 <= i, j <= N:

1: (A[j] - A[i]) + (j - i)
2: (A[j] - A[i]) + (i - j)
3: (A[i] - A[j]) + (j - i)
4: (A[i] - A[j]) + (i - j)
And returning the maximum result. At this point, we can note that the first and fourth, as well as the second and third cases are equivalent. So, eliminating the two redundant cases and rewriting the remaining two slightly, we have:

1: (A[j] - A[i]) + (j - i) = (A[j] + j) - (A[i] + i)
2: (A[j] - A[i]) + (i - j) = (A[j] - j) - (A[i] - i)
At which point, the maximum of the first for 1 <= i, j <= N is:

max(A[i] + i) - min(A[i] + i)
And the maximum of the second for 1 <= i, j <= N is:

max(A[i] - i) - min(A[i] - i)
And we simply return the greater of the two.
*/

int Solution::maxArr(vector<int> &A) {

    int max1=INT_MIN,max2=INT_MIN,min1=INT_MAX,min2=INT_MAX;
    for(int i=0;i<A.size();i++){

        max1=max(max1,A[i] + i);
        max2=max(max2,A[i] - i);
        min1=min(min1,A[i] + i);
        min2=min(min2,A[i] - i);
    }

    return max(max1-min1,max2-min2);
}

