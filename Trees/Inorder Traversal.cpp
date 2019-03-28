/*
InterviewBit : Inorder Traversal

Link: https://www.interviewbit.com/problems/inorder-traversal/

Asked in:
Amazon
Microsoft

Given a binary tree, return the inorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,3,2].

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

// Recursive solution
void traverse(TreeNode* A,vector<int> &ans){
    
    if(!A)return;
    
    traverse(A->left,ans);
    ans.push_back(A->val);
    traverse(A->right,ans);
    
    
}
vector<int> recursiveSolution(TreeNode* A) {
    vector<int> ans;
    traverse(A,ans);
    return ans;
    
}

// As recursion is not allowed, a data structure will be used to simulate the recursion process
// i.e. just like recursion function calls are added to stack, here the nodes will be pushed to a stack 
vector<int> iterativeSolution(TreeNode* A){

    vector<int> ans;
    stack<TreeNode*> s;
    
    // A is null when leaf node reached, stack becomes empty when all nodes covered
    while(A || !s.empty()){

        // Non null node,add to stack and traverse to left
        if(A){
            s.push(A);
            A=A->left;
        }
        // Leaf node reached,get node from stack and add to ans list and then traverse right
        else{

            // Get node
            A=s.top();
            s.pop();

            // Add node to list
            ans.push_back(A->val);

            // Traverse right
            A=A->right;
        }
    }
    return ans;
}

vector<int> Solution::inorderTraversal(TreeNode* A) {

    // This problem requires iterative solution
    return iterativeSolution(A);

    //return recursiveSolution(A);
    
}
