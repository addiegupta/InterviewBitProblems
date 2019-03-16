/*
InterviewBit : Generate all Parentheses II

Link : https://www.interviewbit.com/problems/generate-all-parentheses-ii/


Asked in:  
Microsoft
Facebook


Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
Make sure the returned list of strings are sorted.


*/
void generateAns(int l,int r,int A,string &curr, vector<string> &ans){
    
    // All brackets added
    if(l==A && r==A){
        ans.push_back(curr);
        return;
    }
    // Left bracket number within limit, add left bracket and recur
    if(l<A){
        curr.append(1,'(');
        generateAns(l+1,r,A,curr,ans);
        curr.pop_back();
    }
    // Right brackets only inserted if enough left brackets are present
    if(r<l){
        curr.append(1,')');
        generateAns(l,r+1,A,curr,ans);
        curr.pop_back();
    }
}
vector<string> Solution::generateParenthesis(int A) {

    vector<string> ans;
    string curr;
    generateAns(0,0,A,curr,ans);
    return ans;
}