/*
InterviewBit : Combination Sum II

Link: https://www.interviewbit.com/problems/combination-sum-ii/

Asked in:
Amazon
Microsoft
Infosys

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Example :

Given candidate set 10,1,2,7,6,1,5 and target 8,

A solution set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]


*/
// Standard backtracking problem
void findCombinations(vector<int> &A, int start,int n,vector<int> &curr,int currSum,set<vector<int>> &ans,int B){
    
    // Found required sum, add to answer set
    if(currSum==B){
        ans.insert(curr);
        return;
    }
    // More than required
    if(currSum>B || start==n ) return;
    
    // Recur and backtrack by choosing current value and then without
    curr.push_back(A[start]);

    findCombinations(A,start+1,n,curr,currSum+A[start],ans,B);

    curr.pop_back();

    findCombinations(A,start+1,n,curr,currSum,ans,B);
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {

    int n = A.size();
    set<vector<int>> ans;
    vector<int> curr;

    sort(A.begin(),A.end());

    findCombinations(A,0,n,curr,0,ans,B);

    vector<vector<int>> ret;
    set<vector<int>>::iterator it;
    for(it=ans.begin();it!=ans.end();it++)ret.push_back(*it);

    sort(ret.begin(),ret.end());

    return ret;
}
