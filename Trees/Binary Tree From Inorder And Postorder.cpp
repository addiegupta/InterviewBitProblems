/*
InterviewBit : Binary Tree From Inorder And Postorder

Link: https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/

Asked in:
Amazon
Microsoft


Given inorder and postorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : 
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]

Return : 
            1
           / \
          2   3


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


// Searches for the element val in the subarray A[start,end]
int search (vector<int> &A, int start,int end,int val){
    
    for(int i=start;i<=end;i++) if(A[i]==val)return i;
}

// Recursive function used to build the tree
TreeNode* buildTreeUtil(vector<int> &A,vector<int> &B,int start,int end,int &parentIndex){
    
    // Leaf node encountered in previous call, return NULL 
    if(start>end) return NULL;

    // Create a parent node using parentIndex
    // Decrement parentIndex as parent for next recursive call be 1
    TreeNode* root = new TreeNode(B[parentIndex--]);

    // Leaf node reached 
    if(start==end) return root;

    // Search for the value of newly created node in inorder vector
    int i = search(A,start,end,root->val);

    /*
        Most important steps
        
        The newly created node (say p) has been found in inorder traversal at index i
        Now its subtree is made as follows
        The left subtree nodes are between start and i-1,right subtree nodes in i+1 and end in vector A

        Now first right subtree is created (Why?)
        Because parentIndex is being calculated for this order i.e. parentIndex value will be for right subtrees due to post order traversal
        Once rightsubtree is calculated, left subtree is made.
        Note parentIndex is passed by reference
    */
    root->right = buildTreeUtil(A,B,i+1,end,parentIndex);
    root->left = buildTreeUtil(A,B,start,i-1,parentIndex);

    return root;
}

// Main function
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    
    // The root node will be the last element in postorder vector B
    int parentIndex = B.size()-1;

    // Recursively builds the tree from inorder and postorder vectors
    return buildTreeUtil(A,B,0,B.size()-1,parentIndex);

}