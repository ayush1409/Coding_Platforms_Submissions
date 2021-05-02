// Problem : https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int max(int x, int y){
        return x > y ? x : y ;
    }
    int maxPathHelper(TreeNode *root, int &pathSum){
        
        if(root == NULL)
            return 0 ;
        
        int leftMax = maxPathHelper(root -> left, pathSum) ;
        int rightMax = maxPathHelper(root -> right, pathSum) ;
        
        int currentMax = max(max(leftMax,rightMax) + root -> val, root -> val) ;
        int currentMaxAsRoot = max(currentMax, leftMax + rightMax + root -> val) ;
        
        pathSum = max(currentMaxAsRoot, pathSum) ;
        
        return currentMax ;
    }
    
    
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0 ;
        int pathSum = INT_MIN ;
        
        maxPathHelper(root, pathSum) ;
        
        return pathSum ;
    }
};