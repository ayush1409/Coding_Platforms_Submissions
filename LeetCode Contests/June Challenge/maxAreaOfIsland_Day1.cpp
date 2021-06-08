class Solution {
public:
    int maxArea = 0 ;
    
    vector<pair<int, int>> getNeighbors(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited){
        int m = grid.size() ;
        int n = grid[0].size() ;
        vector<pair<int, int>> result ;
        
        if(j > 0 && !visited[i][j-1] && grid[i][j-1])
            result.push_back({i, j-1}) ;
        if(j < n-1 && !visited[i][j+1] && grid[i][j+1])
            result.push_back({i, j+1}) ;
        if(i > 0 && !visited[i-1][j] && grid[i-1][j])
            result.push_back({i-1, j}) ;
        if(i < m-1 && !visited[i+1][j] && grid[i+1][j])
            result.push_back({i+1, j}) ;
        
        return result ;
        
    }
    
    void bfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited){
        int area = 0 ;
        queue<pair<int, int>> q ;
        q.push({i,j}) ;
        vector<pair<int, int>> neighbors ;
        
        while(!q.empty()){
            pair<int, int> curr = q.front() ;
            q.pop() ;
            visited[curr.first][curr.second] = true ;
            area++ ;
            
            neighbors = getNeighbors(curr.first, curr.second, grid, visited) ;
            
            for(auto x : neighbors){
                visited[x.first][x.second] = true ;
                q.push(x) ;
            }
        }
        
        maxArea = max(maxArea, area) ;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;
        vector<vector<bool>> visited(m, vector<bool>(n, false)) ;
    
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++)
                if(!visited[i][j] && grid[i][j])
                    bfs(i, j, grid, visited) ;
        }
        
        return maxArea ;
    }
};