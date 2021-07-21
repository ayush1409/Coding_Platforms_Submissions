// Problem: https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    
    bool isBipartiteHelper(vector<vector<int>> &graph, int src, vector<bool> visited, vector<int> &color, int parent){
        visited[src] = true ;
        
        if(parent == -1)
            color[src] = 1 ;
        else
            color[src] = 1 - color[parent] ;
        
        for(auto nbr : graph[src]){
            if(!visited[nbr])
                return isBipartiteHelper(graph, nbr, visited, color, src) ;
            else if(nbr != parent && color[nbr] == color[src])
                return false ;
        }
        
        return true ;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size() ;
                
        vector<bool> visited(n, false) ;
        vector<int> color(n, -1) ;
        
        for(int i = 0 ; i < n ; i++)
            if(!visited[i] && !isBipartiteHelper(graph, i, visited, color, -1))
                return false ;
        
        return true ;
        
    }
};