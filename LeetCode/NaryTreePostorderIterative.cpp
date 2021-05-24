// Problem : https://leetcode.com/problems/n-ary-tree-postorder-traversal/

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
    
    vector<int> postorder(Node* root) {
        vector<int> result ;
        if(root == NULL)
            return result ;
        
        Node *curr = NULL ;
        stack<Node*> s ;
        s.push(root) ;
        
        while(!s.empty()){
            curr = s.top() ;
            s.pop() ;
            result.push_back(curr -> val) ;
            
            for(auto child : curr -> children){
                if(child != NULL)
                    s.push(child) ;
            }
        }
        
        reverse(result.begin(), result.end()) ;
        return result ;
    }
};