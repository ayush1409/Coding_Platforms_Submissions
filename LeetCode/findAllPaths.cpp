// Problem : https://leetcode.com/problems/find-if-path-exists-in-graph/

class Solution {
public:
    
    void dfs(int i, int destination, vector<vector<int>> &graph, vector<bool> &visited){
        visited[i] = true ;
        for(int j = 0 ; j < graph[i].size() ; j++){
            if(graph[i][j] && !visited[j]){
                if(j == destination){
                    // return as soon as you get the first path
                    visited[destination] = true ;
                    return ;
                }
                dfs(j, destination, graph, visited) ;
            }
        }   
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n <= 1)
            return true ;
        
        vector<vector<int>> graph(n) ;
        vector<bool> visited(n, false) ;
        
        
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            //cout<<edge[0]<<", "<<edge[1]<<endl ;
        }
        
        //dfs(source, destination, graph, visited) ;
        
        // bfs
        queue<int> q ;
        int curr, next ;
        visited[source] = true ;
        q.push(source) ;
        
        while(!q.empty()){
            curr = q.front() ;
            for(int j = 0 ; j < graph[curr].size() ; j++){
                next = graph[curr][j] ;
                if(!visited[next]){
                    q.push(next) ;
                    visited[next] = true ;
                }
            }
            q.pop() ;
        }
        return visited[destination] ;
    }
};