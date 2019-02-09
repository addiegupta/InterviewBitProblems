/*
InterviewBit : Rearrange Array

Link : https://www.interviewbit.com/problems/rearrange-array/

Asked in 

Facebook

Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.

Example:

Input : [1, 0]
Return : [0, 1]
 Lets say N = size of the array. Then, following holds true :
All elements in the array are in the range [0, N-1]
N * N does not overflow for a signed integer

*/

// The solution is to encode 2 numbers in one
// i.e. store the new value as a multiple of n
// To access old value use A[i]%n, to access new value use A[i]/n
void Solution::arrange(vector<int> &A) {
	int n = A.size();

	for(int i=0;i<n;i++) A[i] += (A[A[i]]%n)*n;
	for(int i=0;i<n;i++) A[i]/=n;

}
