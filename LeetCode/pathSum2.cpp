// Problem : https://leetcode.com/problems/path-sum-ii/

// Solution 2 (Using DFS - More optimized)
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
    void pathSumHelper(TreeNode *root, vector<vector<int>> &result, int sum, vector<int> &sumVec, int targetSum){
        if(root == NULL)
            return ;
        
        if(root -> left == NULL && root -> right == NULL){
            sum += root -> val ;
            sumVec.push_back(root -> val) ;
            if(sum == targetSum)
                result.push_back(sumVec) ;
            sumVec.pop_back() ;
            sum -= root -> val ;
            return ;
        }
         
        sumVec.push_back(root -> val) ;
        sum += root -> val ;
        pathSumHelper(root -> left, result, sum, sumVec, targetSum) ;
        pathSumHelper(root -> right, result, sum, sumVec, targetSum) ;
        sumVec.pop_back() ;
        sum -= root -> val ;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result ;
        vector<int> sumVec ;
        
        pathSumHelper(root, result, 0, sumVec, targetSum) ;
        
        return result ;
    }
};

// Solution 1 Recursive approach (Accepted but High Runtime and Large memeory usage)
/*
class Solution {
public:
    void pathSumHelper(TreeNode *root, vector<vector<int>> &result, int sum, vector<int> &sumVec, 
                              int targetSum){
        if(root == NULL)
            return ;
        vector<int> currentSum(sumVec) ;
        
        /*
        if(sumVec.size() != 0){
            for(auto x : sumVec)
                currentSum.push_back(x) ;
        }
        */
/*        
        currentSum.push_back(root -> val) ;
        sum += root -> val ;
        
        if(sum == targetSum && root -> left == NULL && root -> right == NULL){
            result.push_back(currentSum) ;
            return ;
        }
        
        pathSumHelper(root -> left, result, sum, currentSum, targetSum) ;
        pathSumHelper(root -> right, result, sum, currentSum, targetSum) ;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result ;
        vector<int> sumVec ;
        
        pathSumHelper(root, result, 0, sumVec, targetSum) ;
        
        return result ;
    }
};
*/