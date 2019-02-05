/*
InterviewBit : Set Matrix Zeros

Link : https://www.interviewbit.com/problems/set-matrix-zeros/

Asked in:  
Oracle
Amazon

Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.

Do it in place.

Example

Given array A as

1 0 1
1 1 1 
1 1 1
On returning, the array A should be :

0 0 0
1 0 1
1 0 1
Note that this will be evaluated on the extra memory used. Try to minimize the space and time complexity.

*/
void Solution::setZeroes(vector<vector<int> > &A) {
	
	// iterator variables
	int i,j;
	
	// row and column dimenstions
	int m =A[0].size(),n=A.size();

	// bool to store if row and column need to be set as 0 
	bool rowFlag = false,colFlag =false;
	for(j=0;j<m;j++){
		if(A[0][j]==0){
			rowFlag=true;
			break;
		}
	}
	for(i=0;i<n;i++){
		if(A[i][0]==0){
			colFlag=true;
			break;
		}
	}

	// Store info of rest of matrix in first row and first column
	for(i=1;i<n;i++){
		for(j=1;j<m;j++){
			if(A[i][j]==0){
				A[0][j]=0;
				A[i][0]=0;
			}
		}
	}
	
	// Mark rows and columns as 0 where required
	for(i=1;i<n;i++){
		for(j=1;j<m;j++){
			if(A[0][j]==0 || A[i][0]==0)A[i][j]=0;
		}
	}

	// as per bools stored earlier, mark first row and first column
	if(colFlag){
		for(i=0;i<n;i++){
			A[i][0]=0;
		}
	}
	if(rowFlag){
		for(j=0;j<m;j++){
			A[0][j]=0;
		}
	}
}
