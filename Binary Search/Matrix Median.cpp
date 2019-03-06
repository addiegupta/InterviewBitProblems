/*
InterviewBit : Matrix Median

Link : https://www.interviewbit.com/problems/matrix-median/

Given a N cross M matrix in which each row is sorted, find the overall median of the matrix. Assume N*M is odd.

For example,

Matrix=
[1, 3, 5]
[2, 6, 9]
[3, 6, 9]

A = [1, 2, 3, 3, 5, 6, 6, 9, 9]

Median is 5. So, we return 5.
Note: No extra memory is allowed.

*/
int Solution::findMedian(vector<vector<int>> &A){

	int max=INT_MIN,min=INT_MAX;// max element will be right extreme while min will be on leftmost col
    int row = A.size();
    int col = A[0].size();
    // Get maximum and minimum values
    for(int i=0;i<row;i++){
        if(max < A[i][col-1])
            max = A[i][col-1];
        if(min > A[i][0])
            min = A[i][0];
    }
    
    // now we have max and min (why? because median will be somewhat around it)
    // median will be at position where exactly N/2 element will be less than it
    // so 
    // we can find how much element less than than specified element with upper bound
    int desired = (row*col+1)/2;
    int mid,less_than;
    while(min < max){
        mid = min + (max-min)/2;
        less_than = 0;
        for(int i=0;i<row;i++){
            less_than += (upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin());
        }
        if(less_than < desired){
            min = mid+1;
        }
        else{
            max = mid;
        }
    }
    return min; // (why min? as we want just N/2 element for which it is greater than)

}