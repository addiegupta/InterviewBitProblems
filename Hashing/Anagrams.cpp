/*
InterviewBit : Anagrams

Link : https://www.interviewbit.com/problems/anagrams/

Asked in:
Amazon
Microsoft


Given an array of strings, return all groups of strings that are anagrams. Represent a group by a list of integers representing the index in the original list. Look at the sample case for clarification.

 Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', formed from 'rasp' 
 Note: All inputs will be in lower-case. 
Example :

Input : cat dog god tca
Output : [[1, 4], [2, 3]]
cat and tca are anagrams which correspond to index 1 and 4. 
dog and god are another set of anagrams which correspond to index 2 and 3.
The indices are 1 based ( the first element has index 1 instead of index 0).

 Ordering of the result : You should not change the relative ordering of the words / phrases within the group. Within a group containing A[i] and A[j], A[i] comes before A[j] if i < j.


*/
vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    
    // Hash map for string -> vector of ints pairs
    unordered_map<string,vector<int>> hash;
    
    vector<vector<int>> ans;
    int n = A.size();

    // Iterate over strings
    for(int i=0;i<n;i++){

    	// Sort current string
        string tmp = A[i];
        sort(tmp.begin(),tmp.end());

        // Add 1 based index to the vector corresponding to this sorted string
        hash[tmp].push_back(i+1);
    }
    

    for(auto it=hash.begin();it!=hash.end();it++){
    	// Add all vectors to ans
        ans.push_back(it->second);
    }

    return ans;
}