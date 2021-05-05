// Problem : https://leetcode.com/problems/deepest-leaves-sum/

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
    int max(int x, int y){
        return x > y ? x : y ;
    }
    
    void computeSum(TreeNode *root, int level, int rootHeight, int &sum){
        if(root == NULL)
            return ;
        
        if(level == rootHeight){
            sum += root -> val ;
        }
        
        computeSum(root -> left, level + 1, rootHeight, sum) ;
        computeSum(root -> right, level + 1, rootHeight, sum) ;
        
    }
    
    int height(TreeNode *root){
        if(root == NULL)
            return 0 ;
        if(root -> left == NULL && root -> right == NULL)
            return 1 ;
        
        int leftHeight = height(root -> left) ;
        int rightHeight = height(root -> right) ;
        
        return 1 + max(leftHeight, rightHeight) ;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL)
            return 0 ;
        if(root -> left == NULL && root -> right == NULL)
            return root -> val ;
        
        int rootHeight = height(root) ;
        int sum = 0 ;
        
        computeSum(root, 1, rootHeight, sum) ;
        
        return sum ;
    }
};