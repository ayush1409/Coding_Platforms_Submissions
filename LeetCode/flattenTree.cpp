// Problem : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    TreeNode *getListEnd(TreeNode *root){
        if(root == NULL)
            return NULL ;
        
        while(root -> right != NULL)
            root = root -> right ;
        return root ;
    }
    
    TreeNode* preorder(TreeNode *root){
        
        if(root != NULL){
            
            TreeNode *rootLeft = root -> left ;
            TreeNode *rootRight = root -> right ;
            root -> left = NULL ;
            
            root -> right = preorder(rootLeft) ;
            
            TreeNode *last = getListEnd(root) ;
            
            if(last != NULL)
                last -> right = preorder(rootRight) ;
            else
                root -> right = preorder(rootRight) ;
            
            return root ;
        }
        return NULL ;
    }
    
    void flatten(TreeNode* root) {
        
        if(root == NULL || (root -> left == NULL && root -> right == NULL))
            return ;
       
        root = preorder(root) ;
        
    }
};