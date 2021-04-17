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
    
    void preorderHelper(TreeNode *root, vector<int> &preorder){
        
        if(root != NULL){
            preorder.push_back(root->val) ;
            preorderHelper(root->left, preorder) ;
            preorderHelper(root->right, preorder) ;
        }
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder ;
        preorderHelper(root, preorder) ;
        return preorder ;
    }
    
    
};