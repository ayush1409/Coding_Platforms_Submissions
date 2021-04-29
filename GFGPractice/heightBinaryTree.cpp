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
class Solution{
    public:
    
    int max(int x, int y){
        return x > y ? x : y ;
    }
    
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        
        if(node == NULL)
            return 0;
        
        int heightLeft = height(node -> left) ;
        int heightRight = height(node -> right) ;
        
        return 1 + max(heightLeft, heightRight) ;
    }
};