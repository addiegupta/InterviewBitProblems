/*
InterviewBit : Sorted Insert Position

Link : https://www.interviewbit.com/problems/sorted-insert-position/


Asked in:  
	
Yahoo

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.

[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

*/

// Binary search for number or if number doesnt exist, then find the index where it should have existed
int Solution::searchInsert(vector<int> &A, int B) {
	int n = A.size();
	int l=0,r=n-1,mid;
	
	while(l<=r){
		mid = l + (r-l)/2;
		if(A[mid]==B) return mid;
		else if (A[mid]>B) r= mid-1;
		else if (A[mid]<B) l = mid+1;
	}
	
	return l;
}