// Problem : https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected[0].size() ;
        int time = 0 ;
        int scc = 0 ;
        
        vector<bool> inStack(n, false) ;
        vector<int> disc(n, -1) ;
        vector<int> low(n, -1) ;
        
        for(int i = 0 ; i < n ; i++){
            if(disc[i] == -1){
                inStack[i] = true ;
                dfs(isConnected, i, time, disc, low, inStack, scc) ;
            }
        }

        return scc ;
        
    }
    
    void dfs(vector<vector<int>> &isConnected, int i, int &time, vector<int> &disc, vector<int> &low, 
        vector<bool> &inStack, int &scc){
        
        // current node is visited for the first time
        inStack[i] = true ;
        disc[i] = time ;
        low[i] = time ;
        time++ ;
        
        int n = isConnected[0].size() ;
        
        for(int j = 0 ; j < n ; j++){
            if(isConnected[i][j] == 1){
                
                // if the next node is being visited for the first time (forward/tree edge)
                if(disc[j] == -1){
                    dfs(isConnected, j, time, disc, low, inStack, scc) ;
                    
                    // update the low value for node i using node j
                    low[i] = min(low[i], low[j]) ;
                }
                
                // if the next node is visited and in the stack (back edge)
                if(disc[j] != -1 && inStack[j]){
                    // update the low value and backtrack
                    low[i] = min(low[i], disc[j]) ;
                }
            }
        }
        
        // update the scc count
        if(disc[i] == low[i])
            scc++ ;
        
        inStack[i] = false ;
        
    }
    
};