/*
InterviewBit : Gray Code

Link: https://www.interviewbit.com/problems/gray-code

Asked in:
Microsoft

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
There might be multiple gray code sequences possible for a given n.
Return any such sequence.

*/

/** Insert the reverse of ans in ans by adding a 1 at most significant bit to it
  
    e.g. gray code of 3 is obtained from gray code of 2
    gray code of 2 is 00,01,11,10
    reverse of it is also gray code => it is added to end of ans
  
    => we get 00,01,11,10,10,11,01,00
  
    Now 0 is set as MSB for first half and 1 for second half to get Gray code for 3
  
    => 000,001,001,010,110,111,101,100
*/
vector<int> Solution::grayCode(int A) {
    
    // Insert a single 0 in answer vector, gray code of 1 is obtained in first iteration of loop
    vector<int> ans(1,0);
    
    int n;

    for(int i=0;i<A;i++){
        n=ans.size();

        for(int j=n-1;j>=0;j--){
            ans.push_back(ans[j] + (1<<i));
        }
    } 
    return ans;
}




