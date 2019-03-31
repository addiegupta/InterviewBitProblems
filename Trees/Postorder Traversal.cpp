/*
InterviewBit : Postorder Traversal

Link: https://www.interviewbit.com/problems/postorder-traversal/

Asked in:
Amazon
Microsoft


Given a binary tree, return the postorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3
return [3,2,1].

Using recursion is not allowed.


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
vector<int> Solution::postorderTraversal(TreeNode* A) {
    
    
    // Stack to store nodes
    stack<TreeNode*> stk;
    vector<int> ans;

    if(!A) return ans;
    
    // Add root to stack    
    stk.push(A);

    // Instead of finding postorder i.e. left-right-root, find reverse i.e. root-right-left and then reverse order
    while(!stk.empty()){

        // Get parent node
        A=stk.top();
        stk.pop();
        
        // Add it to order
        ans.push_back(A->val);

        // Add left and right so that right comes on top
        if(A->left) stk.push(A->left);
        if(A->right) stk.push(A->right);
    }

    // Reverse
    reverse(ans.begin(),ans.end());

    return ans;

}
