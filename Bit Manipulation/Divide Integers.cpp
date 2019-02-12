/*
InterviewBit : Divide Integers

Link : https://www.interviewbit.com/problems/divide-integers/

Asked in:

Microsoft
Amazon

Divide two integers without using multiplication, division and mod operator.

Return the floor of the result of the division.

Example:

5 / 2 = 2
Also, consider if there can be overflow cases. For overflow case, return INT_MAX.

*/

int Solution::divide(int A, int B) {


	long long n = A, m = B;

    // determine sign of the quotient
    int sign =( n < 0 )^ (m < 0 )? -1 : 1;

    // remove sign of operands
    n = abs(n), m = abs(m);

    // q stores the quotient in computation
    long long q = 0;

    // test down from the highest bit
    // accumulate the tentative value for valid bits
    for (long long t = 0, i = 31; i >= 0; i--)
        if (t + (m << i) <= n)
            t += m << i, q |= 1LL << i;

    // assign back the sign
    if (sign < 0) q = -q;

    // check for overflow and return
    return q >= INT_MAX || q < INT_MIN ? INT_MAX : q;

}
