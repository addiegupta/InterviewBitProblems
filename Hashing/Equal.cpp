/*
InterviewBit : Equal

Link : https://www.interviewbit.com/problems/equal

Asked in:
Facebook

Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array

Note:

1) Return the indices `A1 B1 C1 D1`, so that 
  A[A1] + A[B1] = A[C1] + A[D1]
  A1 < B1, C1 < D1
  A1 < C1, B1 != D1, B1 != C1 
**************************************************************************************** IMPORTANT 
2) If there are more than one solutions, 
   then return the tuple of values which are lexicographical smallest. 

Assume we have two solutions
S1 : A1 B1 C1 D1 ( these are values of indices int the array )  
S2 : A2 B2 C2 D2

S1 is lexicographically smaller than S2 iff
  A1 < A2 OR
  A1 = A2 AND B1 < B2 OR
  A1 = A2 AND B1 = B2 AND C1 < C2 OR 
  A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2
Example:

Input: [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5] (O index)
If no solution is possible, return an empty list.


*/

vector<int> Solution::equal(vector<int> &A) {

    // key: sum
    // value: possible pairs of indices to get this sum
    unordered_map<int,vector<pair<int,int>>> hash;
    int n = A.size();
    // Add all possible sums to hash
    // Note: i is always less than j
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            hash[A[i]+A[j]].push_back({i,j});
        }
    }
    vector<int> ans (4,INT_MAX);
    // Iterate over hashmap
    for(auto it = hash.begin();it!=hash.end();it++){
        // Get the current vector that contains index pairs that form this sum(key)
        vector<pair<int,int>> curr = it->second; 
        
        // Some values exist
        if(curr.size()>=2){
            int m = curr.size();
            bool found =false;
            for(int i=0;i<m-1;i++){
                for(int j=i+1;j<m;j++){
                    // To avoid duplication 
                    //  A1 < C1, B1 != D1, B1 != C1 
                    if(curr[i].first<curr[j].first && curr[i].second!=curr[j].second && curr[i].second != curr[j].first){
                        // ************************************** Check point 2 in description; this is a lexicographic requirement of the answer vector
                        if(curr[i].first < ans[0] || 
                            (curr[i].first==ans[0] && curr[i].second <ans[1]) ||
                            (curr[i].first==ans[0] && curr[i].second ==ans[1] && curr[j].first<ans[2]) ||
                             (curr[i].first==ans[0] && curr[i].second ==ans[1] && curr[j].first == ans[2] && curr[j].second <ans[3])){ 
                            ans[0] = curr[i].first;
                            ans[1] = curr[i].second;
                            ans[2] = curr[j].first;
                            ans[3] = curr[j].second;
                            found = true;
                        }                        
                    } 
                    if(found)break;
                }
                if(found)break;
            }
        }
    }
    // No answer found
    if(ans[0]==INT_MAX) ans.clear();
    return ans;
}
