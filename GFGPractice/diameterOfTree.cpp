/*
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
*/ 

class Solution
{
    public:
    int max(int x, int y){
        return x > y ? x : y ;
    }
    
    int diameterHelper(Node *root, int &maxDia){
        if(root == NULL)
            return 0 ;
        int leftHeight = diameterHelper(root -> left, maxDia) ;
        int rightHeight = diameterHelper(root -> right, maxDia) ;
        
        maxDia = max(maxDia, leftHeight + rightHeight + 1) ;
        
        return 1 + max(leftHeight, rightHeight) ;
    }
    
    //Function to return the diameter of a Binary Tree.
    int diameter(Node* root){
        if(root == NULL)
            return 0 ;
            
        int dia = INT_MIN;
        diameterHelper(root, dia) ;
        
        return dia ;
    }

};