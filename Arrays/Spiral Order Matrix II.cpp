/*
InterviewBit : Spiral Order Matrix II

Link : https://www.interviewbit.com/problems/spiral-order-matrix-ii/

Asked in:  

 
Microsoft
JP Morgan
Amazon


Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Given n = 3,

You should return the following matrix:

[
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
]

*/
vector<vector<int> > Solution::generateMatrix(int n) {
    
    int row[] = {0,1,0,-1};
    int col[] = {1,0,-1,0};
    vector<vector<int>> ans;
    if(n<=0)return ans;
    int mat[n][n];
    for(int u=0;u<n;u++){
        for(int v=0;v<n;v++){
            mat[u][v]=0;
        }
    }
    int count = (n*n)-1;
    int i=0,j=0;
    int index=0;
    int val=1;
    mat[0][0]=1;
    while(count--){
        if((i+row[index]<0) || (i+row[index]==n)||(j+col[index]<0)||(j+col[index]==n)){
            index++;
        }
        else if(mat[i+row[index]][j+col[index]]!=0)index++;
        
        if(index==4)index=0;
        i+=row[index];
        j+=col[index];
        mat[i][j]=++val;
    }
    vector<int> temp;
    for(int u=0;u<n;u++){
        for(int v=0;v<n;v++){
            temp.push_back(mat[u][v]);
        }
        ans.push_back(temp);
        temp.clear();
    }
    return ans;
}
