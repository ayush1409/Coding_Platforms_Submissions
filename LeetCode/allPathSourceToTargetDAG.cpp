// Problem: https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    void dfs(int i, vector<vector<int>> &graph, vector<vector<int>> &result, vector<int> &parent){
        parent.push_back(i) ;
        
        if(i == graph.size()-1){
            result.push_back(parent) ;
            parent.pop_back() ;
            return ;
        }
        
        for(auto j : graph[i]){
            dfs(j, graph, result, parent) ;
        }
        
        parent.pop_back() ;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result ;
        vector<int> parent ;
        
        dfs(0, graph, result, parent) ;
        
        return result ;
    }
};