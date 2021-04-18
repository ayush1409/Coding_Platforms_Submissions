class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> result ;
       if(root == NULL)
        return result ;
       
       queue<Node *> q ;
       unsigned int n ;
       Node *curr = NULL;
       q.push(root) ;
       
        while(!q.empty()){
            n = q.size() ;
            for(unsigned int i = 0 ; i < n ; i++){
                curr = q.front(); 
                q.pop() ;
               
                if(i == n-1)
                    result.push_back(curr->data) ;
                
                if(curr->left != NULL)
                    q.push(curr->left) ;
                if(curr->right != NULL)
                    q.push(curr->right) ;
                
            }
        }
        
        return result ;
    }
};
