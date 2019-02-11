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
unsigned int swapBits(unsigned int A,int i,int j){
	// Get bits that need to be swapped
	unsigned int lo=(A>>i)&1;
	unsigned int hi=(A>>j)&1;

	// Need for swapping as both are different
	if(lo^hi){
		// Toggle bits at both positions so as to effectively swap them
		A ^= (1U<<i)|(1U<<j);
	}
	return A;
}
unsigned int Solution::reverse(unsigned int A) {
	unsigned int n= sizeof(A)*8;
	
	// Swap left half with right half of A
	for(unsigned int i=0;i<n/2;i++){

		A = swapBits(A,i,n-i-1);
	}
	return A;
}
 