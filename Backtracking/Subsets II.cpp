/*
InterviewBit : Subsets II

Link: https://www.interviewbit.com/problems/subsets-ii

Asked in:
Amazon
Microsoft


Given a collection of integers that might contain duplicates, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]


*/

// Standard backtracking problem
void findSubsets(vector<int> &A,int i,int n,vector<int> &curr,set<vector<int>> &ans){
    
    // Add to answer set
    if(i==n){
        ans.insert(curr);
        return;
    }

    // Recur without curr value
    findSubsets(A,i+1,n,curr,ans);

    // Add current value and then recur and backtrack
    curr.push_back(A[i]);

    findSubsets(A,i+1,n,curr,ans);

    curr.pop_back();
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    
    set<vector<int>> ans;
    vector<int> curr;

    sort(A.begin(),A.end());
    int n = A.size();

    findSubsets(A,0,n,curr,ans);    

    vector<vector<int>> ret (ans.begin(),ans.end());
    
    return ret;  
  
  
}
