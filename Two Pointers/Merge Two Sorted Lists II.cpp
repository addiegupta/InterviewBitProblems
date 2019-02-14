/*
InterviewBit : Merge Two Sorted Lists II

Link : https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/

1
×Close Be the first one to know about full time and internship opportunities on InterviewBit.
Programming Two Pointers Merge Two Sorted Lists Ii
Merge Two Sorted Lists II
Asked in:  
Adobe
Expedia
Microsoft
Given two sorted integer arrays A and B, merge B into A as one sorted array.

 Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.
TIP: C users, please malloc the result into a new array and return the result. 
If the number of elements initialized in A and B are m and n respectively, the resulting size of array A after your code is executed should be m + n

Example :

Input : 
         A : [1 5 8]
         B : [6 9]

Modified A : [1 5 6 8 9]

*/

void Solution::merge(vector<int> &A, vector<int> &B) {

	vector<int> ans;
	int i=0,j=0;
	int m = A.size(),n=B.size();

	// Traverse until end is reached in either list
	while(i<m && j<n){

		// Add smaller element to answer 
		if(A[i]<B[j]){
			ans.push_back(A[i]);
			i++;
		}
		else if(A[i]>B[j]){
			ans.push_back(B[j]);
			j++;
		}
		// If equal , add both elements
		else{
			ans.push_back(A[i]);
			ans.push_back(B[j]);
			i++;
			j++;
		}
	}
	// Add remaining elements
	while(i<m){
		ans.push_back(A[i]);
		i++;
	}
	while(j<n){
		ans.push_back(B[j]);
		j++;
	}
	A=ans;
}