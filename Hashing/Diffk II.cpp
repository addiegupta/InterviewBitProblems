/*
InterviewBit : Diffk II

Link : https://www.interviewbit.com/problems/diffk-ii/

Asked in:
Facebook


Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

Example :

Input :

A : [1 5 3]
k : 2
Output :

1
as 3 - 1 = 2

Return 0 / 1 for this problem.


*/

int Solution::diffPossible(const vector<int> &A, int B) {
	

	int n = A.size();
	// Hash to store previous numbers
	unordered_set<int> hash;

	for(int i=0;i<n;i++){

		// Check if curr no. +- B is present in hash, return 1
		if(hash.find(A[i]-B) !=hash.end() || hash.find(A[i]+B)!=hash.end())return 1;
		
		// Else add this number to hash and continue loop
		hash.insert(A[i]);
	}
	return 0;
}
