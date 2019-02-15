/*
InterviewBit : Implement Power Function

Link : https://www.interviewbit.com/problems/implement-power-function/


Asked in:  
	
Google
LinkedIn

Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative. 
In other words, make sure the answer you return is non negative.

Input : x = 2, n = 3, d = 3
Output : 2

2^3 % 3 = 8 % 3 = 2.

*/
int findPower(long long int x,int n,int d){
	if(n==1)return (x+d)%d;
	// e.g. 3^8 = (3*3)^4;  3^9 = (3*3)^4 * 3
	return (n%2==0)?findPower((x*x+d)%d,n/2,d):(findPower((x*x+d)%d,n/2,d)*x+d)%d;
}
int Solution::pow(int x, int n, int d) {
	long long int val =x;
	if(x==0)return 0;
	if(n==0)return 1%d;
	return (int)findPower(val,n,d);

}