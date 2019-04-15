/*
InterviewBit : Hotel Reviews

Link: https://www.interviewbit.com/problems/hotel-reviews/

Asked in:
Booking.com

Given a set of reviews provided by the customers for different hotels and a string containing “Good Words”, you need to sort the reviews in descending order according to their “Goodness Value” (Higher goodness value first). We define the “Goodness Value” of a string as the number of “Good Words” in that string.

Note: Sorting should be stable. If review i and review j have the same “Goodness Value” then their original order would be preserved.

 You are expected to use Trie in an Interview for such problems 

Constraints:

1.   1 <= No.of reviews <= 200
2.   1 <= No. of words in a review <= 1000
3.   1 <= Length of an individual review <= 10,000
4.   1 <= Number of Good Words <= 10,000
5.   1 <= Length of an individual Good Word <= 4
6.   All the alphabets are lower case (a - z)
Input:

S : A string S containing "Good Words" separated by  "_" character. (See example below)
R : A vector of strings containing Hotel Reviews. Review strings are also separated by "_" character.
Output:

A vector V of integer which contain the original indexes of the reviews in the sorted order of reviews. 

V[i] = k  means the review R[k] comes at i-th position in the sorted order. (See example below)
In simple words, V[i]=Original index of the review which comes at i-th position in the sorted order. (Indexing is 0 based)
Example:

Input: 
S = "cool_ice_wifi"
R = ["water_is_cool", "cold_ice_drink", "cool_wifi_speed"]

Output:
ans = [2, 0, 1]
Here, sorted reviews are ["cool_wifi_speed", "water_is_cool", "cold_ice_drink"]


*/
struct TrieNode{
    TrieNode* children[26];
    bool endOfWord;
};

// Returns empty TrieNode
TrieNode* getNode(){
    TrieNode* newNode = new TrieNode();
    for(int i=0;i<26;i++)newNode->children[i]=NULL;
    newNode->endOfWord=false;
    return newNode;
}

// Inserts string in trie
void insertInTrie(string s,TrieNode* trie){
    if(s.size()==0)return;

    for(int i=0;i<s.size();i++){
        int ind = s[i]-'a';

        if(trie->children[ind]==NULL)trie->children[ind]=getNode();

        trie=trie->children[ind];
    }
    trie->endOfWord=true;
}

// Finds the string in trie
bool findInTrie(string s,TrieNode* trie){

    for(int i=0;i<s.size();i++){
        int ind = s[i]-'a';
        if(trie->children[ind]==NULL)return false;

        trie = trie->children[ind];
    }
    return trie->endOfWord;
}

//  Sorts the vector of pairs by second integer i.e. the count of good words
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) 
{   if(a.second == b.second) return a.first < b.first;
    return (a.second > b.second); 
}

vector<int> Solution::solve(string A, vector<string> &B) {
    
    // Insert good words in trie
    vector<int> ans;
    TrieNode* trie = getNode();
    string word;
    for(int i=0;i<A.size();i++){
        if(A[i]=='_'){
            insertInTrie(word,trie);
            word.clear();
        }
        else{
            word.append(1,A[i]);
        }
    }
    insertInTrie(word,trie);

    // Create answer with vector of pairs of index, count
    vector<pair<int,int>> hash;
    int count=0;
    for(int i=0;i<B.size();i++){
        count=0;
        word.clear();
        for(int j=0;j<B[i].size();j++){
            if(B[i][j]=='_'){
                if(findInTrie(word,trie)){
                    count++;
                }
                word.clear();
            }
            else{
                word.append(1,B[i][j]);
            }
        }
        if(findInTrie(word,trie))count++;
        hash.push_back({i,count});
    }

    // Return in required format
    sort(hash.begin(), hash.end(), sortbysec);
    for(int i=0;i<hash.size();i++)ans.push_back(hash[i].first);
    return ans; 

}
