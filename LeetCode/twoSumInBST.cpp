// Problem: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

// Time: O(N), Space: O(N)

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
    
    void getInorder(TreeNode *root, vector<int> &inorder){
        if(root == NULL)
            return ;
        getInorder(root -> left, inorder) ;
        inorder.push_back(root -> val) ;
        getInorder(root -> right, inorder) ;
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder ;
        getInorder(root, inorder) ;
        
        int n = inorder.size() ;
        int low = 0, high = n-1 ;
        
        while(low < high){
            if(inorder[low] + inorder[high] == k)
                return true ;
            
            if(inorder[low] + inorder[high] < k)
                low++ ;
            else
                high-- ;
        }
        
        return false ;
    }
};