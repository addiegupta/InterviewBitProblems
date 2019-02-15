/*
InterviewBit : Max Sum Contiguous Subarray

Link : https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

Asked in:  
Facebook
Paypal
Yahoo
Microsoft
LinkedIn
Amazon
Goldman Sachs

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example:

Given the array [-2,1,-3,4,-1,2,1,-5,4],

the contiguous subarray [4,-1,2,1] has the largest sum = 6.

For this problem, return the maximum sum.

 */

// This problem is solved using Kadane's algorithm

int Solution::maxSubArray(const vector<int> &A) {
    
    int n = A.size();

    // This value is to be returned in case only negatives are present
    int maxValue;
    for(int i=0;i<n;i++)
        if(i==0 || A[i]>maxValue) maxValue = A[i];
    
    int maxSumAns=0;
    int maxSubarraySum=0;
    
    for(int i=0;i<n;i++){
    	// The maxSubarraySum value is compared to maxSumAns value.
     	// maxSumAns is set to value of the greater among the two

    	// This is the value of sum of current subarray being considered
    	maxSubarraySum += A[i];
    	
    	// Negative subarray sum is reset to 0
    	// i.e. the subarray being considered is started from here	
    	if (maxSubarraySum < 0)	maxSubarraySum = 0;
    	
	    // The maxSubarraySum value is the sum of contiguous sub array 
    	if(maxSumAns < maxSubarraySum) maxSumAns=maxSubarraySum;
    
    }
    return (maxSumAns==0)?maxValue:maxSumAns;
    

}
