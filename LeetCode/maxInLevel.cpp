// Problem : https://leetcode.com/problems/find-largest-value-in-each-tree-row/

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
    int findMax(vector<int> &vec){
        int max = INT_MIN ;
        
        for(auto x : vec){
            if(x > max)
                max = x ;
        }
        
        return max ;
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> result ;
        
        if(root == NULL)
            return result ;
        
        vector<int> level ;
        
        TreeNode *curr ;
        unsigned int n ;
        int max = INT_MIN ;
        queue<TreeNode*> q ;
        q.push(root) ;
        
        while(!q.empty()){
            
            level.clear() ;
            n = q.size() ;
            
            for(int i=0 ; i<n ; i++){
                curr = q.front() ;
                q.pop() ;
                
                level.push_back(curr->val) ;
                
                if(curr->left != NULL)
                    q.push(curr->left) ;
                
                if(curr->right != NULL)
                    q.push(curr->right) ;
                
            }
            
            if(level.size() != 0){
                max = findMax(level) ;
                result.push_back(max) ;
            }
        }
        
        return result ;
    }
};
