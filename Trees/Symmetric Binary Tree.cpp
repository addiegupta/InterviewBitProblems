/*
InterviewBit : Symmetric Binary Tree

Link: https://www.interviewbit.com/problems/symmetric-binary-tree/

Asked in:
Amazon

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example :

    1
   / \
  2   2
 / \ / \
3  4 4  3
The above binary tree is symmetric. 
But the following is not:

    1
   / \
  2   2
   \   \
   3    3
Return 0 / 1 ( 0 for false, 1 for true ) for this problem


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

// For the given 2 nodes, check if their values are equal
// Then recur for As left,Bs right and Bs right, As left to check for symmetry
bool symmetric(TreeNode* A, TreeNode* B){
    
    if(!A || !B)return A == B;
    if(A->val != B->val) return 0;

    return symmetric(A->left,B->right) && symmetric(A->right,B->left);

} 
int Solution::isSymmetric(TreeNode* A) {
    
    // If root is null then tree is symmetric
    return !A || symmetric(A->left,A->right);
}
