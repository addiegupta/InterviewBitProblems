/*
InterviewBit : Numbers of length N and value less than K

Link : https://www.interviewbit.com/problems/numbers-of-length-n-and-value-less-than-k/

Given a set of digits (A) in sorted order, find how many numbers of length B are possible whose value is less than number C.

 NOTE: All numbers can only have digits from the given set. 
Examples:

	Input:
	  0 1 5  
	  1  
	  2  
	Output:  
	  2 (0 and 1 are possible)  

	Input:
	  0 1 2 5  
	  2  
	  21  
	Output:
	  5 (10, 11, 12, 15, 20 are possible)
Constraints:

    1 <= B <= 9, 0 <= C <= 1e9 & 0 <= A[i] <= 9


*/

vector<int> numToVec(int C);
int Solution::solve(vector<int> &A,int B,int C){

    // Count of digits that can be used
    int n = A.size();

    // Convert C to a vector of digits
    vector<int> valueDigits = numToVec(C);
    int numOfDigits = valueDigits.size();

    // Case 1: No solution is possible as required length is greater than length of C value
    if(B>numOfDigits || n==0) return 0;

    // Case 2: Straightforward solution for required length less than C value length
    if(B<numOfDigits){

        // First digit cannot be 0 if length greater than 1
        if(A[0]==0 && B!=1){
            return (n-1) * pow(n,B-1);
        }
        // All combinations of the digits
        else return pow(n,B);
    }

    // Case 3: Required length of values is same as the length of C
    // Hence numbers need to be only selected if value is less than C value
    //
    // 1 by 1 each digit of C is considered 
    // e.g. if C is 213
    // then numbers are counted for 2 first
    // then for 21
    // then for 213. Hence dynamic programming is used

    // lower stores the number of elements in A having value less than i
    // dp stores the solution for first i digits of C
    // Hence answer will be dp[B]
    int lower[11],dp[B+1];
    memset(lower,0,sizeof(lower));
    memset(dp,0,sizeof(dp));

    // Create lower array 
    // e.g. for A = {0,1,2,5,7},  lower array is [0,1,2,3,3,3,4,4,5,5,5]
    for(int i=0;i<n;i++) lower[A[i]+1]=1;
    for(int i=1;i<=10;i++) lower[i] += lower[i-1];

    // 0 length has 0 combinations
    dp[0] = 0;
    
    // Boolean flag to check if the current digit being processed is present in A
    // This is needed for the cases where number is very close to the C value
    // e.g. C is 257, A is [0, 1, 2, 3,5] 
    // Now while processing C only for 25 we need to check if 5 exists in A as if 5 does not exist then combinations like
    // 250,251,252,252,255 cannot be counted. Hence if flag is once set to false it cannot be set to true again (check line 107)
    bool flag = true;

    // Stores number of combinations possible for this digit having value less than current digit in valueDigits
    int numberOfCombinations;
    for(int i=1;i<=B;i++){

        // Number of digits having value less than current digit
        // e.g. for C = 257 and i = 1, the part of C being considered is 2
        // therefore numberOfCombinations = number of digits less than 2 
        numberOfCombinations = lower[valueDigits[i-1]];


        // n is the number of digits available for use
        // for every combination formed of length i-1, n combinations can be formed by appending 1 of the n digits at end
        dp[i] = dp[i-1] * n;

        // First digit cannot be 0
        if(A[0]==0 && i==1 && B!=1)numberOfCombinations--;
        
        // If (i-1)th digit of generated numbers can be equal to (i-1)th digit of C, then increase the combinations which
        // were not counted in previous case i.e. when lower elements were considered and not the element itself
        // e.g. C is 257 , A is [0,1,2,3,4,5] then while processing only 2, the elements less than 2 were considered i.e. 0 and 1
        // Hence the cases starting with 2 will be considered in next case
        if(flag) dp[i] += numberOfCombinations;

        // Flag is true if it was never false before and if the valueDigits[i-1] is present in A
        flag &= (lower[valueDigits[i-1]]+1 == lower[valueDigits[i-1]+1]);

    }
    return dp[B];
}

// Converts integer C to a vector of digits
vector<int> numToVec(int C){
    vector<int> ans;
    while(C){
        ans.push_back(C%10);
        C/=10;
    }
    if(ans.empty())ans.push_back(0);
    reverse(ans.begin(),ans.end());
    return ans;
}
