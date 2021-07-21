// Problem: https://leetcode.com/problems/redundant-connection/

class Solution {
public:
    struct Node{
        int parent = -1 ;
        int rank = 0 ;
    } ;
    
    int findP(int v, vector<Node> &parent){
        if(parent[v].parent == -1)
            return v ;
        parent[v].parent = findP(parent[v].parent, parent) ;
        return parent[v].parent ;
    }
    
    void merge(int u, int v, vector<Node> &parent){
        int uP = findP(u, parent) ;
        int vP = findP(v, parent) ;
        
        if(parent[uP].rank > parent[vP].rank){
            parent[vP].parent = uP ;
        }
        else if(parent[uP].rank < parent[vP].rank){
            parent[uP].parent = vP ;
        }
        else{
            parent[vP].parent = uP ;
            parent[uP].rank += 1 ;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() ;
        vector<Node> parent(n) ;
        
        int u,v,uP,vP ;
        vector<int> result(2) ;
        
        for(auto edge: edges){
            u = edge[0]-1 ;
            v = edge[1]-1 ;
            
            uP = findP(u, parent) ;
            vP = findP(v, parent) ;
            
            if(uP != vP)
                merge(uP, vP, parent) ;
            else{
                result[0] = u+1 ;
                result[1] = v+1 ;
            }
        }
        
        return result ;
        
    }
};