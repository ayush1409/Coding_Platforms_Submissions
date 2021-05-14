// Problem : https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result ;
        if(root == NULL)
            return result ;
        
        TreeNode *curr = NULL ;
        unsigned int n ;
        double sum,count ;
        
        queue<TreeNode*> q ;
        q.push(root) ;
        
        while(!q.empty()){
            n = q.size() ;
            sum = 0 ;
            count = 0 ;
            for(int i = 0 ; i < n ; i++){
                curr = q.front() ;
                q.pop() ;
                
                sum += curr -> val ;
                count++ ;
                
                if(curr -> left != NULL)
                    q.push(curr -> left) ;
                
                if(curr -> right != NULL)
                    q.push(curr -> right) ;
            }
            
            result.push_back(sum/count) ;
        }
        
        return result ;
    }
};
