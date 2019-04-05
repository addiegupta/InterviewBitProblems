/*
InterviewBit : Balanced Binary Tree

Link: https://www.interviewbit.com/problems/balanced-binary-tree/

Asked in:
Amazon

Given a binary tree, determine if it is height-balanced.

 Height-balanced binary tree : is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 
          1
         / \
        2   3

Return : True or 1 

Input 2 : 
         3
        /
       2
      /
     1

Return : False or 0 
         Because for the root node, left subtree has depth 2 and right subtree has depth 0. 
         Difference = 2 > 1. 




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

// Returns -1 if at any point tree is not balanced
int balanced(TreeNode *A){
    
    if(!A) return 0;

    // Find left and right depths
    int left = balanced(A->left);
    int right = balanced(A->right);

    // If -1 is received i.e. unbalanced tree or at this node tree is not balanced
    // return -1
    if(left == -1 || right ==-1 || abs(left-right)>1) return -1;
    
    // return max depth + 1 for this node
    return max(left,right)+1;
}
int Solution::isBalanced(TreeNode* A) {
    
   if(balanced(A)==-1)return 0;
   else return 1;
}
