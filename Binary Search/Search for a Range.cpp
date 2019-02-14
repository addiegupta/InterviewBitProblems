/*
InterviewBit : Search for a Range

Link : https://www.interviewbit.com/problems/search-for-a-range/

Asked in 

Google
Microsoft


Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm’s runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example:

Given [5, 7, 7, 8, 8, 10]

and target value 8,

return [3, 4].

*/

vector<int> Solution::searchRange(const vector<int> &A, int B) {
	vector<int> ans(2,-1);
	int n = A.size();

	int low =0,high = n-1;
	int mid;

	// Find start
	while(low<=high){
		mid = low + (high-low)/2;
		// Altered condition to include equality so as to find start of range
		if(A[mid]>=B)high = mid-1;
		else low = mid+1;
		// else high = mid-1;
	}
	// After termination of loop, low will be index of start of range
	if(A[low]!=B)return ans;
	else ans[0] = low;

	// No need to set low =0 as the range low-high is currently the values equal to
	// the variable B as well as some greater values
	high=n-1;
	
	// Find end
	while(low<=high){
		mid = low + (high-low)/2;
		if(A[mid]<=B) low = mid+1;
		else high = mid-1;
	}
	ans[1] = high;

	return ans;

}
