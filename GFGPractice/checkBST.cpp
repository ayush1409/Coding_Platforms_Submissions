/*
    Problem :   Given a binary tree. Check whether it is a BST or not.
                Note: We are considering that BSTs can not contain duplicate Nodes.
*/

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// return true if the given tree is a BST, else return false
class Solution
{
    public:
    
    bool isBSTHelper(Node *root, int min, int max){
        if(root != NULL){
            if(root -> data > max || root -> data < min)
                return false ;
            
            return isBSTHelper(root -> left , min, root -> data - 1) &&
                isBSTHelper(root -> right, root -> data + 1, max) ;
        }
        return true ;
    }
    bool isBST(Node* root) 
    {
        return isBSTHelper(root, INT_MIN, INT_MAX) ;
    }
};
