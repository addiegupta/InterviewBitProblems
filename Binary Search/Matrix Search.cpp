/*
InterviewBit : Matrix Search

Link : https://www.interviewbit.com/problems/matrix-search/



Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than or equal to the last integer of the previous row.
Example:

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return 1 ( 1 corresponds to true )

Return 0 / 1 ( 0 if the element is not present, 1 if the element is present ) for this problem

*/
// Treats the matrix as a one 1D array and applies binary search
int OLogNMSolution(vector<vector<int>> &A, int B){

	int m = A.size();
	int n = A[0].size();
	int l = 0,r = m*n-1;
	int mid,ele;
	while(l<=r){
		mid = l + (r-l)/2;
		ele = A[mid/n][mid%n];
		if(ele==B)return 1;
		else if(ele>B)r = mid-1;
		else l = mid +1;
	}
	return 0;
}
// Binary search on first element of every array followed by binary search of the array 
// chosen in previous step
int OLogNLogMSolution(vector<vector<int>> &A,int B){
	int m = A.size();
	int n = A[0].size();
	int low=0,high = m-1;
	int mid;
	while(low<=high){

		mid = low + (high - low)/2;
		if(A[mid][0]==B)return 1;
		else if(A[mid][0]>B)high=mid-1;
		else low=mid+1;
	}

	 if(low!=0)low--;
	int row = low;
	low=0,high=n-1;
	while(low<=high){
		mid = low + (high - low)/2;
		if(A[row][mid]==B)return 1;
		else if(A[row][mid]>B)high=mid-1;
		else low=mid+1;
	}
	return 0;
}
int Solution::searchMatrix(vector<vector<int> > &A, int B) {

	return OLogNMSolution(A,B);
	// return OLogNLogMSolution(A,B);
}