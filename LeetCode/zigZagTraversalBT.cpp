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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result ;
        vector<int> level ;
        unsigned int n ;
        TreeNode *curr = NULL;
        if(root ==NULL)
            return result ;
        
        int level_iter = 0 ;
        
        queue<TreeNode *> q ;
        q.push(root) ;
        
        while(!q.empty()){
            
            level.clear() ;
            n = q.size() ;
            
            for(int i = 1 ; i<=n ; i++){
                curr = q.front() ;
                q.pop() ;

                level.push_back(curr->val) ;

               
                if(curr -> left != NULL)
                    q.push(curr->left) ;
                if(curr -> right != NULL)
                    q.push(curr->right) ;
                
            }
            if(level_iter % 2 != 0)
                reverse(level.begin(), level.end()) ;
            
            level_iter++ ;
            result.push_back(level) ;
            
        }
        
        return result ;
    }
};
