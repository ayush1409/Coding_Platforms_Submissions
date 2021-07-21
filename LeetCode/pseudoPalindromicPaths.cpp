// Problem: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

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
    void pseudoPalindromicPathsHelper(TreeNode *root, vector<int> &freq, int &result){
        if(root == NULL)
            return ;
        
        int oddfreqCount = 0 ;
        
        if(root -> left == NULL && root -> right == NULL){
            freq[root -> val]++ ;
            for(auto x: freq){
                if(x % 2)
                    oddfreqCount++ ;
                if(oddfreqCount > 1){
                    freq[root -> val]-- ;
                    return ;
                }
            }
            freq[root -> val]-- ;
            result++ ;
            return ;
        }
        
        freq[root -> val]++ ;
        pseudoPalindromicPathsHelper(root -> left, freq, result) ;
        pseudoPalindromicPathsHelper(root -> right, freq, result) ;
        freq[root -> val]-- ;
    }
    
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10, 0) ;
        int result = 0 ;
        pseudoPalindromicPathsHelper(root, freq, result) ;
        
        return result ;
    }
};