/*
InterviewBit : Palindrome String

Link : https://www.interviewbit.com/problems/palindrome-string/


Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

*/


// This solution first creates a copy of original string with only alphanumeric characters
// then checks if it is a palindrome
//
// O(n) time and O(n) space ------------------------------------------------------ 
int initialSolution(string A){
	// Filtered copy of A containing only alphanumeric characters ignoring cases in cases of alphabets and all other characters
    string B;
    int n = A.size();
    for(int i=0;i<n;i++){
        if(isalpha(A[i]) || (A[i]>='0' && A[i]<='9'))B.append(1,tolower(A[i]));
    }
    // new size
    n=B.size();
    // 1 letter has to be a palindrome
    if(n==1)return 1;
    // Iterators 
    int i,j;

    // Initialise iterators;
    // For even number of characters: i and j set to middle 2 elements
    // For odd number of characters: i is set to element to left of middle element, j is set to element to right of middle element
    // 	as middle element is irrelevant for palindrome property
    if(n%2!=0){
        i=(n/2)-1,j=(n/2)+1;
    }
    else{
        i=(n/2)-1,j=(n/2);
    }
    // Decrease i and increase j while values at both indices are equal
    while(i>=0 && j<n && B[i]==B[j]){
        i--;
        j++;
    }

    // Both iterators reached end -> string is palindrome
    return (i==-1 && j==n) ? 1 : 0;
}


// This solution simply skips over useless characters and checks for palindrome
// It is better than previous solution in terms of space complexity; also it is cleaner code and faster to write
//
// O(n) time and O(1) space complexity -------------------------------------------------
int newSlightlyImprovedSolution(string A){
	// First and last character
	int i =0,j=A.size()-1;
	while(i<j){
		// Skip over useless characters
		while(i<j && !isalnum(A[i]))i++;
		while(i<j && !isalnum(A[j]))j--;
		// Mismatching characters found; return 0
		if(toupper(A[i])!=toupper(A[j]))return 0;
		// Update iterators
		i++;
		j--;
	}
	// No mismatch; return 1
	return 1;
}
int Solution::isPalindrome(string A) {
    
    // return initialSolution(A);
    return newSlightlyImprovedSolution(A);
}
