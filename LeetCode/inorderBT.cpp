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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder ;
        inorderTraversalHelper(root, inorder);
        return inorder ;
    }
    
    void inorderTraversalHelper(TreeNode *root, vector<int> &inorder){
        if(root != NULL){
            inorderTraversalHelper(root->left, inorder) ;
            inorder.push_back(root->val) ;
            inorderTraversalHelper(root->right, inorder) ;
        }
    }
};
