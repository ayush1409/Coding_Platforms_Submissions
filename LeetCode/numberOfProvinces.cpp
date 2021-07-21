// Problem: https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    struct Node{
        int parent = -1;
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
        else if(parent[vP].rank < parent[vP].rank){
            parent[uP].parent = vP ;
        }
        else{
            parent[vP].parent = uP ;
            parent[uP].rank += 1 ;
        }
    }
    
    void computeComponents(vector<vector<int>> &isConnected, vector<Node> &parent){
        int n = isConnected.size() ;
        int uP, vP ;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i != j && (isConnected[i][j] == 1 || isConnected[j][i] == 1)){
                    uP = findP(i, parent) ;
                    vP = findP(j, parent) ;
                    
                    if(uP != vP)
                        merge(uP, vP, parent) ;
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<Node> parent(isConnected.size()) ;
        computeComponents(isConnected, parent) ;
        
        int compCount = 0;
        
        for(auto node : parent){
            if(node.parent == -1)
                compCount++ ;
        }
        
        return compCount ;
    }
};