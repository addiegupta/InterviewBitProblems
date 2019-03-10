/*
InterviewBit : Combinations

Link: https://www.interviewbit.com/problems/combinations

Asked in:
Amazon
Adobe

Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.
Example :
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. 

*/

void findCombinations(int i,int n,vector<vector<int>> &ans,vector<int> v,int B){
    
    // Reached the number of elements required, add to answer and return    
    if(v.size()==B){
        ans.push_back(v);
        return;
    }
    // Exceeded n, no solution will be attained on this path now; return
    if(i>n) return ;
    
    // Select this element in this combination and proceed
    v.push_back(i);
    findCombinations(i+1,n,ans,v,B);

    // Dont select this element in this combination and proceed
    v.pop_back();
    findCombinations(i+1,n,ans,v,B);

}


vector<vector<int> > Solution::combine(int A, int B) {

    vector<vector<int>> ans;
    vector<int> v;
    findCombinations(1,A,ans,v,B);
    return ans;
}