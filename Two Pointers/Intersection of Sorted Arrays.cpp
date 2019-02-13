/*
InterviewBit : Intersection of Sorted Arrays

Link : https://www.interviewbit.com/problems/intersection-of-sorted-arrays/

Asked in 

Google
Facebook


Asked in:  
Facebook
Google
Find the intersection of two sorted arrays.
OR in other words,
Given 2 sorted arrays, find all the elements which occur in both the arrays.

Example :

Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 3 5]

Output : [3 3 5]

Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 5]

Output : [3 5]
 NOTE : For the purpose of this problem ( as also conveyed by the sample case ), assume that elements that appear more than once in both arrays should be included multiple times in the final output. 

*/
vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
	// Iterators for both the arrays
	int i=0,j=0;
	// Sizes of arrays
	int m=A.size(),n=B.size();
	vector<int> ans;
	while(i<m && j<n){
		// Common array, add to answer and increment iterators
		if(A[i]==B[j]){
			ans.push_back(A[i]);
			i++;
			j++;
		}
		// A has bigger element; if this element exists in B it must be at a higher j
		else if(A[i]>B[j]) j++;
		else i++;
	}
	return ans;

}
