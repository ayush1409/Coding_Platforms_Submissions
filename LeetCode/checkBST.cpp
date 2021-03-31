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
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, INT_MIN, INT_MAX) ;
    }
    
    bool isValidBSTHelper(TreeNode *root, int min, int max){
        
        if(root == NULL)
            return true ;
        
        if(root->val < min || root->val > max)
            return false ;
        
        return  isValidBSTHelper(root->left, min, root->val - 1) && 
                isValidBSTHelper(root->right, root -> val + 1, max) ;
    }
};
