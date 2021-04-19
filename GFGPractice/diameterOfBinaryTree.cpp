struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 



class Solution
{
    public:
    
    int max(int a, int b){
        return a>b ? a : b ;
    }
    
    int diameterHelper(Node *root, int &maxDiameter){
        if(root == NULL)
            return -1 ;
            
        if(root->left == NULL && root->right == NULL)
            return 0 ;
        
        int leftHeight = diameterHelper(root->left, maxDiameter) ;
        int rightHeight = diameterHelper(root->right, maxDiameter) ;
        
        if(maxDiameter < 2 + leftHeight + rightHeight)
            maxDiameter = 2 + leftHeight + rightHeight ;
            
        return 1 + max(leftHeight, rightHeight) ;
    }
    
    //Function to return the diameter of a Binary Tree.
    int diameter(Node* root)
    {
        if(root == NULL)
            return 0 ;
    
        int maxDiameter = 0 ;
        
        diameterHelper(root, maxDiameter) ;
        
        return maxDiameter;
    }

};