/*
InterviewBit : Nearest Smaller Element

Link : https://www.interviewbit.com/problems/nearest-smaller-element/


Asked in:  
Amazon
Microsoft

Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.

Example:

Input : A : [4, 5, 2, 10, 8]
Return : [-1, 4, -1, 2, 2]

Example 2:

Input : A : [3, 2, 1]
Return : [-1, -1, -1]



*/
vector<int> Solution::prevSmaller(vector<int> &A) {
    
    stack<int> stack;
    vector<int>ans;

    int n=A.size();

    for(int i=0;i<n;i++){
        
        // Remove stack values until a lesser value is found
        while(!stack.empty() && stack.top()>=A[i])stack.pop();
        
        // Stack still has values; add top value to answer vector
        if(!stack.empty())  ans.push_back(stack.top());
        
        // No lesser value; add -1 to answer vector
        else ans.push_back(-1);
        
        // Add current value to stack
        stack.push(A[i]);
    }
    return ans;
}

