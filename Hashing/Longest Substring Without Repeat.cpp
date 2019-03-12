/*
InterviewBit : Longest Substring Without Repeat

Link : https://www.interviewbit.com/problems/longest-substring-without-repeat/

Asked in:
Amazon


Given a string, 
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.


*/

int Solution::lengthOfLongestSubstring(string A) {
	
	// Hash value is 1 if index has occured before in string
	int hash[260];
	//Init to 0
	memset(hash,0,sizeof(hash));

	int i=0,ans=0;

	int n = A.size();
	
	// j is the end index of substring being considered; i is start
	for(int j=0;j<n;j++){
		// Occurred before,increment start until same value occurs
		if(hash[A[j]]==1){
			while(A[i]!=A[j]){
				// Remove these elements from hash and increment start
				hash[A[i]]--;
				i++;
			}
			// skip the duplicate; it doesnt need to be removed from hash as it has been found at index j
			i++;
		}
		else{
			// Add to hash and set answer value if greater
			hash[A[j]]++;
			if(j-i+1>ans) ans = j-i+1;
		}
	}
	return ans;

}