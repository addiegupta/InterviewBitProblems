/*
InterviewBit : Highest Product

Link : https://www.interviewbit.com/problems/highest-product/


Asked in:
Coursera
Amazon

Given an array of integers, return the highest product possible by multiplying 3 numbers from the array

Input:

array of integers e.g {1, 2, 3}
 NOTE: Solution will fit in a 32-bit signed integer 
Example:

[0, -1, 3, 100, 70, 50]

=> 70*50*100 = 350000


*/
int Solution::maxp3(vector<int> &A) {
	
	if(A.size()<3)return 0;

	// O(n logn); O(n) can be achieved by only keeping track of 3 max values and 2 min values
	sort(A.begin(),A.end());
	
	int n = A.size();
	
	// Ans is found by 
	// 1) product of 3 max numbers
	// or 2) product of 2 min numbers (negative) mmultiplied by largest positive number
	int ans = max(A[n-1]*A[n-2]*A[n-3],A[0]*A[1]*A[n-1]);

	return ans;

}

int ONMethod(vector<int> &A){

	if(A.size() == 0) return 0;
    if(A.size() == 1) return 1;
    if(A.size() == 2) return max(A[0] * A[1], max(A[0], A[1]));
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
    for(int i=0; i<A.size(); i++) {
        if(A[i] > max1){
            max3 = max2;
            max2 = max1;
            max1 = A[i];
        }
        else if(A[i] > max2) {
            max3 = max2;
            max2 = A[i];
        }
        else if(A[i] > max3) {
            max3 = A[i];
        }
        if(A[i] < min1) {
            min2 = min1;
            min1 = A[i];
        }
        else if(A[i] < min2) {
            min2 = A[i];
        }
    }
    return max(max1 * max2 * max3, max1 * min1 * min2);

}
