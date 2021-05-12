/*
    Problem : Given a Binary Search Tree (BST) and a range [min, max], remove all keys which are outside the given range. The modified tree should also be BST.

    Example 1:

    Input:
    Range = [-10, 13]
    Lightbox

    Output:
    -8 6 7 13
    Explanation:
    Nodes with values -13, 14 and 15 are 
    outside the given range and hence are 
    removed from the BST.

    BinaryTreeModified2

    This is the resultant BST and it's 
    inorder traversal is -8 6 7 13.
    Example 2:

    Input:
    Range = [2, 6]
            14
        /    \
        4      16
        / \     /
    2   8   15
    / \  / \
    -8  3 7  10

    Output:
    2 3 4
    Explanation:
    After removing nodes outside the range, 
    the resultant BST looks like:
                4
                /
                2
                \
                    3 
    The inorder traversal of this tree is: 2 3 4
    Your task:
    You don't have to read input or print anything. Your task is to complete the function removekeys() which takes the root node of the BST and the range as input and returns the root of the modified BST after removing the nodes outside the given range.
    
    Expected Time Complexity: O(number of nodes)
    Expected Auxiliary Space: O(h)
    
    Constraints:
    1<=Number of Nodes<=105
    1<=K<=105
*/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

 // } Driver Code Ends
// User function Template for C++

/*struct Node
{
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
    public:

/*    
    void swap(Node *node1, Node *node2){
        int temp = node1 -> data ;
        node1 -> data = node2 -> data ;
        node2 -> data = temp ;
    }
    
    Node* findPredecessor(Node *node){
        if(node -> left == NULL)
            return node ;
        node = node -> left ;
        
        while(node -> right != NULL)
            node = node -> right ;
            
        return node ;
    }
    
    Node* findSuccessor(Node *node){
        if(node -> right == NULL)
            return node ;
        
        node = node -> right ;
        
        while(node -> left != NULL)
            node = node -> left ;
            
        return node ;
    }
    
    Node* deleteNode(Node *node, int data){
        if(node == NULL)
            return NULL;
        
        if(node -> data > data)
            node -> left = deleteNode(node -> left, data) ;
        else if(node -> data < data)
            node -> right = deleteNode(node -> right, data) ;
            
        if(node -> left == NULL && node -> right == NULL){
            delete(node) ;
            return NULL;
        }
        
        Node *next = NULL;
        
        if(node -> left == NULL){
            Node *temp = node -> right ;
            node -> data = temp -> data ;
            node -> right = temp -> right ;
            delete(temp) ;
            return node ;
        }
        
        if(node -> right == NULL){
            Node *temp = node -> left ;
            node -> data = node -> left -> data ;
            node -> left = temp -> left ;
            delete(temp) ;
            return node ;
        }
        else{
           next = findSuccessor(node) ;
            swap(node , next) ;
            node -> right = deleteNode(node -> right, next -> data) ; 
        }
        
        return node ;
        /*
        if(node -> right == NULL)
            next = findPredecessor(node) ;
        else
            next = findSuccessor(node) ;
        
        */

        //return node ;
      

/*    }*/
    Node* removekeys(Node* root, int l, int r) {
/*
        // Sample test cases passed only
        if(root == NULL)
            return root ;
        
        while(root != NULL && (root -> data < l || root -> data > r))
            root = deleteNode(root, root -> data) ;
            
        if(root == NULL)
            return root ;
        
        if(root -> data > l)
            root -> left = removekeys(root -> left, l, r) ;
        
        if(root -> data < r )
            root -> right = removekeys(root -> right, l, r) ;
        
        return root ;
    
*/

/*
    The idea is to fix the tree in a Post-order fashion. 
    When we visit a node, we make sure that its left and right sub-trees are already fixed. 
    In case 1.a), we simply remove the root and return the right sub-tree as a new root. 
    In case 1.b), we remove the root and return the left sub-tree as a new root.
*/
        if (root == NULL)
            return NULL;

        root -> left =  removekeys(root -> left, l, r);
        root -> right =  removekeys(root -> right, l, r);
        
        if (root -> data < l)
        {
            Node *rChild = root -> right;
            delete root;
            return rChild;
        }
        
        if (root -> data > r)
        {
            Node *lChild = root -> left;
            delete root;
            return lChild;
        }
        
        return root;
    }
};

// { Driver Code Starts.
/* Driver program to test size function*/
int main() {

    int t;
    cin >> t;
    getchar();
    while (t--) {
        int l, r;
        cin >> l >> r;

        string ln;
        getline(cin, ln);

        string inp, ch;
        getline(cin, inp);
        struct Node* root = buildTree(inp);
        Solution obj;
        Node* head = obj.removekeys(root, l, r);

        inorderTraversal(head);
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends