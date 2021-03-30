// Problem : https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int sumNumbers(TreeNode* root) {
        int TotalSum = 0 ;
        sumNumbersHelper(root,TotalSum, 0) ;
        return TotalSum ;
    }
    
    void sumNumbersHelper(TreeNode* root, int &TotalSum, int sum){
        if(root == NULL)
            return ;
        
        sum = sum*10 + root->val ;				
        
        if(!root->left && !root->right){
            TotalSum += sum ;
            return ;
        }
        
        sumNumbersHelper(root->left, TotalSum, sum) ;
        sumNumbersHelper(root->right, TotalSum, sum) ;
    }
};
