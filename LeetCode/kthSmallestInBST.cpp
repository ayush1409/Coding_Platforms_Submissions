// Problem : https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int CountElements(TreeNode *root){
        if(root == NULL)
            return 0 ;
        if(root -> left == NULL && root -> right == NULL)
            return 1 ;
        
        return 1 + CountElements(root -> left) + CountElements(root -> right) ;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL)
            return 0 ;
        
        int lCount = CountElements(root -> left) ;
        
        if(lCount + 1 == k)
            return root -> val ;
        
        if(lCount >= k)
            return kthSmallest(root -> left, k) ;
        
        return kthSmallest(root -> right , k - lCount - 1) ;
    }
};