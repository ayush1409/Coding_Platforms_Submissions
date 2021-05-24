// Problem : https://leetcode.com/problems/n-ary-tree-preorder-traversal/

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
    void preorderHelper(Node *root, vector<int> &result){
        if(root != NULL){
            result.push_back(root -> val) ;
            
            for(auto child : root -> children)
                preorderHelper(child, result) ;
        }    
    }
    
    vector<int> preorder(Node* root) {
        vector<int> result ;
        preorderHelper(root, result) ;
        return result ;
    }
};