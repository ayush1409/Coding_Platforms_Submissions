// Problem: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

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
    
    void maxDepthHelper(Node *node, int depth, int &maxDepth){
        if(node == NULL)
            return ;
        
        maxDepth = max(depth, maxDepth) ;
        
        for(auto child : node -> children)
            maxDepthHelper(child, depth + 1, maxDepth) ;
        
    }
    
    int maxDepth(Node* root) {
        if(root == NULL)
            return 0 ;
        
        int maxD = 0;
        
        maxDepthHelper(root, 1, maxD) ;
        
        return maxD ;
    }
};