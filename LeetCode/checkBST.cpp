// Problem : https://leetcode.com/problems/validate-binary-search-tree/

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
    
    bool isValidBSTHelper(TreeNode *root, int min, int max){
        if(root == NULL)
            return true ;
        
        if(root -> val == INT_MAX && root -> right  != NULL)
            return false ;
        
        if(root -> val == INT_MIN && root -> left != NULL)
            return false ;
    
        if(root -> val < min || root -> val > max) 
            return false ;
        
        bool a = true, b = true ; 
        if(root -> left)
            a = isValidBSTHelper(root -> left, min, root -> val-1) ;
        if(root -> right)        
            b = isValidBSTHelper(root -> right, root -> val+1, max) ;
        
        return a && b ;
    }
    
    
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, INT_MIN, INT_MAX) ;
    }
   
};