class Solution
{
    public:
    
    void invert(Node *root){
        if(root == NULL)
            return  ;
        
        Node *temp = root->left ;
        root->left = root->right ;
        root->right = temp ;
        
        invert(root -> left) ;
        invert(root -> right) ;
        
    }
    
    bool equalTrees(Node *a, Node *b){
        if(a == NULL && b == NULL)
            return true ;
        
        if(a == NULL && b != NULL)
            return false ;
            
        if(a != NULL && b == NULL)
            return false ;
        
        if(a->data != b->data)
            return false ;
        
        return a->data == b->data &&
        equalTrees(a->left, b->left) && equalTrees(a->right, b->right) ;
    }
    
    int areMirror(Node* a, Node* b) {
   
    // invert second tree
    invert(b) ;
    
    // compute equal
    if(equalTrees(a,b))
        return 1 ;
    else return 0 ;
    
    }

};