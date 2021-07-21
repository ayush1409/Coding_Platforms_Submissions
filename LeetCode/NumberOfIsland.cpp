// Problem : https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    
    int numIslands(vector<vector<char> >& grid) {
        
        if(grid.size() == 0)
            return 0 ;
        size_t m = grid.size() ;
        size_t n = grid[0].size() ;
        
        vector<vector<bool> > visited(m, vector<bool>(n, false)); 
        int NumOfIsland = 0 ;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(visited[i][j] == false && grid[i][j] == '1'){
                    BFSTraverse(i, j, grid, visited) ;
                    NumOfIsland++ ;
                }
                else if(visited[i][j] == false)
                    BFSTraverse(i, j, grid, visited) ; 
            }
        }
        
        return NumOfIsland ;
    }
    
    void BFSTraverse(int i, int j, vector<vector<char> > &grid, vector<vector<bool> > &visited){
        
        queue<pair<int, int> > q ;
        q.push(make_pair(i,j)) ;
        
        pair<int,int> current ;
        
        vector<pair<int,int> > NeighboringNodes ;
        
        while(!q.empty()){
            current = q.front() ;
            q.pop() ;
            
            
            i = current.first ;
            j = current.second ;
            if(visited[i][j])
                continue ;
            
            visited[i][j] = true ;
            
            if(grid[i][j] == '0')
                continue ;
            
            getNeighbors(i, j, visited, NeighboringNodes) ;
            
            if(NeighboringNodes.size() != 0){
                for(auto neighbor : NeighboringNodes)
                    q.push(neighbor) ;
            }
            
            NeighboringNodes.clear() ;
        }
    }
    
    void getNeighbors(int i, int j, vector<vector<bool> > &visited, vector<pair<int, int> > &NeighboringNodes){
        if(i > 0 && visited[i-1][j] == false)
            NeighboringNodes.push_back(make_pair(i-1,j)) ;
        
        if(i < visited.size()-1 && visited[i+1][j] == false)
            NeighboringNodes.push_back(make_pair(i+1,j)) ;
        
        if(j > 0 && visited[i][j-1] == false)
            NeighboringNodes.push_back(make_pair(i,j-1)) ;
        
        if(j < visited[i].size()-1 && visited[i][j+1] == false)
            NeighboringNodes.push_back(make_pair(i,j+1)) ;
    }
};

/*
    // DFS Solution
    class Solution {
    
    public:
    
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited){
        int m = grid.size() ;
        int n = grid[0].size() ;
        
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == '0')
            return ;
        
        visited[i][j] = true ;
        
        dfs(i, j-1, grid, visited) ;
        dfs(i-1, j, grid, visited) ;
        dfs(i, j+1, grid, visited) ;
        dfs(i+1, j, grid, visited) ;
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;
        vector<vector<bool>> visited(m, vector<bool>(n, false)) ;
        int islandCount = 0 ;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(i, j, grid, visited) ;
                    islandCount++ ;
                }
            }
        }
        
        return islandCount ;
    }
};
*/
