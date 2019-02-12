/*
InterviewBit : Reverse Bits

Link : https://www.interviewbit.com/problems/reverse-bits/

Asked in:

Nvidia
HCL
Amazon

Reverse bits of an 32 bit unsigned integer

Example 1:

x = 0,

          00000000000000000000000000000000  
=>        00000000000000000000000000000000
return 0

Example 2:

x = 3,

          00000000000000000000000000000011 
=>        11000000000000000000000000000000
return 3221225472

Since java does not have unsigned int, use long


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
 