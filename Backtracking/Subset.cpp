/*
InterviewBit : Subset

Link: https://www.interviewbit.com/problems/subset

Asked in:
Amazon
Microsoft

Given a set of distinct integers, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]


*/
void findSubsets(vector<int> &A, int i, int n, vector<int> &curr,vector<vector<int>> &ans){
    
    if(i==n){
        ans.push_back(curr);
        return;
    }

    // Continue subset without including i'th element of A
    findSubsets(A,i+1,n,curr,ans);

    // Add i'th element of A to subset and continue
    curr.push_back(A[i]);
    findSubsets(A,i+1,n,curr,ans);

    // Remove the element as this function call ends and previous function call is continued
    curr.pop_back();
}


vector<vector<int> > Solution::subsets(vector<int> &A) {
    
    int n = A.size();
    sort(A.begin(),A.end());

    vector<vector<int>> ans;
    vector<int> curr;
    findSubsets(A,0,n,curr,ans);

    sort(ans.begin(),ans.end());
    return ans;

}



