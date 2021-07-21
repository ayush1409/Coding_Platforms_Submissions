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
    TreeNode *buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int i, int j, int &k){
        if(i > j)
            return NULL ;
        
        if(i == j && preorder[k] == inorder[i])
            return new TreeNode(preorder[k++]) ;
        
        int mid ;
        for(mid = i ; mid < inorder.size() ; mid++)
            if(preorder[k] == inorder[mid])
                break ;

        TreeNode *root = new TreeNode(preorder[k]) ;
        k++ ;
        root -> left = buildTreeHelper(preorder, inorder, i, mid-1, k) ;
        root -> right = buildTreeHelper(preorder, inorder, mid+1, j, k) ;
        
        return root ;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() != inorder.size())
            return NULL ;
        
        int k = 0 ;
        return buildTreeHelper(preorder, inorder, 0, inorder.size()-1, k);
    }
};