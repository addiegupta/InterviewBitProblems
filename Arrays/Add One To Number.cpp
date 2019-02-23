/*
InterviewBit : Add One To Number

Link : https://www.interviewbit.com/problems/add-one-to-number/

Asked in:  

Google


Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

 NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
For example, for this problem, following are some good questions to ask :
Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.

*/

vector<int> Solution::plusOne(vector<int> &A) {
    int n = A.size();
    int carry=0;
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            if(A[i]==9){
                A[i]=0;
                carry=1;
            }
            else A[i]++;
        }
        else if(carry ==0)break;
        else{
            A[i]+=carry;
            carry=0;
            if(A[i]==10){
                A[i]=0;
                carry=1;
            }
        }
    }
    if(carry==1){
        int temp=1,newTemp;
        for(int i=0;i<n;i++){
            newTemp = A[i];
            A[i]=temp;
            temp=newTemp;
        }
        A.push_back(temp);
    }
    int i =0;
    while(A[i]==0)i++;

    if(i>0){
        vector<int>::iterator it1,it2;
        it1=A.begin();
        it2 = it1 + i;
        A.erase(it1,it2);

    } 

    return A;

}
