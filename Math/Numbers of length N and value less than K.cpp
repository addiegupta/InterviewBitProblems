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
vector <int> numToVec(int N) {   
    vector<int> digit;
    while(N != 0) {
        digit.push_back(N % 10);
        N = N / 10;
    }
    if(digit.size() == 0)
        digit.push_back(0);

    reverse(digit.begin(), digit.end());
    return digit; 
}

int Solution:: solve(vector<int> &A, int B, int C) {
    vector<int> digit;
    int  d, d2;
    // Convert number to digit array
    digit = numToVec(C);
    d = A.size();

    //Case 1: Number of digits required are greater than digits in greatest number allowed
    // Answer is 0
    if(B > digit.size()  || d == 0)
        return 0;

    // Case 2: Number of digits required are less than digits in greatest number
    // Permutations will be formed as per (number of possible digit values)^B ( i.e. the total digits)
    else if(B < digit.size()) {
        // Handling of 0; 0 cannot be present in the greatest digit place in a number with more than 1 digits
        if(A[0] == 0 && B != 1)
            return (d - 1) * pow(d, B - 1);
        else 
            return pow(d, B);
    }

    //Case 3: number of digits required is equal to digits in greatest number
    else {
          int dp[B + 1], lower[11];
          for(int i = 0; i <= B; i++)
              dp[i] = 0;

          for(int i = 0; i <= 10; i++)
              lower[i] = 0;
          
          for(int i = 0; i < d; i++)
              lower[A[i] + 1] = 1;

          for(int i = 1; i <= 10; i++)
              lower[i] += lower[i-1]; 

          bool flag = true;
          dp[0] = 0;
          for(int i = 1; i <= B; i++) {
              d2 = lower[digit[i-1]];
              dp[i] = dp[i-1] * d;

              // For first index we can't use 0
             if(i == 1 &&  A[0] == 0 && B != 1)
                 d2 = d2 - 1;

             //Whether (i-1) digit of generated number can be equal to (i - 1) digit of C.
             if(flag)
                 dp[i] += d2;
             //Is digit[i - 1] present in A ?
                flag = flag & (lower[digit[i-1] + 1] == lower[digit[i-1]] + 1);
        }
    return dp[B];                   
    } 
}
