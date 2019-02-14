/*
InterviewBit : Reverse the String

Link : https://www.interviewbit.com/problems/reverse-the-string/

Asked in 

Qualcomm
Amazon
Cisco
Facebook
Microsoft

Given an input string, reverse the string word by word.

Example:

Given s = "the sky is blue",

return "blue is sky the".

A sequence of non-space characters constitutes a word.
Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
If there are multiple spaces between words, reduce them to a single space in the reversed string.


*/
// Reverse characters in string from index i to j using swapping
void rev(string &A,int i,int j){
	while(i<j){
		char temp = A[i];
		A[i]=A[j];
		A[j]=temp;
		// swap(A[i],A[j]);
		i++;
		j--;
	}
}
void Solution::reverseWords(string &A) {
	// Reverse all characters
	reverse(A.begin(),A.end());

	// Iterators and size
	int i=0,j=0;
	int n= A.size();

	while(j<n){
		
		// Last character; reverse this word
		if(j==n-1){
			rev(A,i,j);
			break;
		}
		// Found a complete word;reverse it
		if(A[j]==' '){
			rev(A,i,j-1);
			i=j+1;
		}
		j++;
	}
}
