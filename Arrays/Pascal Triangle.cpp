/*
InterviewBit : Pascal Triangle

Link : https://www.interviewbit.com/problems/pascal-triangle/

Asked in:  
Google
Amazon


Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]

*/
vector<vector<int> > Solution::solve(int A) {

   
   	// Base case
    if(A<=0)return {};

    vector<vector<int>> ans(A);
    
    // First row
    ans[0].push_back(temp);

    // Remaining rows created by observing previous rows
    for(int i=1;i<A;i++){
        for(int j=0;j<=i;j++){
            int ins=0;

            // Checking if index is present in previous row 
            if(j-1>=0)ins+=ans[i-1][j-1];
            if(j<i)ins+=ans[i-1][j];
            ans[i].push_back(ins);
        }
    }
    return ans;
}
