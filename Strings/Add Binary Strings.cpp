/*
InterviewBit : Add Binary Strings

Link : https://www.interviewbit.com/problems/add-binary-strings/

Asked in

Facebook

Given two binary strings, return their sum (also a binary string).

Example:

a = "100"

b = "11"
Return a + b = “111”.

*/
string Solution::addBinary(string A, string B) {

	
	string ans;
	int i = A.length()-1,j = B.length()-1;
	int sum=0,carry=0;
	while(i>=0 || j>=0 || carry){
		sum = carry;
		if(i>=0)sum += A[i]-'0';
		if(j>=0)sum += B[j]-'0';

		// Add first digit 
		ans.push_back((sum%2)+'0');
		// Carry is the second digit
		carry = sum/2;
		i--;
		j--;
	}
	reverse(ans.begin(),ans.end());
	return ans;

}
