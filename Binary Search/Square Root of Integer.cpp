/*
InterviewBit : Square Root of Integer

Link : https://www.interviewbit.com/problems/square-root-of-integer/

Asked in 

Amazon
Facebook
Microsoft

Implement int sqrt(int x).

Compute and return the square root of x.

If x is not a perfect square, return floor(sqrt(x))

Example :

Input : 11
Output : 3
DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY

*/
int Solution::sqrt(int A) {
	// 0 and 1
	if(A<2)return A;

	// Binary search for the square root of A
	int low = 1,high = A;
	int mid;
	int ans=0;
	while(low<=high){
		mid = low +(high-low)/2;
		
		// Using division instead of multiplication to avoid overflow errors
		if(mid<=A/mid){
			ans=mid;
			low=mid+1;
		}
		else high = mid-1;
	}	
	return ans;
}
