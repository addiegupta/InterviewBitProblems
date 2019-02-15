/*
InterviewBit : Remove Duplicates from Sorted Array

Link : https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/


Asked in:  
United Healthgroup
Amazon
Google
Microsoft
Expedia


Remove duplicates from Sorted Array
Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.

Note that even though we want you to return the new length, make sure to change the original array as well in place

Do not allocate extra space for another array, you must do this in place with constant memory.

 Example: 
Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2]. 


*/
int Solution::removeDuplicates(vector<int> &A) {

    int n = A.size();
    int j=0;
    for(int i=0;i<n;i++){
		// Found duplicate element, skip setting this value at index j
	    if(i<n-1 && A[i]==A[i+1])continue;
    	
    	A[j]=A[i];
    	j++;
    }
    return j;
}