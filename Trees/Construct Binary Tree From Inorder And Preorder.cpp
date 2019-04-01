/*
InterviewBit : Construct Binary Tree From Inorder And Preorder

Link: https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/

Asked in:
Amazon
Microsoft


Given preorder and inorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input :
        Preorder : [1, 2, 3]
        Inorder  : [2, 1, 3]

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


// Recursive function that builds the tree
TreeNode* buildTreeUtil(vector<int> &pre,vector<int> &in, int start,int end,int &parentIndex,unordered_map<int,int> &hash){
    
    // All nodes covered
    if(start>end)return NULL;

    // Current parent is at index 'parentIndex' in the preorder vector, increment for next parent 
    // i.e. left child of this node will be at +1 position
    // subsequently when left subtree is done, right subtree is calculated and parentIndex variable would have reached its
    // correct position. Note parentIndex is passed by reference

    TreeNode* root = new TreeNode(pre[parentIndex++]);

    // Index of parent in inorder vector
    int inorderParentIndex = hash[root->val];

    // Calculate left and right subtrees
    root->left = buildTreeUtil(pre,in,start,inorderParentIndex - 1,parentIndex,hash);
    root->right = buildTreeUtil(pre,in,inorderParentIndex + 1,end,parentIndex,hash);

    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    
    // Empty tree
    if(A.size()==0)return NULL;

    // Store key value mapping of nodes from inorder vector (value->index in inorder vector)
    unordered_map<int,int> hash;    
    for(int i=0;i<B.size();i++) hash[B[i]]=i;

    // The parent in the particular recursive call is determined using this variable
    // It keeps on increasing by 1 for every recursive call
    int parentIndex = 0;
    return buildTreeUtil(A,B,0,B.size()-1,parentIndex,hash);

}