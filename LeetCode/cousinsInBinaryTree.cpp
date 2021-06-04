// Problem: https://leetcode.com/problems/cousins-in-binary-tree/

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
    int depthX = -1, depthY = -2 ;
    bool flag = true ;
    
    void isCousinHelper(TreeNode *root, int x, int y, int depth){
        if(root == NULL)
            return ;
        
        if(root -> val == x)
            depthX = depth ;
        if(root -> val == y)
            depthY = depth ;
        
        if(root -> left && root -> right){
            if(root -> left -> val == x && root -> right -> val == y)
                flag = false ;
            if(root -> right -> val == x && root -> left -> val == y)
                flag = false ;
        }
        
        isCousinHelper(root -> left, x, y, depth + 1) ;
        isCousinHelper(root -> right, x, y, depth + 1) ;
        
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL)
            return false ;
        
        isCousinHelper(root, x, y, 0) ;
        
        return flag && (depthX == depthY) ;
    }
};