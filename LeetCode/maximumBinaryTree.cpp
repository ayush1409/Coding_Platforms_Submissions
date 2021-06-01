// Problem: https://leetcode.com/problems/maximum-binary-tree/

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
    TreeNode* constructTree(vector<int> &num, int l, int r){
        if(l > r)
            return NULL ;
        
        if(l == r)
            return new TreeNode(num[l]) ;
        
        int maxIdx = l, max = num[l] ;
        for(int i = l ; i <= r ; i++){
            if(max < num[i])
                max = num[i], maxIdx = i ;
        }
        
        TreeNode *node = new TreeNode(max) ;
        node -> left = constructTree(num, l, maxIdx-1) ;
        node -> right = constructTree(num, maxIdx+1, r) ;
        
        return node ;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        return constructTree(nums, 0, nums.size()-1) ;
    
    }
};