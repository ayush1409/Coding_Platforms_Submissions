/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
vector<int> reverseLevelOrder(Node *root)
{
    vector<int> result ;
    if(root == NULL) 
        return result ;
        
    Node *curr = NULL ;
    queue<Node *> q ;
    q.push(root) ;
    
    while(!q.empty()){
        curr = q.front() ;
        q.pop() ;
        result.push_back(curr -> data) ;
        
        if(curr -> right)
            q.push(curr -> right) ;
        if(curr -> left)
            q.push(curr -> left) ;
    }
    
    reverse(result.begin(), result.end()) ;
    return result ;
}