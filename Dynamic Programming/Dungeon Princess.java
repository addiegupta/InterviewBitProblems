/*
InterviewBit : Dungeon Princess

Link : https://www.interviewbit.com/problems/dungeon-princess/


The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0’s) or contain magic orbs that increase the knight’s health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Write a function to determine the knight’s minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path

RIGHT-> RIGHT -> DOWN -> DOWN.

Dungeon Princess: Example 1

-------------------------
|	-2	 |	-3	|	3	|
|	-5	 |	-10 |	1	|
|	10	 |	30	|  -5	|
-------------------------


Input arguments to function:
Your function will get an M*N matrix (2-D array) as input which represents the 2D grid as described in the question. Your function should return an integer corresponding to the knight’s minimum initial health required.



 Note:
The knight’s health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

*/
public class Solution {
    public int calculateMinimumHP(ArrayList<ArrayList<Integer>> A) {
        
        // Row and column count
        int m = A.size();
        int n = A.get(0).size();

        // Stores the minimum knight health required while entering the corresponding room
        int[][] dp = new int[m][n];

        // Stores the best adjacent (down or right) room dp value to minimise required initial health
        // Another way to phrase it: best stores the min value of health required while exiting the room
        int best;
        // Start from bottom right corner; reverse traversal
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
            	// Reached corner; final health should be at least 1
                if(j==n-1&& i==m-1)best = 1;
                // Only south room available
                else if(j==n-1)best = dp[i+1][j];
                // Only east room available
                else if(i==m-1)best = dp[i][j+1];
                // Pick the room which requires min entry health
                else best = Math.min(dp[i+1][j],dp[i][j+1]);
                
                // While minimizing health, if this room replenishes health, then minimum entry health still needs to be 1 as 0 and below is not applicable
                // Exit health - health addition(or subtraction) in this room = min required entry health
                dp[i][j] = Math.max(1, best - A.get(i).get(j));
            }
        }
        // Min health required before entering first room
        return dp[0][0];
    }
}