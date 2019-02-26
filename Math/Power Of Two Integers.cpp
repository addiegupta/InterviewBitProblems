/*
InterviewBit : Power Of Two Integers

Link : https://www.interviewbit.com/problems/power-of-two-integers/

Asked in:  
Amazon
Housing


Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.

Example

Input : 4
Output : True  
as 2^2 = 4. 


*/

//TODO IMprove solution
int checkForPower(int A,int i){
    if(A<i)return 0;
    if(A==i)return 1;
    if(A%i!=0)return 0;
    checkForPower(A/i,i);
}
int Solution::isPower(int A) {

    if(A<=1)return 1;

    for(int i=2;i<A;i++){

        if(checkForPower(A,i)==1)return 1;

    }
    return 0;


}
