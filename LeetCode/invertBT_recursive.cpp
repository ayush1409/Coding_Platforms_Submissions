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
    TreeNode* invertTree(TreeNode* root) {
        invertTreeHelper(root) ;
        return root ;
    }
    
    void invertTreeHelper(TreeNode *root){
        if(root == NULL)
            return ;
        
        invertTreeHelper(root->left) ;
        invertTreeHelper(root->right) ;
        
        TreeNode *temp = root->left;
        root->left = root->right ;
        root->right = temp ;
    }
};
