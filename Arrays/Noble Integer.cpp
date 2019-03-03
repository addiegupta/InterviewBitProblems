/*
InterviewBit : Noble Integer

Link : https://www.interviewbit.com/problems/noble-integer/


Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.


*/
int Solution::solve(vector<int> &A) {
    
    int n = A.size();
	
	// Sort the array
	sort(A.begin(),A.end());

    for(int i=0;i<n;i++){
    	// Skip duplicates
        while(i+1<n && A[i]==A[i+1])i++;
        // Now if number of elements greater than current element
        // i.e. to the right of this element is equal to A[i] then return true
        if(A[i]==n-i-1)return 1;
    }
    // No solution found; return -1
    return -1;
}
