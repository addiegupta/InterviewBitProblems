/*

InterviewBit : Minimum Characters required to make a String Palindromic

Link : https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/

You are given a string. The only operation allowed is to insert characters in the beginning of the string. How many minimum characters are needed to be inserted to make the string a palindrome string

Example:
Input: ABC
Output: 2
Input: AACECAAAA
Output: 2


*/

/** Problem is solved using KMP pattern matching

Answer to the problem is |S| - |LPP|.
Where |S| is the length of the input string and |LPP| is the length of longest palindromic prefix of the input string.

Why? Let’s assume we have string of the form S = PR, where P is longest possible palindrome and R is the rest of the string.
To transform S into palindrome we should insert R characters at the beginning of the string. So finally string will have form RPR.
For example, let’s consider AACECAAAA string. Longest palindromic prefix is AACECAA. The rest of the characters are AA.
So to make full string palindromic we should add AA at the beginning of the string, ie final string = AA + AACECAA + AA.

But how to find length of longest palindromic prefix?
Let’s calculate LSP for string of the form S + ‘#’ + reversed S, for example: AACECAAAA#AAAACECAA.
Last element of LSP is the length of longest prefix-suffix of the entire string (AACECAA in our case -> AACECAA|AA#AA|AACECAA).
But it is also length of longest palindromic prefix of input string.
First part of the combined string is input string and the second part is reversed string.
So when some prefix is the suffix of the entire string it means that the prefix is palindromic.

Finally, we calculated |LPP|, so we can return answer as |S| - |LPP|.


*/
void computeKmpLps(int lps[],string x);
int Solution::solve(string A) {


	int n = A.length();

	string B = A + '$';
	reverse(A.begin(),A.end());
	
    B+=A;
	
    int lps[n*2 + 1];
	
    computeKmpLps(lps,B);
	
    return n - lps[n*2];
}
void computeKmpLps(int lps[], string x){
    int i=1,m=x.length(),len=0;

    lps[0] = 0; // lps[0] is always 0 
  
    // the loop calculates lps[i] for i = 1 to M-1 
    while (i < m) 
    { 
        if (x[i] == x[len]) 
        { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (str[i] != str[len]) 
        { 
            // This is tricky. Consider the example. 
            // AAACAAAA and i = 7. The idea is similar 
            // to search step. 
            if (len != 0) 
            { 
                len = lps[len-1]; 
  
                // Also, note that we do not increment 
                // i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 

}