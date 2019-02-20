/*
InterviewBit : 3 Sum

Link : https://www.interviewbit.com/problems/3-sum/

Asked in:  
Facebook
Amazon
Microsoft


Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers.

Assume that there will only be one solution

Example: 
given array S = {-1 2 1 -4}, 
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)


*/
int Solution::threeSumClosest(vector<int> &A, int B) {

    int n = A.size();
    if(n<3)return 0;
    int i,ptr1,ptr2;
    int sum;
    sort(A.begin(),A.end());
    int ans=INT_MAX;
    for(i=0;i<n-2;i++){
        ptr1 =i+1,ptr2 = n-1;
        
        while(ptr1<ptr2){
            sum = A[i]+A[ptr1]+A[ptr2];
            if(ans==INT_MAX)ans=sum;
            if(sum==B)return B;
            if(abs(sum-B)<abs(ans-B))ans=sum;
            if(sum>B)ptr2--;
            else if(sum<B)ptr1++;
        }
    }
    return ans;
}