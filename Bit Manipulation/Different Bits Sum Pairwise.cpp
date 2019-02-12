/*
InterviewBit : Different Bits Sum Pairwise

Link : https://www.interviewbit.com/problems/different-bits-sum-pairwise/

Asked in:

Google

We define f(X, Y) as number of different corresponding bits in binary representation of X and Y. For example, f(2, 7) = 2, since binary representation of 2 and 7 are 010 and 111, respectively. The first and the third bit differ, so f(2, 7) = 2.

You are given an array of N positive integers, A1, A2 ,…, AN. Find sum of f(Ai, Aj) for all pairs (i, j) such that 1 ≤ i, j ≤ N. Return the answer modulo 109+7.

For example,

A=[1, 3, 5]

We return

f(1, 1) + f(1, 3) + f(1, 5) + 
f(3, 1) + f(3, 3) + f(3, 5) +
f(5, 1) + f(5, 3) + f(5, 5) =

0 + 1 + 1 +
1 + 0 + 2 +
1 + 2 + 0 = 8

*/

// Returns number of different bits in 2 numbers
int differentBits(int a,int b){
	int ans=0;
	// XOR value has those bits set which are different
	int xorValue = a^b;
	while(xorValue){
		// Reset one bit from right
		xorValue &= (xorValue-1);
		ans++;
	}
	return ans;
}
int previousSlowSolution(vector<int>&A,int n,int modulo){
	// For every pair calculate number of different bits
	int ans=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			ans += 2* differentBits(A[i],A[j]);
		}
		if(ans>=modulo)ans%=modulo;
	}
	return ans;
}
int Solution::cntBits(vector<int> &A) {

	int n = A.size();
	if(n==0)return 0;
	int ans=0;
	int modulo = pow(10,9)+7;

	// Previous slow solution
	// ans = previousSlowSolution(A,n,modulo);
	
	// For every bit position in a 32 bit integer, count the number of set bits
	for(int i=0;i<31;i++){
	    int count=0;
		for(int j=0;j<n;j++){
			if(A[j]&(1<<i)) count++;
		}
		// Total number of bits different at this position will be 2 * set bits * reset bits
		ans += count*(n-count)*2;	
		if(ans>modulo)ans%=modulo;
	}
	return ans;
}
