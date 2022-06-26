// Problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Time: O(N), Space: O(H)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q)
            return root ;
        
        TreeNode *leftSearch = lowestCommonAncestor(root -> left, p, q) ;
        TreeNode *rightSearch = lowestCommonAncestor(root -> right, p, q);
        
        if(leftSearch != NULL && rightSearch != NULL)
            return root ;
        
        return leftSearch == NULL ? rightSearch : leftSearch ;
    }
};