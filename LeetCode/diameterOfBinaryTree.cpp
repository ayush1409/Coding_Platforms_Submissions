// Problem : https://leetcode.com/problems/diameter-of-binary-tree/ 

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
    
    int max(int a, int b){
        return a>b ? a : b ;
    }
    
    
    int height(TreeNode *root, int &maxDiameter){
        if(root == NULL)
            return -1 ;
        
        if(root->left == NULL && root->right == NULL)
            return 0 ;
        
        int leftHeight = height(root->left, maxDiameter) ;
        int rightHeight = height(root->right, maxDiameter) ;
        
        if(maxDiameter < 2 + leftHeight + rightHeight)
            maxDiameter = 2 + leftHeight + rightHeight ;
        
        return 1 + max(leftHeight, rightHeight) ;
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0 ;
        
        int maxDiameter = 0 ;
        
        height(root, maxDiameter) ;
        
        return maxDiameter ;
    }
};