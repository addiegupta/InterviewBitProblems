/*
InterviewBit : Power of 2

Link : https://www.interviewbit.com/problems/power-of-2/

Find if Given number is power of 2 or not. 
More specifically, find if given number can be expressed as 2^k where k >= 1.

Input:

number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)
Output:

return 1 if the number is a power of 2 else return 0

Example:

Input : 128
Output : 1


*/
int Solution::power(string A) {

    while(A.length()>=2){
        int num=0,carry=0;
        string newA;
        int temp;
        for(int i=0;i<A.length();i++){
            num = carry*10 + (A[i]-'0');
            carry = num%2;
            if(num==1 && i==0) continue;
            newA.append(1,num/2 +'0');
        }
        if((newA[newA.length()-1]-'0')%2!=0)return 0;
        A=newA;
    }
    int value = A[0]-'0';
    if(value==2 || value ==4 || value ==8)return 1;
    return 0;
}