/*
InterviewBit : Substring Concatenation

Link : https://www.interviewbit.com/problems/substring-concatenation/

Asked in:

Facebook

You are given a string, S, and a list of words, L, that are all of the same length.

Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

Example :

S: "barfoothefoobarman"
L: ["foo", "bar"]
You should return the indices: [0,9].
(order does not matter).

*/
/************************************************************************************
*************************************************************************************


Can the time complexity of this program be optimised???????????????

******************************************************************
*******************************************************************/


// We have to return starting indices where all the given strings will be found adjacent to each other
vector<int> Solution::findSubstring(string A, const vector<string> &B) {
	vector<int> ans;
	if(B.size()==0 || A.size()==0) return ans;
	
	// All words have same length
	int len = B[0].length();
	// Count of words
	int num = B.size();
	
	// Length of all words adjacent to each other is greater than strings entire length
	if(A.size()<num*len)return ans;

	// Add count of all words to hash
	unordered_map<string,int> hash;
	for(int i=0;i<B.size();i++)hash[B[i]]++;

	string temp;
	int k;
	// Temp hash stores words not yet found for particular iteration $$$
	unordered_map<string,int> tempHash;

	for(int i=0;i<=A.size()-(num*len);i++){
		// Current substring being evaluated
		temp = A.substr(i,num*len);
		// $$$  
		tempHash = hash;
		k=0;
		// Check if the words exist
		for(int j =0;j<num;j++){
			string sub = temp.substr(k,len);
			if(tempHash.find(sub)!=tempHash.end()){
				if(tempHash[sub]==1)tempHash.erase(sub);
				else tempHash[sub]--;
			}
			else break;
			k+=len;
		}
		// Found all words at this index
		if(tempHash.size()==0)ans.push_back(i);
	}

	return ans;
}

/***
Java version copied from LeetCode

class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        final Map<String, Integer> counts = new HashMap<>();
        for (final String word : words) {
            counts.put(word, counts.getOrDefault(word, 0) + 1);
        }
        final List<Integer> indexes = new ArrayList<>();
        final int n = s.length(), num = words.length, len = words[0].length();
        for (int i = 0; i < n - num * len + 1; i++) {
            final Map<String, Integer> seen = new HashMap<>();
            int j = 0;
            while (j < num) {
                final String word = s.substring(i + j * len, i + (j + 1) * len);
                if (counts.containsKey(word)) {
                    seen.put(word, seen.getOrDefault(word, 0) + 1);
                    if (seen.get(word) > counts.getOrDefault(word, 0)) {
                        break;
                    }
                } else {
                    break;
                }
                j++;
            }
            if (j == num) {
                indexes.add(i);
            }
        }
        return indexes;
    }
}

*/