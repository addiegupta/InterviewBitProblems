/*
InterviewBit : Container With Most Water

Link : https://www.interviewbit.com/problems/container-with-most-water/

Asked in 

Google
Facebook
Amazon

Given n non-negative integers a1, a2, ..., an,
where each represents a point at coordinate (i, ai).
'n' vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).

Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Your program should return an integer which corresponds to the maximum area of water that can be contained ( Yes, we know maximum area instead of maximum volume sounds weird. But this is 2D plane we are working with for simplicity ).

 Note: You may not slant the container. 
Example :

Input : [1, 5, 4, 3]
Output : 6

Explanation : 5 and 3 are distance 2 apart. So size of the base = 2. Height of container = min(5, 3) = 3. 
So total area = 3 * 2 = 6

*/
int area(vector<int>&A,int i,int j){return min(A[i],A[j])*(j-i);}
int Solution::maxArea(vector<int> &A) {

	// Size of the array
	int n=A.size();
	// Iterators; one from start, other from end
	int i=0,j=n-1;
	int ans=0;
	int temp;

	// Iterate over complete array
	while(i!=j){
		// Get area if lines at i and j are used as walls for container
		temp = area(A,i,j);

		// Better solution found
		if(temp>ans)ans = temp;

		// Change that iterator which currently has less value as compared to other iterator
		(A[i]>A[j])?j--:i++;	
	}
	return ans;

}
