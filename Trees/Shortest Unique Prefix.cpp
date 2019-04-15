/*
InterviewBit : Shortest Unique Prefix

Link: https://www.interviewbit.com/problems/shortest-unique-prefix/

Asked in:
Google

Find shortest unique prefix to represent each word in the list.

Example:

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov
 NOTE : Assume that no word is prefix of another. In other words, the representation is always possible

*/

// Trie Node to store all the words
struct Node{
	Node* children[26];
	// Count stores the number of words containing prefix till till node
	int count;
};
// Returns a new node initialised with NULL and 0 count
Node* getNode(){
	Node* pNode = new Node();
	for(int i=0;i<26;i++)pNode->children[i]=NULL;
	pNode->count = 0;
	return pNode;
}

// Inserts a word in a trie
void insertWord(Node* parent,string s){
	Node* trav = parent;
	for(int i=0;i<s.size();i++){
		int ind = s[i]-'a';
		
		// Node not yet present for this character
		if(trav->children[ind]==NULL){
			trav->children[ind] = getNode();
		}

		// Increment counter for words
		trav->count++;
		trav = trav->children[ind];
	}
}

// Find the prefix for string s
string findPrefix(Node* parent,string s){
	
	// Traversal pointer
	Node* trav = parent;
	for(int i=0;i<s.size();i++){
		int ind = s[i]-'a';
		// Only 1 word contains this prefix
		if(trav->count==1)return s.substr(0,i);
		trav=trav->children[ind];
	}
	return s;
}
vector<string> Solution::prefix(vector<string> &A) {
	vector<string> ans;
	Node* parent = getNode();
	int n = A.size();
	for(int i=0;i<n;i++){
		insertWord(parent,A[i]);
	}
	for(int i=0;i<n;i++){
		ans.push_back(findPrefix(parent,A[i]));
	}
	return ans;
}