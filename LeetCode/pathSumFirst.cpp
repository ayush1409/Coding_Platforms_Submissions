// Problem : https://leetcode.com/problems/path-sum/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasPathSumHelper(root, targetSum, 0) ;
    }
    
    bool hasPathSumHelper(TreeNode *root, int targetSum, int sum){
        
        if(root == NULL)
            return false ;
        
        sum += root -> val ;
        
        if(sum == targetSum && (!root->left && !root->right))
            return true ;
        
        return hasPathSumHelper(root->left, targetSum, sum) || hasPathSumHelper(root->right, targetSum, sum) ;
    }
};
