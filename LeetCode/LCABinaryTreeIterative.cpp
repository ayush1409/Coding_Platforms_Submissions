// Problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Time: O(h^2), Space: O(h)

class Solution {
public:
    
    bool findPath(TreeNode *root, TreeNode *p, vector<TreeNode*> &path){
        if(root == NULL)
            return false ;
        
        path.push_back(root) ;
        
        if(root == p)
            return true ;
            
        bool leftSearch = findPath(root -> left, p, path) ;
        bool rightSearch = findPath(root -> right, p, path) ;
        
        if(leftSearch || rightSearch)
            return true ;
        
        path.pop_back() ;
        return false ;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ancesstors_p, ancesstors_q ;
        
        findPath(root, p, ancesstors_p) ;
        findPath(root, q, ancesstors_q) ;
                
        for(int i = ancesstors_p.size()-1; i >= 0 ; i--){
            for(int j = ancesstors_q.size()-1 ; j >= 0 ; j--)
                if(ancesstors_p[i] == ancesstors_q[j])
                    return ancesstors_p[i] ;
        }
        return NULL ;
    }
};