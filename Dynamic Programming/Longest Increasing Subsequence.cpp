/*
InterviewBit : Longest Increasing Subsequence

Link : https://www.interviewbit.com/problems/longest-increasing-subsequence/


Asked in:
Amazon
Epic systems
Facebook
Microsoft
Yahoo

Find the longest increasing subsequence of a given sequence / array.

In other words, find a subsequence of array in which the subsequence’s elements are in strictly increasing order, and in which the subsequence is as long as possible. 
This subsequence is not necessarily contiguous, or unique.
In this case, we only care about the length of the longest increasing subsequence.

Example :

Input : [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
Output : 6
The sequence : [0, 2, 6, 9, 13, 15] or [0, 4, 6, 9, 11, 15] or [0, 4, 6, 9, 13, 15]

*/


int Solution::lis(const vector<int> &A) {
    
    int n = A.size();

    // Stores the length of longest increasing subsequence till index i
    int lis[n]; 
   
   	// Length for first element is 1 as only that element is included
    lis[0]=1;
    
    int ans=1;

    for(int i=1;i<n;i++){
    	
    	// At least this element can be considered
        lis[i]=1;

        // Iterate for elements starting from 0 till current i index
        for(int j=0;j<i;j++){

        	// If num at index j is less than at i AND lis value will be better if sequence is continued from j
        	// as opposed to currently chosen value, then update lis value
            if(A[j]<A[i] && lis[i]<lis[j]+1){
                lis[i] = lis[j] + 1;
                ans = max(ans,lis[i]);
            }
        }
    }
    return ans;
}
