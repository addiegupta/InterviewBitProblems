/*
InterviewBit : Stairs

Link : https://www.interviewbit.com/problems/stairs/


Asked in:
Amazon
Intel
Morgan Stanley

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example :

Input : 3
Return : 3

Steps : [1 1 1], [1 2], [2 1]

*/
int Solution::climbStairs(int A) {
    int two_steps=1;
    int one_step=1;
    int temp;
    for(int i=2;i<=A;i++){
        temp=one_step;
        one_step=one_step+two_steps;
        two_steps=temp;
    }
    return one_step;
}
