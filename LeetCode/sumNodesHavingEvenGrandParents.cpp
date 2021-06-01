// Problem: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

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
    int sumGrandChild(TreeNode *root){
        int sum = 0 ;
        
        sum += (root -> left == NULL) ? 0 : ((root -> left -> left == NULL) ? 0 : root -> left -> left -> val) ;
        sum += (root -> left == NULL) ? 0 : ((root -> left -> right == NULL) ? 0 : root -> left -> right -> val) ;
        sum += (root -> right == NULL) ? 0 : ((root -> right -> left == NULL) ? 0 : root -> right -> left -> val) ;
        sum += (root -> right == NULL) ? 0 : ((root -> right -> right == NULL) ? 0 : root -> right -> right -> val) ;
        
        return sum ;
    }

    void sumEGPHelper(TreeNode *root, int &sum){
        if(root == NULL)
            return  ;
            
        sumEGPHelper(root -> left, sum) ;
        sumEGPHelper(root -> right, sum) ;
        
        if((root -> val) % 2)
            return ;
        
        sum += sumGrandChild(root) ;
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        if(root == NULL || (root -> left == NULL && root -> right == NULL))
            return 0 ;
        
        int sum = 0 ;
        sumEGPHelper(root, sum) ;
        
        return sum ;
    }
};