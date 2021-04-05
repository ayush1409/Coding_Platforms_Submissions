// Problem : https://leetcode.com/problems/same-tree/

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL)
            if(q == NULL)
                return true ;
            else
                return false ;
        if(q == NULL)
            if(p == NULL)
                return true ;
            else
                return false ;
        
        return (p -> val == q -> val) && isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right) ;
    
    }
};
