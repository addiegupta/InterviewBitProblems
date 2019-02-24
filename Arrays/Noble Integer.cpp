/*
InterviewBit : Noble Integer

Link : https://www.interviewbit.com/problems/noble-integer/


Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.


*/
int Solution::solve(vector<int> &A) {
    
    int n = A.size();
    sort(A.begin(),A.end());
    int j;
    for(int i=0;i<n;i++){
        int p = A[i];
        j=i+1;
        while(j<n && A[j]==A[i])j++;
        // if(j==i+1)j=i;
        if(n-j==p)return 1;
    }
    return -1;
}
