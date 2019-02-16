/*
InterviewBit : Diffk

Link : https://www.interviewbit.com/problems/diffk/

Asked in

Facebook

Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

 Example: Input : 
    A : [1 3 5] 
    k : 4
 Output : YES as 5 - 1 = 4 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Try doing this in less than linear space complexity.


*/
int Solution::diffPossible(vector<int> &A, int B) {


	int n = A.size();
	if(n<2 || B<0)return 0;
	int i=0;
	int j=1;
	
	// Find duplicate elements
	if(B==0){
		for(;i<n-1;i++)if(A[i]==A[i+1])return 1;
		return 0;
	}
	while((i<n-1) && (j<n)){
		
		int diff = A[j]-A[i];
		
		if(diff == B)return 1;
		else if(diff<B)j++;
		else i++;
	}
	return 0;
}
