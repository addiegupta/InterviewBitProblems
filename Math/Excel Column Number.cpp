/*
InterviewBit : Excel Column Number

Link : https://www.interviewbit.com/problems/excel-column-number/

Asked in:  
Amazon

Given a column title as appears in an Excel sheet, return its corresponding column number.

Example:

    A -> 1
    
    B -> 2
    
    C -> 3
    
    ...
    
    Z -> 26
    
    AA -> 27
    
    AB -> 28 


*/
int Solution::titleToNumber(string A) {
    int n = A.length();
    int MAX = 26;
    int ans=0;
    for(int i=0;i<n;i++){
        int num = A[i]-'A' + 1;
        ans += pow(MAX,n-i-1)*num;
    }
    return ans;
}