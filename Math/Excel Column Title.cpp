/*
InterviewBit : Excel Column Title

Link : https://www.interviewbit.com/problems/excel-column-title/

Asked in:  
Amazon

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

*/
string Solution::convertToTitle(int A) {

	string ans;

	while(A){
		// Get letter
        ans += ((A - 1) % 26 + 'A');
        
        // Divide by 26 
        A = (A - 1) / 26;
	}
	reverse(ans.begin(),ans.end());
	return ans;

}
