/*
InterviewBit : MAXSPPROD

Link : https://www.interviewbit.com/problems/set-matrix-zeros/

You are given an array A containing N integers. The special product of each ith integer in this array is defined as the product of the following:<ul>

LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (i>j). If multiple A[j]’s are present in multiple positions, the LeftSpecialValue is the maximum value of j. 

RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (j>i). If multiple A[j]s are present in multiple positions, the RightSpecialValue is the minimum value of j.

Write a program to find the maximum special product of any integer in the array.

Input: You will receive array of integers as argument to function.

Return: Maximum special product of any integer in the array modulo 1000000007.

Note: If j does not exist, the LeftSpecialValue and RightSpecialValue are considered to be 0.

Constraints 1 <= N <= 10^5 1 <= A[i] <= 10^9

*/
// Creates Left Special Value Array 
vector<int> getLeftArray(vector<int> &A,int n){
	// Contains values in strictly decreasing order
	// Going left to right
	stack<int> lStack;
	vector<int> la(n,0);

	lStack.push(0);
	la[0]=0;
	for(int i=1;i<n;i++){
		while(!lStack.empty()){
			// Found higher value
			if(A[i]<A[lStack.top()])break;
			lStack.pop();
		}
		// 0 if no value found else the higher value
		la[i]=(lStack.empty())?0:lStack.top();
		lStack.push(i);
	}
	return la;
}
// Creates Right Special Value Array similar to leftarray
vector<int> getRightArray(vector<int> &A,int n){
	stack<int> rStack;
	vector<int> ra(n,0);

	rStack.push(n-1);
	ra[n-1]=0;
	for(int i=n-2;i>=0;i--){
		while(!rStack.empty()){
			if(A[i]<A[rStack.top()])break;
			rStack.pop();
		}
		ra[i]=(rStack.empty())?0:rStack.top();
		rStack.push(i);
	}
	return ra;
}
int Solution::maxSpecialProduct(vector<int> &A) {
	int n = A.size();
	vector<int> leftArray = getLeftArray(A,n);
	vector<int> rightArray = getRightArray(A,n);
	long long mx=0;
	for(int i=1;i<n-1;i++){
		mx = max(mx,leftArray[i]*1LL*rightArray[i]);
	}
	return mx % ((int)pow(10,9)+7);
}

