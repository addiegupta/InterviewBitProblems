/*
InterviewBit : Max Continuous Series of 1s

Link : https://www.interviewbit.com/problems/max-continuous-series-of-1s/


Asked in:
VMWare

You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:

Input : 
Array = {1 1 0 1 1 0 0 1 1 1 } 
M = 1

Output : 
[0, 1, 2, 3, 4] 

If there are multiple possible solutions, return the sequence which has the minimum start index.


*/
vector<int> Solution::maxone(vector<int> &A, int B) {

    int n = A.size();

    // length of largest continuous 1 subarray; start index of subarray
    int maxLen =0, maxStart;

    // Count of 0s in current range
    int count=0;
    
    // Subarray range iterators
    int l=0,r=1;
    
    // Handle first element
    if(A[l]==0){

        // No flips allowed
        if(B==0){
            // Find first 1 value
            while(l<n && A[l]!=1 ){
                l++;
            }
            r=l+1;
        }
        else count++;
    }

    // Iterate over array
    while(r<n){

        // Found a 0, flip it
        if(A[r]==0){

            // Increase l until a 0 is found so that another flip can be accomodated
            while(count>=B){
                // Found a 0, decrease count
                if(A[l]==0) count--;
                
                // Increase left iterator
                l++;
            }    
            // Increase count for current element flip
            count++;
        }
        
        // Current length is greater than max length; set this as max length
        if((r-l+1)>maxLen){
            maxLen = r-l+1;
            maxStart = l;
        }
        // Iterate
        r++;
    }

    // Add indices to the answer vector
    vector<int> ans;
    for(int i = maxStart; (i-maxStart)<maxLen;i++){
        ans.push_back(i);
    }
    return ans;

}
