/*
InterviewBit : Single Number

Link : https://www.interviewbit.com/problems/single-number/

Asked in 

Amazon

Given an array of integers, every element appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example :

Input : [1 2 2 3 1]
Output : 3

*/

// XORing the same number with a saved value twice will add even number of 1s/0s
// hence producing no effect overall
// thus the number that is not repeating can be found using this method
//
// The idea is based on following two facts.
// a) XOR of a number with itself is 0.
// b) XOR of a number with 0 is number itself.
int Solution::singleNumber(const vector<int> &A) {
	// temp value to be xor'ed with every number in array
    int temp=0;
    for(int i=0;i<A.size();i++){
        temp^=A[i];
    }
    return temp;
}
