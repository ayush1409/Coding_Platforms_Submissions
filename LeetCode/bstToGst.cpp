// Problem: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

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
    
    void bstToGstHelper(TreeNode *root, int &sum){
        if(root == NULL)
            return ;
        
        bstToGstHelper(root -> right, sum) ;
        
        root -> val += sum ;
        sum = root -> val ;
        
        bstToGstHelper(root -> left, sum) ;
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        
        int sum = 0 ; 
        bstToGstHelper(root, sum) ;
        
        return root ;
        
    }
};