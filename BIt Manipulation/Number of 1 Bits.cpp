/*
InterviewBit : Number of 1 Bits

Link : https://www.interviewbit.com/problems/number-of-1-bits/

Write a function that takes an unsigned integer and returns the number of 1 bits it has.

Example:

The 32-bit integer 11 has binary representation

00000000000000000000000000001011
so the function should return 3.

Note that since Java does not have unsigned int, use long for Java


*/

int Solution::numSetBits(unsigned int A) {
    int sum=0;
    while(A){
        sum++;

        //This is used to find and thus reset the first 1 from right in binary form of number
        // e.g. number A is 11001010001000
        // then A-1 is      11001010000111
        // therefore the bits to right of first set bit from right are reset
        // ANDing these results in 11001010001000
        //						 & 11001010000111
        //						   --------------
        //						   11001010000000	
        A=A&A-1;
    }
    return sum;
}