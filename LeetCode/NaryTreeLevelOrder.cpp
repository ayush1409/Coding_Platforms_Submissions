// Problem : https://leetcode.com/problems/n-ary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<int> level ;
        vector<vector<int>> result ;
        if(root == NULL)
            return result ;
        
        Node *curr = NULL ;
        queue<Node*> q ;
        q.push(root) ;
        
        while(!q.empty()){
            int n = q.size() ;
            level.clear() ;
            
            for(int i = 0 ; i < n ; i++){
                curr = q.front() ;
                q.pop() ;
                level.push_back(curr -> val) ;
                
                for(auto child : curr -> children){
                    if(child != NULL)
                        q.push(child) ;
                }
            }
            result.push_back(level) ;
        }
        
        return result ;
    }
};