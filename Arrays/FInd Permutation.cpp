/*
InterviewBit : Find Permutation

Link : https://www.interviewbit.com/problems/find-permutation/

Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Notes

Length of given string s will always equal to n - 1
Your solution should run in linear time and space.
Example :

Input 1:

n = 3

s = ID

Return: [1, 3, 2]


*/
vector<int> Solution::findPerm(const string A, int B) {
	
	int n=A.length();
	assert(n==B-1);
	int l=1,r=n+1;
	vector<int> ans;
	for(int i=0;i<n;i++){
		(A[i]=='I')?ans.push_back(l++):ans.push_back(r--);
	}
	ans.push_back(l);
	return ans;
}
