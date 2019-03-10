/*
InterviewBit : Permutations

Link : https://www.interviewbit.com/problems/permutations


Asked in:  
Microsoft
Adobe
Google


Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]
 NOTE
No two entries in the permutation sequence should be the same.
For the purpose of this problem, assume that all the numbers in the collection are unique.
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS.
Example : next_permutations in C++ / itertools.permutations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. 

*/

void findPermutationsUsingSet(vector<int> &A, vector<vector<int>> &ans,vector<int> &p,int n,unordered_set<int> used);
void findPermutationsWithoutSet(vector<int> &A, vector<vector<int>> &ans,int start,int n);

vector<vector<int> > Solution::permute(vector<int> &A) {
    
    vector<vector<int>> ans;
    
    vector<int> p;
    unordered_set<int> used;
    

    // Initial solution; Same time complexity, requires extra space to store current permutation in a seperate vector
    // and a set of integers that stores the numbers used up already in current permutation
    // findPermutationsUsingSet(A,ans,p,A.size(),used);
    
    // Solution given on InterviewBit without using the additional vector and set of integers
    findPermutationsWithoutSet(A,ans,0,A.size());

    return ans;


}

void findPermutationsUsingSet(vector<int> &A, vector<vector<int>> &ans,vector<int> &p,int n,unordered_set<int> used){
    
    // All numbers used up, add current permutation to ans vector and return
    if(used.size()==n){
        ans.push_back(p);
        return;
    }

    // Iterate for every number
    for(int i=0;i<n;i++){

        // Check set if this number is used up already
        if(used.find(A[i])==used.end()){
            
            // Add this number to permutation
            used.insert(A[i]);
            p.push_back(A[i]);

            // Recursively call this function to complete permutations
            findPermutationsUsingSet(A,ans,p,n,used);

            // Remove this number at end of for loop
            p.pop_back();
            used.erase(A[i]);
        }
    }

}
void findPermutationsWithoutSet(vector<int> &A,vector<vector<int>> &ans,int start ,int n){
    
    // Last element reached, add permutation to ans vector
    if(start == n-1){
        ans.push_back(A);
        return;
    }
    for(int i =start;i<n;i++){

        // Swap the start element with i element
        swap(A[start],A[i]);

        // Find permutations recursive call
        findPermutationsWithoutSet(A,ans,start+1,n);

        // Undo swap operation; Note that this statement is exactly same as the previous swap 
        // start and i can be written in reverse order as well 
        swap(A[i],A[start]);
    }

}