// Problem : https://leetcode.com/problems/longest-univalue-path/

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
    int longestPathHelper(TreeNode *root, int &maxPath){
        
        if(root == NULL)
            return 0;
        if(root -> left == NULL && root -> right == NULL){
            maxPath = maxPath > 1 ? maxPath : 1 ;
            return 1 ;
        }
        
        int Left = longestPathHelper(root -> left, maxPath) ;
        int Right = longestPathHelper(root -> right, maxPath) ;
        int currPath = 1 ;
        
        if(root -> left != NULL && root -> left -> val == root -> val)
            currPath = max(currPath, 1 + Left) ;
        
        if(root -> right != NULL && root -> right -> val == root -> val)
            currPath = max(currPath, 1 + Right) ;
        
        if(root -> left != NULL && root -> right != NULL){
            if(root -> left -> val == root -> val && root -> right -> val == root -> val)
                maxPath = max(maxPath, Left + Right + 1) ;
        }
        
        maxPath = max(maxPath, currPath) ;
        
        return currPath ;
    }
    
    int longestUnivaluePath(TreeNode* root) {
        
        int maxPath = 0 ;
        
        if(root == NULL)
            return 0;
        
        longestPathHelper(root, maxPath) ;
        
        return maxPath - 1 ;
    }
};