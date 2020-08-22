/*
InterviewBit : Min Sum Path in Triangle

Link : https://www.interviewbit.com/problems/min-sum-path-in-triangle/

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

 Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. 

*/
public class Solution {
    public int minimumTotal(ArrayList<ArrayList<Integer>> a) {
        int n = a.size();
        // Concept of solving using a matrix for dp, can be solved in array as well
        // At every point,dp[i] already contains the value for dp[i+1] when solving bottom to top of triangle
        int[] dp = new int[n];
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=i;j++){
                // Bottom row cost is simply cell value
                if(i==n-1)dp[j] = a.get(i).get(j);
                else{
                    // Add value of current cell + min cost from south or south-east cell
                    // Note that iteration of j cannot be from right to left as then we 
                    // will obtain value of east instead of south-east
                    dp[j] = a.get(i).get(j) + Math.min(dp[j],dp[j+1]);
                }
            }
        }
        return dp[0];
    }
    
}
