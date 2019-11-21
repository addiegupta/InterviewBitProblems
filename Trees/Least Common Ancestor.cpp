/*
InterviewBit : Least Common Ancestor

Link: https://www.interviewbit.com/problems/least-common-ancestor/

Asked in:
Amazon
Facebook
Microsoft
Adobe
Google


Find the lowest common ancestor in an unordered binary tree given two values in the tree.

 Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants. 
Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of nodes 5 and 1 is 3.

 LCA = Lowest common ancestor 
Please note that LCA for nodes 5 and 4 is 5.

You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.



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

TreeNode* findLCA(TreeNode*A,int B,int C){
    if(!A) return NULL;
    // If this node is one of the values then other value must necessarily be a child of this tree
    // otherwise control wouldnt have reached here; hence this is the LCA
    if(A->val == B || A->val == C) return A;

    // Look in left and right subtrees
    TreeNode* leftLca = findLCA(A->left,B,C);
    TreeNode* rightLca = findLCA(A->right,B,C);

    // If both subtrees return nonnull i.e. a reqd. node was found there, then this node is LCA
    if(leftLca && rightLca)return A;   

    // Else return subtree where nodes were found from where the LCA node will be propagated upwards
    return (leftLca)? leftLca: rightLca;

}

// Look for the given value  in the tree
bool findNode(TreeNode* A,int B){
    if(!A) return false;
    if(A->val==B) return true;

    return findNode(A->left,B) || findNode(A->right,B);
}

// Main method
int Solution::lca(TreeNode* A, int B, int C) {
    
    // If either node is not present in the tree, return -1
    if(!findNode(A,B) || !findNode(A,C)) return -1;
    
    // No need to check for null as both values exist in tree
    return findLCA(A,B,C)->val;
}
