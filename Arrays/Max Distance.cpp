/*
InterviewBit : Max Distance

Link : https://www.interviewbit.com/problems/max-distance/

Asked in:  

Google
Amazon


Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

If there is no solution possible, return -1.

Example :

A : [3 5 4 2]

Output : 2 
for the pair (3, 4)

*/
// This approach creates an array which stores the min value from left till the current index
// and another array which stores the max value from right till the current index
// comparing these arrays the answer is calculated
int createMinFromLeftAndMaxFromRighArraysApproach(const vector<int> &A){
	
	int n = A.size();

	vector<int> minFromLeft(n,0);
	vector<int> maxFromRight(n,0);
	int minLeft=INT_MAX,maxRight=INT_MIN;

	// Initialise minFromLeft array
	for(int i=0;i<n;i++){
		if(A[i]<minLeft)	minLeft=A[i];
		minFromLeft[i]=minLeft;
	}

	// Initialise maxFromRight array
	for(int i=n-1;i>=0;i--){
		if(A[i]>maxRight)	maxRight=A[i];
		maxFromRight[i]=maxRight;
	}


	// Default value for no solution found
	int ans=0;

	// Iterate over array
	int i=0,j=1;
		
	while(i<n && j<n){

		// Possible solution found, increase j for finding better solution 
		if(minFromLeft[i]<=maxFromRight[j]){
			// Set as ans if higher value
			if(j-i>=ans)ans = j-i;
			j++;
		}
		// Find better minimum by going right
		else i++;
	}

	return ans;
}
// This approach follows the idea that after sorting, values to right will always be greater than values
// on left. hence now only indices need to be compared
int sortArrayWhileSavingIndexApproach(const vector<int> &A){
	
	int n = A.size();

	// Create vector of pairs having values sorted and second value is original index
	vector<pair<int,int>> toSort;
	for(int i=0;i<n;i++)toSort.push_back(make_pair(A[i],i));

	// Sort the array
	sort(toSort.begin(),toSort.end());
	
	// Max value of index till now
	int maxIndex = toSort[n-1].second;
	int ans=0;
	// Traverse reverse order
	for(int i=n-2;i>=0;i--){
		// Compare with previous values
		ans = max(ans,maxIndex - toSort[i].second);
		maxIndex = max(maxIndex,toSort[i].second);
	}
	return ans;
}
int Solution::maximumGap(const vector<int> &A){

	if(A.size()<1)return -1;
	if(A.size()==1)return 0;

	// O(n) time O(n) space
	return createMinFromLeftAndMaxFromRighArraysApproach(A);
	
	// O(nlogn) time O(n) space
	// return sortArrayWhileSavingIndexApproach(A);

}