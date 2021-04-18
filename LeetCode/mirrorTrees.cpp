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
    
    bool isSymmetricHelper(TreeNode *a, TreeNode *b){
    
        if(a == NULL && b == NULL)
            return true ;
        
        if(a == NULL && b != NULL)
            return false ;
        if(a != NULL && b == NULL)
            return false ;
        
        return a->val == b->val && isSymmetricHelper(a->left, b->right) &&
            isSymmetricHelper(a->right, b->left) ;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true ;
        
        if(root->left == NULL && root->right == NULL)
            return true ;
        
        if(root -> left != NULL && root -> right == NULL)
            return false ;
        if(root -> left == NULL && root -> right != NULL)
            return false ;
        
        return root->left->val == root->right->val && isSymmetricHelper(root->left, root->right) ;
    }
};