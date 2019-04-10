/*
InterviewBit : Invert the Binary Tree

Link: https://www.interviewbit.com/problems/invert-the-binary-tree/

Asked in:
Google

Given a binary tree, invert the binary tree and return it. 
Look at the example for more details.

Example : 
Given binary tree

     1
   /   \
  2     3
 / \   / \
4   5 6   7
invert and return

     1
   /   \
  3     2
 / \   / \
7   6 5   4



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
 
void mirror(TreeNode* A){
    if(!A) return;
    TreeNode* left = A->left;
    A->left = A->right;
    A->right = left;
    mirror(A->left);
    mirror(A->right);
}
TreeNode* Solution::invertTree(TreeNode* A) {

    mirror(A);
    return A;
}
