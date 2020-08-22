/*
InterviewBit : Unique Paths in a Grid

Link : https://www.interviewbit.com/problems/unique-paths-in-a-grid/


Asked in:  
Facebook


Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y).

Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Example :
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

 Note: m and n will be at most 100.


*/
public class Solution {
    public int uniquePathsWithObstacles(ArrayList<ArrayList<Integer>> A) {
        
        int m = A.size();
        int n = A.get(0).size();
        
        // matrix dp being solved using only an array, by containing the south value in the same cell
        int[] dp = new int[n];
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                
                // IF this cell is an obstacle, paths from here is 0
                if(A.get(i).get(j) == 1)dp[j]=0;
                else {
                    // Destination; unique path is 1
                    if(i==m-1 && j==n-1){
                        dp[j]=1;
                    }
                    // Bottom row; unique path is only by going right
                    else if(i==m-1){
                        dp[j] = dp[j+1];
                    }
                    // For last column, nothing is to be done as it already contains the south value
                    else if(j!=n-1){
                        // For others, simply add unique paths from south and east
                        dp[j] += dp[j+1];
                    }
                }
            }
        }
        return dp[0];
    }
}
