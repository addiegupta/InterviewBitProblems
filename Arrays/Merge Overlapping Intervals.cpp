/*
InterviewBit : Merge Overlapping Intervals

Link : https://www.interviewbit.com/problems/merge-overlapping-intervals/

Asked in 
Google
Amazon

Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.

*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::merge(vector<Interval> &A) {

	// 1 element or less; no need to process
	if(A.size()<2)return A;

	// New vector to store final intervals
	vector<Interval> ans;

	// Sort the vector for better efficiency
	sort(A.begin(),A.end(),[](const Interval& lhs, const Interval& rhs){ return lhs.start < rhs.start;});
	
	// Add first element to answer vector
	ans.push_back(A.front());

	for(int i=1;i<A.size();i++){
		
		// This element will be compared with the last element of the answer vector
		Interval curr = A[i];
		
		// No Overlap
		if(curr.start>ans.back().end){
			ans.push_back(curr);
		}
		// Overlap; this statement is required so that the interval does not become shorter
		else if(curr.end>ans.back().end){
			ans.back().end = curr.end;
		}
	}

	return ans;
}
