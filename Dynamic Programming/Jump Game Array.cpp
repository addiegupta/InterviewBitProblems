/*
InterviewBit : Jump Game Array

Link : https://www.interviewbit.com/problems/jump-game-array/


Asked in:
Amazon
Ebay

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return 1 ( true ).

A = [3,2,1,0,4], return 0 ( false ).

Return 0/1 for this problem


*/
int Solution::canJump(vector<int> &A) {

    int n = A.size();
    if(n==0 || (A[0]==0&&n!=1))return 0;
    int minIndex = n-1;
    bool possible;
    for(int i=n-2;i>=0;i--){
        possible = false;
        if(i+A[i]>=minIndex){
            possible = true;
            minIndex = i;
        }
    }
    return possible;
}
