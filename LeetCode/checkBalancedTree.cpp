// Problem : https://leetcode.com/problems/balanced-binary-tree/

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
    
    int height(TreeNode *root){
        if(root == NULL)
            return 0 ;
        int leftHeight = height(root -> left) ;
        int rightHeight = height(root -> right) ;
        
        return 1 + max(leftHeight, rightHeight) ;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL || (root -> left == NULL && root -> right == NULL))
            return true ;
        
        int leftHeight = height(root -> left) ;
        int rightHeight = height(root -> right) ;
        
        return abs(rightHeight - leftHeight) <= 1 && 
                isBalanced(root -> left) && isBalanced(root -> right) ;
            
    }
};