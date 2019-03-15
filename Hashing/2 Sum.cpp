/*
InterviewBit : 2 Sum

Link : https://www.interviewbit.com/problems/2-sum

Asked in:
Amazon
Facebook
Google


Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based. 
Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.

If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

Input: [2, 7, 11, 15], target=9
Output: index1 = 1, index2 = 2


*/

vector<int> Solution::twoSum(const vector<int> &A, int B) {
	
	// Hash to store numbers encountered	
	unordered_map<int,int> hash;
	int n = A.size();

	// Ans vector
	vector<int> ans;

	int req;
	
	// Iterate over array
	for(int i=0;i<n;i++){

		// The required number to make sum equal to B
		req = B-A[i];
		
		// If required number has been encountered before, then return the ans
		if(hash.find(req)!=hash.end()){
			ans.push_back(hash[req]);

			// 1 based index
			ans.push_back(i+1);
			return ans;
		}
		// If curr number has not been encountered before, add index to hash
		if(hash.find(A[i])==hash.end()) hash[A[i]]=i+1;
	}
	
	// No solution found return empty vector
	return ans;

}