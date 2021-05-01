// Problem : https://leetcode.com/problems/maximum-width-of-binary-tree/

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
    unsigned int max(unsigned int x, unsigned int y){
        return x > y ? x : y ; 
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0 ;
        
        if(root -> left == NULL && root -> right == NULL)
            return 1 ;
        
        unsigned int n, max_width = 0, index, leftIndex, rightIndex ;
        pair<TreeNode*, unsigned int> curr;
        
        queue<pair<TreeNode*, unsigned int> > q ;    // pair(node, index)
        q.push(make_pair(root,0)) ;
        
       
        while(!q.empty()){
            n = q.size() ;
    
            rightIndex = q.back().second ;
            leftIndex = q.front().second ;
            max_width = max(max_width, rightIndex - leftIndex + 1) ;
                
            for(unsigned int i = 0 ; i < n ; i++){
                curr = q.front() ;
                q.pop() ;
                
                // Process current
                index = curr.second ;
                
                // push left child
                if(curr.first -> left != NULL){
                    q.push(make_pair(curr.first -> left, 2*index)) ;
                }
                
                // push right child
                if(curr.first -> right != NULL){
                    q.push(make_pair(curr.first -> right, 2*index + 1)) ;
                }
            }
            
        }
        
        return max_width ;
    }
};