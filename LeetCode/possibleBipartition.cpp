// Problem: https://leetcode.com/problems/possible-bipartition/

class Solution {
public:
    enum color{WHITE, RED, BLUE} ;
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1) ;
        vector<int> colors(n+1, WHITE) ;
        queue<int> q ;
        int u ;
        
        for(auto dislike: dislikes){
            graph[dislike[0]].push_back(dislike[1]) ;
            graph[dislike[1]].push_back(dislike[0]) ;
        }
            
        for(int i = 1 ; i <= n ; i++){
            
            if(colors[i] == WHITE){
                colors[i] = RED ;
                q.push(i) ;
                
                while(!q.empty()){
                    u = q.front() ;
                    q.pop() ;
                    
                    for(auto nbr : graph[u]){
                        
                        if(colors[nbr] == colors[u])
                            return false ;
                        
                        if(colors[nbr] != WHITE)
                            continue ;
                        
                        if(colors[u] == RED)
                            colors[nbr] = BLUE ;
                        else
                            colors[nbr] = RED ;
                        
                        q.push(nbr) ;
                    }
                }
            }
        }
        
        return true ;
        
    }
};