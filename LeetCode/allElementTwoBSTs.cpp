// Problem : https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

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
    
    void merge(vector<int> &result, vector<int> &a, vector<int> &b){
        int m = a.size() ;
        int n = b.size() ;
        int i = 0, j = 0 , k = 0 ;
        while(i < m && j < n){
            if(a[i] < b[j]){
                result[k++] = a[i++] ;
            }
            else
                result[k++] = b[j++] ;
        }
        
        while(i < m){
            result[k++] = a[i++] ;
        }
        
        while(j < n){
            result[k++] = b[j++];
        }
    }
    
    void inorder(TreeNode *root, vector<int> &arr){
        if(root != NULL){
            inorder(root -> left, arr) ;
            arr.push_back(root -> val) ;
            inorder(root -> right, arr) ;
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> inorderTree1 ;
        vector<int> inorderTree2 ;
        
        inorder(root1, inorderTree1) ;
        inorder(root2, inorderTree2) ;
        
        if(root1 == NULL && root2 == NULL)
            return inorderTree1 ;
        if(root1 == NULL && root2 != NULL)
            return inorderTree2 ;
        if(root1 != NULL && root2 == NULL)
            return inorderTree1 ;
        
        vector<int> result(inorderTree1.size() + inorderTree2.size()) ;
        
        merge(result, inorderTree1, inorderTree2) ;
        
        return result ;
    }
};