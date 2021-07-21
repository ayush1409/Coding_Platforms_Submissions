// Problem: https://leetcode.com/problems/increasing-order-search-tree/

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
    void getInorder(TreeNode *root, vector<int> &inorder){
        if(root != NULL){
            getInorder(root -> left, inorder) ;
            inorder.push_back(root -> val) ;
            getInorder(root-> right, inorder) ;
        }
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> inorder ;
        
        getInorder(root, inorder) ;
        
        TreeNode *newRoot = new TreeNode(inorder[0]) ;
        TreeNode *temp = newRoot ;
        newRoot -> left = NULL ;
        
        for(int i = 1 ; i < inorder.size() ; i++){
            temp -> right = new TreeNode(inorder[i]) ;
            temp = temp -> right ;
            temp -> left = NULL ;
        }
        
        return newRoot ;
    }
};