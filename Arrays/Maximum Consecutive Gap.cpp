/*
InterviewBit : Maximum Consecutive Gap

Link : https://www.interviewbit.com/problems/maximum-consecutive-gap/

Asked in : Hunan Asset

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Example :

Input : [1, 10, 5]
Output : 5 
Return 0 if the array contains less than 2 elements.

You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
You may also assume that the difference will not overflow.



*/
int Solution::maximumGap(const vector<int> &A) {




}
/**
 FIGURE OUT **************************************

Inefficient solution
int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    if(n<2) return 0;
    
    vector<int> B = A;
    sort(B.begin(),B.end());
    
    int ans = 0;
    for(int i=1;i<B.size();i++) ans = max(ans,B[i]-B[i-1]);
    
    return ans;
}

Solution copied from editorial

class Solution {
    public:
        int maximumGap(const vector<int> &num) {
            if(num.empty() || num.size() < 2)
                return 0;
            int maxNum = *max_element(num.begin(), num.end());
            int minNum = *min_element(num.begin(), num.end());
            //average gap from minNum to maxNum.
            int gap = (maxNum - minNum - 1) / (num.size() - 1) + 1;

            //number of buckets = num.size() - 1
            vector<int> bucketsMin(num.size() - 1, INT_MAX);
            vector<int> bucketsMax(num.size() - 1, INT_MIN);
            //put into buckets
            for (int i = 0; i < num.size(); i++) {
                if (num[i] != maxNum && num[i] != minNum)
                {
                    int buckInd = (num[i] - minNum) / gap;
                    bucketsMin[buckInd] = min(bucketsMin[buckInd], num[i]);
                    bucketsMax[buckInd] = max(bucketsMax[buckInd], num[i]);
                }
            }
            int maxGap = INT_MIN;
            int previous = minNum;
            for (int i = 0; i < num.size() - 1; i++) {
                if (bucketsMin[i] == INT_MAX && bucketsMax[i] == INT_MIN)
                    continue;   //empty
                //i_th gap is minvalue in i+1_th bucket minus maxvalue in i_th bucket 
                maxGap = max(maxGap, bucketsMin[i] - previous);
                previous = bucketsMax[i];
            }
            maxGap = max(maxGap, maxNum - previous);
            return maxGap;
        }
};

*/