// Problem : https://leetcode.com/problems/invert-binary-tree/

void swapChildNodes(TreeNode *node){
        if(!node || (!node->left && !node->right))
           return ;
        
        TreeNode *temp = node ->left ;
        node->left = node->right ;
        node->right = temp ;
    }
           
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == NULL)
            return root;
        
        queue<TreeNode*> q ;
        q.push(root) ;
        
        while(!q.empty()){
            
            TreeNode *curr = q.front() ;
            q.pop() ;
            
            swapChildNodes(curr) ;
            
            if(curr->left != NULL)
                q.push(curr->left) ;
        
            if(curr->right != NULL)
                q.push(curr->right) ;
        }
        
        return root ;
    }
