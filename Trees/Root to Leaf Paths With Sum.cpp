/*
InterviewBit : Root to Leaf Paths With Sum

Link: https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/

Asked in:
Amazon
Microsoft
Yahoo


Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
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
void findPathSums(TreeNode* A,vector<int> currPath,int currSum,int B,vector<vector<int>> &ans){
    
    // If null is reached then return
    // This is not a leaf node
    if(!A) return;
    
    // Add current value to path and sum
    currPath.push_back(A->val);
    currSum+=A->val;

    // This is leaf node, compare sums
    if(!A->left && !A->right){
        if(currSum==B) ans.push_back(currPath);
        return;
    }

    // Traverse left and right
    findPathSums(A->left,currPath,currSum,B,ans);
    findPathSums(A->right,currPath,currSum,B,ans);
    
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {

    vector<vector<int>> ans;
    vector<int> currPath;
    int currSum=0;

    findPathSums(A,currPath,currSum,B,ans);
    
    return ans;

}
