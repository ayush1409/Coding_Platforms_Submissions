void rightViewHelper(Node *root, int level, int &maxlevel, vector<int> &result){
        if(root == NULL)
            return ;
        
        if(level > maxlevel){
            maxlevel = level ;
            result.push_back(root->data) ;
        }
        
        rightViewHelper(root->right, level + 1, maxlevel, result) ;
        rightViewHelper(root->left, level + 1, maxlevel, result) ;
}

vector<int> rightView(Node *root)
{
       // Your Code here
        vector<int> result ;
        if(root == NULL)
            return result ;
        int maxlevel = -1 ;
        rightViewHelper(root, 0, maxlevel, result) ;
       
        return result ;
}