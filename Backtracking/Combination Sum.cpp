/*
InterviewBit : Combination Sum

Link: https://www.interviewbit.com/problems/combination-sum

Asked in:
Amazon
Facebook
Adobe

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.
Example, 
Given candidate set 2,3,6,7 and target 7,
A solution set is:

[2, 2, 3]
[7]



*/


vector<vector<int>> newSolutionWithoutSet(vector<int> &A,int B);
vector<vector<int>> initialSolutionUsingSet(vector<int> &A,int B);


vector<vector<int> > Solution :: combinationSum(vector<int> &A, int B) {
    
    // return initialSolutionUsingSet(A,B);
    return newSolutionWithoutSet(A,B);
    
}

// Recursive function to find combinations so that sum is made
// Uses set to store the combinations so that duplication is avoided

void findCombinations(vector<int> &A,int i,int n,vector<int> &curr,int currSum,set<vector<int>> &ans,int B){

    // Sum value exceeded 
    if(currSum>B) return;

    // Found sum, add combination to set
    if(currSum==B){
        ans.insert(curr);
        return;
    }
    // Exceeded size of array
    if(i==n)return;

    // Without selecting this number, increase index and recur
    findCombinations(A,i+1,n,curr,currSum,ans,B);

    // Add curr element to curr combination
    curr.push_back(A[i]);

    // Recur with and without index so that same element can be used again in without case
    findCombinations(A,i,n,curr,currSum+A[i],ans,B);
    findCombinations(A,i+1,n,curr,currSum+A[i],ans,B);

    // Remove element for backtracking
    curr.pop_back();

}
// Solves using a set to avoid duplication of combinations
vector<vector<int>> initialSolutionUsingSet(vector<int> &A,int B){
    
    set<vector<int>> ansSet;
    int n = A.size();
    vector<int> curr;

    sort(A.begin(),A.end());
    findCombinations(A,0,n,curr,0,ansSet,B);

    // Add set values to vector and return after sorting

    vector<vector<int>> ans;
    set<vector<int>>::iterator it;
    for(it=ansSet.begin();it!=ansSet.end();++it)ans.push_back(*it);

    sort(ans.begin(),ans.end());
    return ans;


}
// Editorial recursive function that does not use set
void findCombinationsWithoutSet(vector<int> &A,int i,int n,int currSum,vector<int> &curr,vector<vector<int>> &ans,int B){
    
    if(currSum>B)return;

    if(currSum==B){
        ans.push_back(curr);
        return;
    }
    if(i==n)return;

    // Iterate over array
    for(int j=i;j<n;j++){
        //Add value to curr vector
        curr.push_back(A[j]);

        // Recur for same index so that value can be used again
        findCombinationsWithoutSet(A,j,n,currSum+A[j],curr,ans,B);

        // Remove value from curr vector
        curr.pop_back();
    }
}

// Editorial solution that solves without using a set
vector<vector<int>> newSolutionWithoutSet(vector<int> &A,int B){
    
    sort(A.begin(),A.end());

    // Create new array without duplicate elements in A
    vector<int> uniqueA;
    for(int i=0;i<A.size();i++){
        if(i==0 || A[i]!=A[i-1]) uniqueA.push_back(A[i]);
    }

    int n = uniqueA.size();
    vector<vector<int>> ans;
    vector<int> curr;
    findCombinationsWithoutSet(uniqueA,0,n,0,curr,ans,B);

    return ans;

}
