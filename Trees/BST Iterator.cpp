/*
InterviewBit : BST Iterator

Link: https://www.interviewbit.com/problems/bst-iterator/

Asked in:
Amazon
Apple
Facebook

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

The first call to next() will return the smallest number in BST. Calling next() again will return the next smallest number in the BST, and so on.

 Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
Try to optimize the additional space complexity apart from the amortized time complexity. 


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

// Stack to store the path from root node to be used till smallest node
stack<TreeNode*> stk;

// Creates the path from A till smallest node
void createPathTillSmallest(TreeNode* A){
    if(!A)return;
    stk.push(A);
    createPathTillSmallest(A->left);
}

// Constructor creates path till smallest node in stack
BSTIterator::BSTIterator(TreeNode *root) {
    createPathTillSmallest(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !stk.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    
    // Get top element
    TreeNode* A = stk.top();
    stk.pop();
    
    // Create path till smallest for right noode of the current node
    createPathTillSmallest(A->right);
    return A->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
