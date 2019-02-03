/*
InterviewBit : Find Duplicate in Array

Link : https://www.interviewbit.com/problems/find-duplicate-in-array/

Asked in:  
Amazon
VMWare
Riverbed


Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input:

[3 4 1 4 1]
Sample Output:

1
If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1

*/

// THE EDITORIAL ON THE SITE IS INCORRECT
int Solution::repeatedNumber(const vector<int> &A) {
    

	// Less than O(n) space required; so make vector of half the size
    vector<int> hash((A.size()/2)+1, 0);

    // Deal with even numbers in the array
    for(int i = 0; i < A.size(); i++){
        if((A[i]%2) == 0){
            if(hash[(A[i]/2)-1] == 0){
                hash[(A[i]/2)-1] = A[i];
            }
            else{
                return A[i];
            }
        }
    }

    fill(hash.begin(), hash.end(), 0);

    // Deal with odd numbers in the array
    for(int i = 0; i < A.size(); i++){
        if((A[i]%2) != 0){
            if(hash[A[i]/2] == 0){
                hash[A[i]/2] = A[i];
            }
            else{
                return A[i];
            }
        }
    }
    return -1;
}