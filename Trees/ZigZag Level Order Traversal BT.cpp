/*
InterviewBit : ZigZag Level Order Traversal BT

Link: https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/

Asked in:
Amazon
Microsoft

Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example : 
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
         [15, 7]
]

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
void zigZagTraverse(stack<TreeNode*> &stk,vector<vector<int>> &ans,bool ltr){
   
    // No nodes present; all nodes covered; return
    if(stk.empty())return;
    
    // Vector to store current level of nodes
    vector<int> curr;

    // Stack to store next level of nodes
    stack<TreeNode*> newStk;
    
    TreeNode* node;
    while(!stk.empty()){

        // Get node from stack
        node = stk.top();
        stk.pop();
        curr.push_back(node->val);
        
        // Nodes for next level to be added in new stack
        TreeNode* node1;
        TreeNode* node2;

        // Left to right order, first insert left then right; otherwise opposite
        if(ltr){
            node1=node->left;
            node2=node->right;
        }
        else{
            node1=node->right;
            node2=node->left;
        }
        
        // Insert in stack if node is not null
        if(node1) newStk.push(node1);
        if(node2) newStk.push(node2);
    }       

    // Add current level of nodes vector to ans
    ans.push_back(curr);

    // Continue traversal for next level of nodes
    zigZagTraverse(newStk,ans,!ltr);
}

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {

    vector<vector<int>> ans;

    // Stack to store the current level of nodes
    stack<TreeNode*> stk;
    stk.push(A);

    // Left to right order
    bool ltr = true;

    // Recursive function that adds nodes of one level as a vector to ans in a zigzag manner
    zigZagTraverse(stk,ans,ltr);

    return ans;

}