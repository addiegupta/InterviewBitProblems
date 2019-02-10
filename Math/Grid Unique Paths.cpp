/*
InterviewBit : Grid Unique Paths

Link : https://www.interviewbit.com/problems/grid-unique-paths/

Asked in 

Google
Amazon
Adobe
Microsoft

A robot is located at the top-left corner of an A x B grid (marked ‘Start’ in the diagram below).

Path Sum: Example 1

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).

How many possible unique paths are there?

Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

Example :

Input : A = 2, B = 2
Output : 2

2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)

*/

// Combinatorics Solution
int Solution::uniquePaths(int A,int B){
	// There are total A+B-2 paths to reach A-1,B-1
	// Total A-1 down moves and B-1 right moves need to be made
	// Hence answer is A+B-2             A+B-2
	//						C       or        C
	//						 A-1				B-1
	// which is equal to (A+B-2)!/(A-1)!(B-1)!
	int ans =1;
	for(int i=A;i<A+B-1;i++){
		ans *= i;
		ans /= (i-A+1); 
	}
	return ans;
}

// DP Solution
int Solution::uniquePaths(int A, int B) {
	int dp[A][B];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=0;i<A;i++){
		for(int j=0;j<B;j++){
			if(i==0&&j==0)continue;
			if(i-1>=0)dp[i][j]+=dp[i-1][j];
			if(j-1>=0)dp[i][j]+=dp[i][j-1];
		}
	}
	return dp[A-1][B-1];
}

