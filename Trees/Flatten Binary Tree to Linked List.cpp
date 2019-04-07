/*
InterviewBit : Flatten Binary Tree to Linked List

Link: https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/

Asked in:
Amazon
Microsoft
Adobe


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

// Recursively flattens tree into a linked list
void flattenTree(TreeNode* A){
    
    // Null node; return
    if(!A)return;    

    // Left node is present, flatten for left node
    if(A->left){
        
        flattenTree(A->left);

        // Save right subtree in temp node
        TreeNode*temp=A->right;

        // Set right tree as left subtree and set left subtree as null
        A->right = A->left;
        A->left=NULL;

        // Attach saved right subtree at rightmost node of the newly attached left subtree
        TreeNode* trav=A;
        while(trav->right)trav=trav->right;
        trav->right = temp;

        // Continue flattening process
        flattenTree(trav->right);
    }

    // Left node not present continue flattening process for right node
    else if(A->right)flattenTree(A->right);  

}

TreeNode* Solution::flatten(TreeNode* A) {

    flattenTree(A);

    return A;
}
