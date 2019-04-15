/*
InterviewBit : Sorted Array To Balanced BST

Link: https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/

Asked in:
Amazon
Microsoft

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Example :


Given A : [1, 2, 3]
A height balanced BST  : 

      2
    /   \
   1     3


*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Insert nodes like binary search
TreeNode* insertMidInTree(const vector<int> &A,int l,int r){
	
	if(l>r)return NULL;
	
	int mid = l - (l-r)/2;

	// Set mid node as root 
	TreeNode* root = new TreeNode(A[mid]);
	
	// Set left and right as mids of left and right subarrays recursively
	root->left = insertMidInTree(A,l,mid-1);
	root->right = insertMidInTree(A,mid+1,r);

	return root;

}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
	if(A.size()==0)return NULL;

	return insertMidInTree(A,0,A.size()-1);
}
