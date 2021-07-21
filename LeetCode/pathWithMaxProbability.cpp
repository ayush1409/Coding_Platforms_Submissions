// Problem: https://leetcode.com/problems/path-with-maximum-probability/

class Solution {
public:
    
    // Using Dijkshtra's longest path: Accepted
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end){
        vector<double> prob(n, 0) ;
        vector<vector<pair<int, double>>> graph(n) ;
        int u, v;
        double w ;
        
        for(int i = 0 ; i < edges.size() ; i++){
            graph[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i])) ;
            graph[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i])) ;
        }
        
        priority_queue<pair<double, int>> pq ;
        prob[start] = 1 ;
        pq.push({prob[start], start}) ;
        
        while(!pq.empty()){
            u = pq.top().second ;
            pq.pop() ;
    
            for(auto j : graph[u]){
                v = j.first ;
                w = j.second ;
                
                if(prob[u] * w > prob[v]){
                    prob[v] = prob[u] * w ;
                    pq.push({prob[v], v}) ;
                }
            }
        }
                
        return prob[end] ;
    }
    
    /*
    // Backtracking : TLE
    void maxProb(vector<vector<pair<int, double>>> &graph, int start, int end, double prob, double &result, vector<bool> &visited){
        
        if(start == end){
            if(prob > result)
                result = prob ;
            return ;
        }
        
        visited[start] = true ;
        for(auto j : graph[start]){
            if(!visited[j.first])
                maxProb(graph, j.first, end, prob*(j.second), result, visited) ;
        }
        visited[start] = false ;
    }
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> graph(n) ;
        vector<bool> visited(n, false);
        
        for(int i = 0 ; i < edges.size() ; i++){
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]}) ;
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]}) ;
        }
        
        for(auto g: graph){
            for(auto x : g)
                cout<<"("<<x.first<<", "<<x.second<<") " ;
            cout<<endl ;
        }
        double result = 0 ;
        
        maxProb(graph, start, end, 1, result, visited) ;
        
        return result ;
    }
    */
};