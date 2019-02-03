/*
InterviewBit : Reverse integer

Link : https://www.interviewbit.com/problems/reverse-integer/

Asked in:  
HCL
Bloomberg

Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer

*/
int Solution::reverse(int A) {
    int ans=0,digit;

    // Obtain sign of the number
    int sign = (A<0)?-1:1;
    // Make number positive
    A *= sign;
    while(A){
    	// Obtain last digit
    	digit = A%10;

        // Check for integer overflow
    	if(ans>(INT_MAX/10)||(ans==(INT_MAX/10)&&digit>(INT_MAX%10)))return 0;
    	
        // Add digit
        ans = (ans*10) + digit;
    	A/=10;
    }
    return ans*sign;
}
