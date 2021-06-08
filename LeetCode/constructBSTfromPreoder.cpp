// Problem: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    TreeNode *bstFromPreorderHelper(vector<int> &preorder, vector<int> &inorder, int i, int j, int &k){
        if(i > j)
            return NULL ;
        if(i == j && preorder[k] == inorder[i])
            return new TreeNode(preorder[k++]) ;
        
        int mid = 0 ;
        for(mid = i ; mid <= j ; mid++)
            if(inorder[mid] == preorder[k])
                break ;
        
        TreeNode *root = new TreeNode(inorder[mid]) ;
        k++ ;
        
        root -> left = bstFromPreorderHelper(preorder, inorder, i, mid-1, k) ;
        root -> right = bstFromPreorderHelper(preorder, inorder, mid+1, j, k) ;
        
        return root ;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder(preorder.begin(), preorder.end()) ;
        sort(inorder.begin(), inorder.end()) ;
        
        int k = 0 ;
        return bstFromPreorderHelper(preorder, inorder, 0, inorder.size()-1, k) ;
    }
};