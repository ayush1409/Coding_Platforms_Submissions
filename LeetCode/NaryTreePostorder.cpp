//Problem : https://leetcode.com/problems/n-ary-tree-postorder-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    void postorderHelper(Node *root, vector<int> &result){
        if(root != NULL){
            for(auto child : root -> children)
                postorderHelper(child, result) ;
        
            result.push_back(root -> val) ;
        }    
    }
    
    vector<int> postorder(Node* root) {
        vector<int> result ;
        postorderHelper(root, result) ;
        return result ;
    }
};