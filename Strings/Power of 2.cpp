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

    // Divide by 2 in string form until string length is greater than 19 ( i.e. it cant be converted into long long int )
    while(A.length()>=19){

        int num=0,carry=0;
        string newA;
        int temp;
        for(int i=0;i<A.length();i++){
            
            // get value at current index added with carry
            num = carry*10 + (A[i]-'0');
            // new carry will be found after dividing by 2
            carry = num%2;
            // if value is 1, then dividing by 2 will result in 0 . therefore skip for first index
            // as 0 is not required at start of number
            if(num==1 && i==0) continue;
            // divide number by 2 and append
            newA.append(1,num/2 +'0');
        }
        // If last character is not even , return 0
        if((newA[newA.length()-1]-'0')%2!=0)return 0;
        A=newA;
    }

    // Convert string to long long int form
    long long int val=0;
    for(int i=0;i<A.length();i++){
        val = val*10 + (A[i]-'0');
    }
    if(val==1)return 0;

    // if the number is a power of 2 then its binary will be of the form 10000000000.....0
    // i.e. only the leftmost bit will be set
    // then number -1 will be of the form                                01111111111.....1
    // therefore performing and operation on both will result in         00000000000.....0                   
    return (((val) & (val-1))==0)?1:0;

}