/*
InterviewBit : Majority Element

Link : https://www.interviewbit.com/problems/majority-element/


Asked in:
Microsoft
Yahoo
Google

Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example :

Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2. 


*/
int Solution::majorityElement(const vector<int> &A) {
    
    // Select index 0 element as majority element   
    int majorityIndex = 0;
    
    int n = A.size();

    for(int i=1,count = 1;i<n;i++){
        
        // If i'th element is same as chosen maj elem, increment count else decrement
        A[majorityIndex] == A[i]? count++:count--;

        // Selected element was not majority as count has reached 0,set i'th element as majority
        if(count==0){
            majorityIndex=i;
            count=1;
        }
    }
    return A[majorityIndex];
}
