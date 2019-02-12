/*
InterviewBit : Min XOR Value

Link : https://www.interviewbit.com/problems/min-xor-value/

Asked in:

Booking.com

Given an array of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR value.

Examples : 
Input 
0 2 5 7 
Output 
2 (0 XOR 2) 
Input 
0 4 7 9 
Output 
3 (4 XOR 7)

Constraints: 
2 <= N <= 100 000 
0 <= A[i] <= 1 000 000 000


*/
int Solution::findMinXor(vector<int> &A) {
	
	// Sort the array
	sort(A.begin(),A.end());
	
	int n= A.size();
	int min = INT_MAX;

	// As array is sorted, answer will be A[i]^A[i+1] (for some i) as closer the numbers,
	// more the number of set bits in their binary form
	for(int i=0;i<n-1;i++){
		if((A[i]^A[i+1])<min)min = A[i]^A[i+1];
	}
	return min;
}
