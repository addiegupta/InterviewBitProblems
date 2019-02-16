/*
InterviewBit : Roman to Integer

Link : https://www.interviewbit.com/problems/roman-to-integer/

Asked in

Facebook
Amazon
Microsoft
Twitter

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Read more details about roman numerals at Roman Numeric System

Example :

Input : "XIV"
Return : 14
Input : "XX"
Output : 20

*/

int romanToInt(char A){
	switch(A){
		case 'I':return 1;
		case 'V':return 5;
		case 'X':return 10;
		case 'L':return 50;
		case 'C':return 100;
		case 'D':return 500;
		case 'M':return 1000;
	}
}

int interviewBitSolution(string A){
	int n = A.size();
	int ans=0;
	for(int i=0;i<n;i++){
		int roman = romanToInt(A[i]);
		if((i!=n-1)&& (roman < romanToInt(A[i+1]))) ans-=roman;
		else ans+=roman;
	}
	return ans;
}

int customHardcodedApproach(string A){
	int ans=0;
	int n =A.length();
	for(int i=0;i<n;i++){
		char c = A[i];
		switch(c){
			case 'I': (i!=n-1 && (A[i+1] == 'V' ||A[i+1] == 'X'))?ans--:ans++;
						break;
			case 'V': 	ans+=5;
						break;
			case 'X': (i!=n-1 && (A[i+1] == 'L'||A[i+1] == 'C'))?ans -=10:ans+=10;
						break;
			case 'L':	ans+=50;
						break;
			case 'C':	(i!=n-1 && (A[i+1] == 'D' ||A[i+1] == 'M'))?ans -=100:ans+=100;
						break;
			case 'D':	ans+=500;
						break;
			case 'M':	ans+=1000;
						break;
			default: break;
		}
	}
	return ans;
}
int Solution::romanToInt(string A) {
 
 	// return customHardcodedApproach(A);// not clean and slow to type
	return interviewBitSolution(A);// cleaner and faster to type code	
}


