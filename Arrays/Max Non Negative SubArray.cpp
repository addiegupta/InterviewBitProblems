/*
InterviewBit : Max Non Negative SubArray

Link : https://www.interviewbit.com/problems/max-non-negative-subarray/


Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:

A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]
NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length
NOTE 2: If there is still a tie, then return the segment with minimum starting index



*/

vector<int> Solution::maxset(vector<int> &A) {
	
	int n=A.size(),ansStart=0,start=0,length=0,ansLength=0;
	long long int sum=0,ansSum=0;
	
	for(int i=0;i<n;i++){
		if(A[i]<0){
			sum=0;
			start=i+1;
			length=0;
		}	
		else{
			sum+=A[i];
			length++;
			if(sum>ansSum || (sum==ansSum && ansLength < length)){
				ansSum = sum;
				ansStart = start;
				ansLength=length;
			}
		}
	}
	
	vector<int> ans;
	for(int i=ansStart;i<ansStart+ansLength;i++)ans.push_back(A[i]);
	return ans;
}
