/*
InterviewBit : Array 3 Pointers

Link : https://www.interviewbit.com/problems/array-3-pointers/


Asked in:  
Google
Microsoft
Yahoo

You are given 3 arrays A, B and C. All 3 of the arrays are sorted.

Find i, j, k such that :
max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))

**abs(x) is absolute value of x and is implemented in the following manner : **

      if (x < 0) return -x;
      else return x;
Example :

Input : 
        A : [1, 4, 10]
        B : [2, 15, 20]
        C : [10, 12]

Output : 5 
         With 10 from A, 15 from B and 10 from C.


*/
/*
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

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
	
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
