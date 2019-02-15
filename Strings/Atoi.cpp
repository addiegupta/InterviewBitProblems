/*
InterviewBit : Atoi

Link : https://www.interviewbit.com/problems/atoi/


Asked in:  
	
Adobe
Nvidia
Agilent systems
Bloomberg
Amazon
Groupon
Apple
Microsoft

Please Note:
There are certain questions where the interviewer would intentionally frame the question vague.
The expectation is that you will ask the correct set of clarifications or state your assumptions before you jump into coding.

Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

 Questions: Q1. Does string contain whitespace characters before the number?
A. Yes Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it. Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0. Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise. 
Warning : DO NOT USE LIBRARY FUNCTION FOR ATOI.
If you do, we will disqualify your submission retroactively and give you penalty points.


*/
bool isNum(int a){return a-'0'>=0 && a-'9'<=0;}
int Solution::atoi(const string A) {

	int ans=0;
	int n = A.size();
	
	// String iterator
	int i=0;

	// Sign of the number
	int sign =1;
	// Skip whitespaces
	while(A[i]==' ')i++;

	// Negative sign
	if(A[i]=='-'){
		sign =-1;
		i++;
	}

	// Positive sign
	else if(A[i]=='+') i++;

	// Iterate over string
	while(i<n){
		if(!isNum(A[i]))break;

		// Overflow
		if(ans > INT_MAX/10 || (ans == INT_MAX/10 && (A[i]-'0')>7)){
			if(sign==-1)return INT_MIN;
			else return INT_MAX;
		}

		// Add the digit to the answer
		ans = ans*10 + (A[i]-'0');
		i++;
	}
	return sign * ans;
}
