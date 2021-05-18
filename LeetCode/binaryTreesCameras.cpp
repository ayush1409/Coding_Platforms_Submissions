// Problem : https://leetcode.com/problems/binary-tree-cameras/

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
    struct camera {int covered = 0, please_cover = 1, has_camera = 2 ;} ;
    
    camera c;
    int cameraCount = 0 ;
    
    int minCameraCover(TreeNode* root) {
        return postorder(root) == c.please_cover ? ++cameraCount : cameraCount ;
    }
    
    int postorder(TreeNode *root){
        if(root == NULL)
            return c.covered ;
        
        int leftResult = postorder(root -> left) ;
        int rightResult = postorder(root -> right) ;
        
        if(leftResult == c.please_cover || rightResult == c.please_cover){
            cameraCount++ ;
            return c.has_camera ;
        }
        else if(leftResult == c.has_camera || rightResult == c.has_camera)
            return c.covered ;
        else
            return c.please_cover ;
    }
};