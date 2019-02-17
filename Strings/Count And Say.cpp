/*
InterviewBit : Count And Say

Link : https://www.interviewbit.com/problems/count-and-say/


Asked in:
Facebook

The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.

*/
string getSequence(string a){
    
    int n = a.size();
    int num,i=0,count=0;
    string ans;

    while(i<n){
        // Get a number
        num=a[i];
        count=1;
        // Count its instances
        while(i<n-1 && a[i+1]==num) count++,i++;
        // Append the count and the number
        ans += std::to_string(count);
        ans += num;
        i++;
    }
    return ans;
}
string Solution::countAndSay(int A) {

    string hash[A];
    hash[0]="1";
    for(int i=1;i<A;i++){
        hash[i]=getSequence(hash[i-1]);
    }
    return hash[A-1];
}
