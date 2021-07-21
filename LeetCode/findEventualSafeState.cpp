// Problem: https://leetcode.com/problems/find-eventual-safe-states/

class Solution {
public:
    
    // Using DFS and backtracking
    bool cycleExist(vector<vector<int>> &graph, int i, unordered_set<int> &visited, unordered_set<int> &visiting){
        if(visiting.find(i) != visiting.end())
            return true ;
        if(visited.find(i) != visited.end())
            return false ;
        
        visiting.insert(i) ;
        
        for(auto nbr: graph[i]){
            if(cycleExist(graph, nbr, visited, visiting))
                return true ;
        }
        
        visiting.erase(visiting.find(i)) ;
        visited.insert(i) ;
        
        return false ;
    }
    /*
    // BFS to detect cycle: works for only directed graph
    bool detectCycle(vector<vector<int>> &graph, int i){
        int n = graph.size() ;
        vector<bool> visited(n) ;
        queue<int> q ;
        //visited[i] = true ;
        q.push(i) ;
        int u, v ;
        
        while(!q.empty()){
            u = q.front() ;
            q.pop() ;
            visited[u] = true ;
            
            for(auto v : graph[u]){
                if(!visited[v])
                    q.push(v) ;
                else 
                    return true ;
            }
        }
        
        return false ;
    }
    */
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size() ;
        
        vector<int> result ;
        //vector<bool> visited(n, false) ;
        unordered_set<int> visited ;
        unordered_set<int> visiting ;
        
        for(int i = 0 ; i < graph.size() ; i++){
            if(!cycleExist(graph, i, visited, visiting))
                result.push_back(i) ;
        }
        
        sort(result.begin(), result.end()) ;
        
        return result ;
    }
};