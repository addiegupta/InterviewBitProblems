/*
InterviewBit : 3 Sum Zero

Link : https://www.interviewbit.com/problems/3-sum-zero/

Asked in:  
Facebook
Google
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets. For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
(-1, 0, 1)
(-1, -1, 2) 


*/

// O(n^2) time better solution after checking InterviewBit solution
vector<vector<int> > Solution::threeSum(vector<int> &A) {

	// Stores the 3 sum sets
	vector<vector<int>> ans;
	
	// Stores a single set
	vector<int> temp;
	
	int n = A.size();

	// Return if less than 3 elements
	if(n<3)return ans;
	
	// Sort the array
	sort(A.begin(),A.end());
	
	// Iterator variables and val to store current sum of 3 values
	int i,j,k,val;

	// i iterates over array; j and k are adjusted as per value for every iteration of i
	// So O(n) for i and for every i, O(n) for j and k together
	for(i=0;i<n-2;i++){

		// Skip over duplicates
		if(i>0 && A[i]==A[i-1])continue;
		// A[i] is smallest element; if it is greater than 0 then no possible set can be found now
		if(A[i]>0)break;

		// Initialise j and k iterators
		j=i+1;
		k=n-1;

		// Iterate j and k
		while(j<k){

			// Check sum
			val = A[i]+A[j]+A[k];
			
			// Add to answer
			if(val==0){
				temp.clear();
				temp.push_back(A[i]);
				temp.push_back(A[j]);
				temp.push_back(A[k]);
				ans.push_back(temp);
				j++;
				// Skip over duplicates
				while(j<k && A[j]==A[j-1])j++;
			}
			// Value needs to be larger, increase j
			else if(val<0)j++;
			// Value needs to be smaller, increase i
			else k--;
		}
		
	}
	return ans;
}

// O(n^2 log n) time and additional set used; first solution submitted; not good ---------------
vector<vector<int> > Solution::threeSumSlow(vector<int> &A) {

	set<vector<int>> ans;
	vector<vector<int>> returnAns;
	vector<int> temp;

	int n = A.size();
	if(n<3)return returnAns;
	
	sort(A.begin(),A.end());
	
	int i,j,k,l,r,val;
	
	for(i=0;i<n-2;i++){
		for(j=n-1;j>i+1;j--){
	
			val = (A[i]+A[j])*-1;
			l =i+1,r=j-1;
	
			while(l<=r){
				k = l + (r-l)/2;
				if(A[k]==val)break;
				else if (A[k]>val)r=k-1;
				else l=k+1;
			}
			if(A[k]==val){
				temp.clear();
				temp.push_back(A[i]);
				temp.push_back(A[k]);
				temp.push_back(A[j]);
				ans.insert(temp);
			}
		}
	}
	
	set<vector<int>>::iterator it;
    for(it=ans.begin();it!=ans.end();it++){
        returnAns.push_back(*it);
    }
    return returnAns;

}
