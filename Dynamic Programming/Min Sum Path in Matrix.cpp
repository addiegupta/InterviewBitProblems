/*
InterviewBit : Min Sum Path in Matrix

Link : https://www.interviewbit.com/problems/min-sum-path-in-matrix/


Asked in:
Amazon

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

 Note: You can only move either down or right at any point in time. 
Example :

Input : 

    [  1 3 2
       4 3 1
       5 6 1
    ]

Output : 8
     1 -> 3 -> 2 -> 1 -> 1


*/
int Solution::minPathSum(vector<vector<int> > &A) {
    
    // Number of rows and number of columns
    int m = A.size();
    int n = A[0].size();

    int dp[m][n];
    memset(dp,0,sizeof(dp));
    
    // Solve the problem for every point in the A matrix
    // Thus using subproblems we can reach the solution for last element of matrix
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){

            // Add weight of current position to path sum
            dp[i][j] = A[i][j];

            // Not the first element
            if(i!=0 || j!=0){

                // First row; choose path from left
                if(i==0) dp[i][j] += dp[i][j-1];
                // First column; choose path from up
                else if(j==0) dp[i][j] += dp[i-1][j];

                // Choose the path which has min sum between path from top and left
                else dp[i][j] += min(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[m-1][n-1];
}