/*
InterviewBit : Kth Row of Pascal's Triangle

Link : https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/

Asked in 

Google

Given an index k, return the kth row of the Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Input : k = 3

Return : [1,3,3,1]
 NOTE : k is 0 based. k = 0, corresponds to the row [1]. 
Note:Could you optimize your algorithm to use only O(k) extra space?

*/

vector<int> Solution::getRow(int A) {

	// Only need to store 2 rows
	vector<int> prev,next;
	prev.push_back(1);
	for(int i=1;i<=A;i++){
		next.clear();
		for(int j=0;j<=i;j++){
			// Create new row
			int l =(j-1<0)?0:prev[j-1];
			int r = (j==i)?0:prev[j];
			next.push_back(l+r);
		}
		// Set this row as previous for next iteration
		prev = next;
	}
	return prev;
}
