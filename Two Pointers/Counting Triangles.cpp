/*
InterviewBit : Counting Triangles

Link : https://www.interviewbit.com/problems/counting-triangles


You are given an array of N non-negative integers, A0, A1 ,…, AN-1.
Considering each array element Ai as the edge length of some line segment, count the number of triangles which you can form using these array values.

Notes:

You can use any value only once while forming each triangle. Order of choosing the edge lengths doesn’t matter. Any triangle formed should have a positive area.

Return answer modulo 109 + 7.

For example,

A = [1, 1, 1, 2, 2]

Return: 4



*/
// O(n^2 log n) approach. fix 2 sides and binary search for 3rd side. once 3rd side is found,
// all values present after this value are also included in answer
int initialONSquaredLogNApproach(int n,vector<int> &A){
	
	// Iterators for array
    int i,j,mid,l,r;

    // return ans%modulo
    int modulo= (int)(pow(10,9)+7);
    int ans =0;
    // Iterate over array; for every i find suitable other 2 sides
    for(i=0;i<n-2;i++){
    	// For every j, binary search for 3rd side
    	for(j=i+1;j<n-1;j++){

            l=j+1;
            r=n-1;
            while(l<=r){
                mid=l + (r-l)/2;
             
             	// Not a possible solution increase l
             	if(A[mid]<(A[i]+A[j]))l=mid+1;
             	// Else narrow down the binary search array to get the exact value after which
             	// possible triangles are found
                else r=mid-1;
            }
            if(l-j>1)ans+= (l-j-1);
            if(ans>=modulo)ans%=modulo;
        }
    }
    return ans % modulo;

}
// O(n^2) approach; fix i and use 2 pointer approach(increment left or decrement right based on conditions)
// to find other 2 sides
int newONSquaredApproach(int n,vector<int> &A){
	 // Iterators for array
    int i,j,l,r;

	// return ans%modulo
    int modulo= (int)(pow(10,9)+7);
    int ans =0;


    for(i=2;i<n;i++){
        l =0;
        r =i-1;
        while(l<r){
        	// Add to solution number of triangles formed using these values
        	// as well as due to values in between l and r ( by using r-l)
            if(A[l]+A[r]>A[i]){
                ans+=r-l;
                ans%=modulo;
                r--;
            }
            else l++;
        }
    }
    return ans%modulo;

}
int Solution::nTriang(vector<int> &A) {
  	

    int n = A.size();
    
    // Insufficient number of sides
    if(n<3)return 0;
    
    // Sort the array
    sort(A.begin(),A.end());
    

    // return initialONSquaredLogNApproach(n,A);
    return newONSquaredApproach(n,A);
}