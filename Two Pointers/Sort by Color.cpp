/*
InterviewBit : Sort by Color

Link : https://www.interviewbit.com/problems/sort-by-color/


Asked in:  
Facebook
Microsoft

Given an array with n objects colored red, white or blue, 
sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: Using library sort function is not allowed.

Example :

Input : [0 1 2 0 1 2]
Modify array so that it becomes : [0 0 1 1 2 2]


*/

// Count the number of 0s,1s and 2s
// Recreate the array using their count values
// Takes 2 passes and O(1) extra space
void solveByCountingApproach(vector<int> &A){
	int count[3]={0};
	int n = A.size();
	int i=0,j=0;
	for(;i<n;i++) count[A[i]]++;
	i=0;
	while(n--){
		if(j==3)break;
		if(count[j]==0){
			n++;
			j++;
			continue;
		}
		A[i++] = j;
		count[j]--;
	}
}

// Swap elements to put 0s at start and 2s at end, 1s will be in position on their own
// Takes one pass and no extra space
void solveBySwappingApproach(vector<int> &A){

	int i=0,n=A.size();
	while(i<n && A[i]==0) i++;
	int k=n-1;
	for(int j=i;i<=k;i++){
		if(A[i]==0)	swap(A[j++],A[i]);
		else if(A[i]==2) swap(A[i--],A[k--]);
	}
	
}
void Solution::sortColors(vector<int> &A) {

	// solveByCountingApproach(A);
	solveBySwappingApproach(A);
}

