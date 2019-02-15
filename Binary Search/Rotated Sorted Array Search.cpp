/*
InterviewBit : Rotated Sorted Array Search

Link : https://www.interviewbit.com/problems/rotated-sorted-array-search/


Asked in:  
	
Facebook
Google
Amazon
Microsoft

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).

You are given a target value to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Input : [4 5 6 7 0 1 2] and target = 4
Output : 0

NOTE : Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*


*/

int Solution::search(const vector<int> &A, int B) {
	
	int n = A.size();
    int low = 0, high = n-1,mid;
    
    // Binary Search
    while(low<=high){
        mid = low + (high-low)/2;
        
        // Element found
        if(A[mid] == B) return mid;

        // left part is sorted
        else if(A[0]<=A[mid]){

            //B lies on left part
            if(A[0]<=B && B < A[mid]) high = mid-1;
            else low = mid+1;
        }

        // right part is sorted
        else{
            //B lies on right part
            if(A[mid] < B && B<=A[n-1]) low = mid+1;
            else high = mid-1;
        }
    }

    // Not found
    return -1;
}