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

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> result ;
    if(root == NULL)
        return result ;
        
    unsigned int n ;
    Node *curr = NULL ;
    queue<Node *> q ;
    q.push(root) ;
    while(!q.empty()){
        n = q.size() ;
        for(int i = 0 ; i < n ; i++){
            curr = q.front() ;
            q.pop() ;
            
            if(i == 0)
                result.push_back(curr -> data) ;
            
            if(curr -> left != NULL)
                q.push(curr -> left) ;
                
            if(curr -> right != NULL)
                q.push(curr -> right) ;
        }
    }
    
    return result;
}