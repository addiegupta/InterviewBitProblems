/*
InterviewBit : Coins in a Line

Link : https://www.interviewbit.com/problems/coins-in-a-line/

There are N coins (Assume N is even) in a line. Two players take turns to take a coin from one of the ends of the line until there are no more coins left. The player with the larger amount of money wins. Assume that you go first.

Write a program which computes the maximum amount of money you can win.

Example:

suppose that there are 4 coins which have value
1 2 3 4
now you are first so you pick 4
then in next term
next person picks 3 then
you pick 2 and
then next person picks 1
so total of your money is 4 + 2 = 6
next/opposite person will get 1 + 3 = 4
so maximum amount of value you can get is 6


*/

// Tough question!!
int Solution::maxcoin(vector<int> &A) {
    

    int n = A.size();
    
    // First element stores the value obtained by player going first
    // Second element for second player
    pair<int,int> dp[n][n];
    memset(dp,0,sizeof(dp));

    // The dp matrix at index(i,j) contains a pair of values which contains the max values of coin sum 
    // for first and second player as first and second values respectively if the coins present were just the subset (i,j)
    // e.g the pair (9,3) at index 1,3 denotes that if only the subset of coins from index 1 to 3 is present, then 
    // the player going first gets max 9 value while player going second gets 3

    // Main Diagonal elements; only 1 coin is present, first player gets the coin second player gets 0
    for(int i=0;i<n;i++){
        dp[i][i].first = A[i];
        dp[i][i].second = 0;
    }

    // Rest of the elements created diagonally
    // After the main diagonal every subsequent diagonal to the right is filled
    for(int k=1;k<n;k++){
        for(int i=0,j=k;j<n;i++,j++){

            // the 2 options available to player 1

            // Starting coin is chosen, opponent then chooses the best value(i.e. first element)
            // for the remaining subset and then player chooses the remaining value for the subset(i.e. second element)
            int opt1 = A[i] + dp[i+1][j].second;

            // Similar to previous case, just this time the coin at end is chosen
            int opt2 = A[j] + dp[i][j-1].second;

            // If player 1 chooses opt1
            if(opt1>opt2){
                dp[i][j].first = opt1;
                dp[i][j].second = dp[i+1][j].first;
            }
            // Player 1 chooses opt2
            else{
                dp[i][j].first = opt2;
                dp[i][j].second = dp[i][j-1].first;
            }
        }
    }

    // dp[0][n-1] denotes that the entire coin set 0 to n-1 is present
    // the first element represents the max value obtained by the player going first
    return dp[0][n-1].first;
}
