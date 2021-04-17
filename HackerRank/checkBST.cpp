/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  
The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
#include <climits>
    bool checkBSTHelper(Node* root, int min, int max){
        if(root == NULL)
            return true ;
        
        if(root->data > max || root->data < min)
            return false ;
        
        return checkBSTHelper(root -> left, min, root->data - 1) &&
            checkBSTHelper(root->right, root->data + 1, max) ;
    }
	bool checkBST(Node* root) {
        return checkBSTHelper(root, INT_MIN+1, INT_MAX-1) ;
	}