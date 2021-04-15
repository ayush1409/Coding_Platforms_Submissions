/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    bool find(TreeNode *root, int x){
        
        if(root == NULL)
            return false ;
        
        if(root->val == x)
            return true ;
        
        if(root->val < x)
            return find(root->right, x) ;
        else
            return find(root->left, x) ;
    }
   
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(p == NULL || q == NULL)
            return NULL ;
        
        // case when either p or q are LCA
        if(root == p || root == q)
            return root ;
        
        // Swap pointers if p->val > q->val
        if(p->val > q->val){
            TreeNode *temp = p ;
            p = q ;
            q = temp ;
        }
        
        if(root->val > q->val)
            return lowestCommonAncestor(root->left, p, q) ;
        else if(root->val < p->val)
            return lowestCommonAncestor(root->right, p, q) ;
        
        if(find(root->left, p->val) && find(root->right, q->val))
            return root ;
        
        return NULL ;
    }
};
