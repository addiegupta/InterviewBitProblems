/*
InterviewBit : Longest Common Prefix

Link : https://www.interviewbit.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".

Given the array of strings, you need to find the longest S which is the prefix of ALL the strings in the array.

Example:

Given the array as:

[

  "abcdefgh",

  "aefghijk",

  "abcefgh"
]
The answer would be “a”.


*/
string Solution::longestCommonPrefix(vector<string> &A) {
	string ans;
	int n = A.size();
	if(n==1)return A[0];
	for(int i=0;i<A[0].length();i++){
		if(i>=A[0].length())return ans;
		char c = A[0][i];
		for(int j=1;j<n;j++){
			if(i>=A[j].length())return ans;
			if(A[j][i]!=c)return ans;
		}
		ans.append(1,c);
	}
	return ans;

}
