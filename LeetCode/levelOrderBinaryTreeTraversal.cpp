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
    vector<vector<int> > levelOrder(TreeNode* root) {
        
        vector<vector<int> > result ;
        
        if(root == NULL)
            return result ;
        vector<int> level ;
        
        TreeNode *curr ;
        unsigned int n ;
        
        queue<TreeNode *> q ;
        
        q.push(root) ;
        
        while(!q.empty()){
            
            level.clear() ;
            n = q.size() ;
            
            for(int i=1 ; i<=n ; i++){
                curr = q.front() ;
                q.pop() ;
                
                level.push_back(curr->val) ;
                
                if(curr->left != NULL)
                    q.push(curr->left) ;
                
                if(curr->right != NULL)
                    q.push(curr->right) ;
                
            }
            
            result.push_back(level) ;
            
        }
        
        return result ;
    }
};
