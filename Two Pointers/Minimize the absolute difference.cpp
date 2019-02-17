/*
InterviewBit : Minimize the absolute difference

Link : https://www.interviewbit.com/problems/minimize-the-absolute-difference/


Asked in:  
Microsoft

Given three sorted arrays A, B and Cof not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.

Example :

Input:

A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]
Output:

1
Explanation: We get the minimum difference for a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.


*/

/* THIS PROBLEM IS SAME AS "ARRAY 3 POINTERS"--------------------------------------

 Explanation

Windowing strategy works here. 
Lets say the arrays are A,B and C.

Take 3 pointers X, Y and Z
Initialize them to point to the start of arrays A, B and C
Find min of X, Y and Z.
Compute max(X, Y, Z) - min(X, Y, Z).
If new result is less than current result, change it to the new result.
Increment the pointer of the array which contains the minimum.
Note that we increment the pointer of the array which has the minimum,
 because our goal is to decrease the difference. 
 Increasing the maximum pointer is definitely going to increase the difference. 
 Increase the second maximum pointer can potentially increase the difference
  ( however, it certainly will not decrease the difference ).

*/

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {

int minValue = INT_MAX, maxValue = INT_MIN, ans = INT_MAX;
	int x=A.size(),y=B.size(),z=C.size();
	
	for(int i=0,j=0,k=0;i<x && j<y && k<z;){
		minValue = min(A[i],min(B[j],C[k]));
		maxValue = max(A[i],max(B[j],C[k]));
		ans = min(ans,maxValue-minValue);

		if(ans==0)break;
		if(minValue==A[i])i++;
		else if(minValue==B[j])j++;
		else k++;
	}
	return ans;
}

