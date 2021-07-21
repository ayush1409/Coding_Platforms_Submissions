// Problem: https://leetcode.com/problems/binary-tree-paths/

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
    void pathsHelper(TreeNode *root, string s, vector<string> &paths){
        if(root == NULL){
            return ;
        }
        
        if(root -> left == NULL && root -> right == NULL){
            paths.push_back(s + to_string(root -> val)) ;
            return ;
        }
        
        if(root -> left != NULL)
            pathsHelper(root -> left, s + to_string(root -> val) + "->", paths) ;
        
        
        if(root -> right != NULL)
            pathsHelper(root -> right, s + to_string(root -> val) + "->", paths) ;
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths ;
        string s = "" ;
        
        pathsHelper(root, s, paths) ;
        
        return paths;
    }
};