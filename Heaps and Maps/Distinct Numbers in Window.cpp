/*
InterviewBit : Distinct Numbers in Window

Link : https://www.interviewbit.com/problems/distinct-numbers-in-window/

You are given an array of N integers, A1, A2 ,…, AN and an integer K. Return the of count of distinct numbers in all windows of size K.

Formally, return an array of size N-K+1 where i’th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,…, Ai+k-1.

Note:

If K > N, return empty array.
For example,

A=[1, 2, 1, 3, 4, 3] and K = 3

All windows of size K are

[1, 2, 1]
[2, 1, 3]
[1, 3, 4]
[3, 4, 3]

So, we return an array [2, 3, 3, 2].

*/

vector<int> Solution::dNums(vector<int> &A, int B) {
    
    // Vector to store counts of distinct numbers in windows
    vector<int> ans;
    int n = A.size();

    // No possible window
    if(B>n)return ans;

    // Hash to store counts of the numbers appearing in the window
    unordered_map<int,int> hash;
    
    for(int i=0;i<n;i++){

        // Add new element to hash
        hash[A[i]]++;

        // Execute only for elements appearing after the first window
        if(i-B+1>=0){
            // Add count of this window to answer
            ans.push_back(hash.size());

            // Remove first element in window in prep for new element to be inserted in the NEXT for loop iteration
            hash[A[i-B+1]]--;

            // If no more occurences left of first element, erase it from hash so that size of hash is decremented
            if(hash[A[i-B+1]]==0)hash.erase(A[i-B+1]);
        }
    }    

    return ans;
}
