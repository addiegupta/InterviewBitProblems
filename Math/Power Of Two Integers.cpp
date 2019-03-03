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

int checkForPower(int A,int i){
    if(A<i)return 0;
    if(A==i)return 1;
    if(A%i!=0)return 0;
    checkForPower(A/i,i);
}
int recursiveDivideApproach(int A){
    int root = sqrt(A);
    // For every number i from 2 to sqrt(A), check if there exists some p such that i^p =A
    for(int i=2;i<=root;i++){
        if(checkForPower(A,i)==1)return 1;
    }
    return 0;
}
// This approach directly compares logarithms of input number and i to sqrt(A) to see if any number could form powers
int logApproach(int A){

    int root = sqrt(A);
    int logVal ;
    for(int i=2;i<=root;i++){
        logVal = log(A)/log(i);

        // Check if log(A)/log(i) is an integer
        if(abs(log(A)/log(i))-logVal <=0.000001)return 1;

    }
    return 0;
}
int Solution::isPower(int A) {

    if(A<=1)return 1;

    // 2 Approaches
    // return recursiveDivideApproach(A);
    return logApproach(A);
}
