/*
InterviewBit : Anti Diagonals

Link : https://www.interviewbit.com/problems/anti-diagonals/

Asked in 

Microsoft
Adobe


Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:

        
Input:  

1 2 3
4 5 6
7 8 9

Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]


Input : 
1 2
3 4

Return the following  : 

[
  [1],
  [2, 3],
  [4]
]





*/
vector<vector<int>> Solution::diagonal(vector<vector<int> > &A) {

    int n = A.size();
    vector<vector<int>> ans;
    vector<int> temp;
    for(int i=0;i<(n-1)*2+1;i++)ans.push_back(temp);
    if(n==0)return ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i+j].push_back(A[i][j]);
        }
    }
    return ans;

}