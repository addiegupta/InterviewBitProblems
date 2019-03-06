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

	// Stores longest common prefix
	string ans;
	
	int n = A.size();
	char c;
	
	// Entire string is answer
	if(n==1)return A[0];

	for(int i=0;i<A[0].length();i++){
	
		// Traverse over the strings
		for(int j=0;j<n;j++){
			
			// Length of string is shorter than required index
			if(i>=A[j].length())return ans;
			
			// Get character at index i in first string
			if(j==0)c=A[0][i];
			
			// Different character found
			if(j!=0 && A[j][i]!=c)return ans;
		}
		ans.append(1,c);
	}
	return ans;

}
