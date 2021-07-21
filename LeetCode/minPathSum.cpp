// Problem: https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;
        int x,y ;
        vector<vector<int>> paths(m , vector<int>(n, 0)) ;
        
        //paths[m-1][n-1] = grid[m-1][n-1] ;
        
        for(int i = m-1 ; i >= 0 ; i--){
            for(int j = n-1 ; j >= 0 ; j--){
                if(i == m-1 && j == n-1){
                    paths[i][j] = grid[i][j] ;
                    continue ;
                }
                
                x = (i+1 >= 0 && i+1 <= m-1) ? paths[i+1][j] : INT_MAX ;
                y = (j+1 >= 0 && j+1 <= n-1) ? paths[i][j+1] : INT_MAX ;
                paths[i][j] = grid[i][j] + min(x,y) ;
            }
        }
        
        return paths[0][0] ;
    }

    /* Using Backtracking : Time Limit Exceeded
    vector<int> xOff = {0,0,-1,1} ;
    vector<int> yOff = {-1,1,0,0} ;
    
    void minPathHelper(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j, int path, int &minPath){
        int m = grid.size() ;
        int n = grid[0].size() ;
        
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j])
            return ;
        
        if(i == m-1 && j == n-1){
            path += grid[i][j] ;
            minPath = min(path, minPath) ;
            return ;
        }
        
        visited[i][j] = true ;
        
        for(int k = 0 ; k < 4 ; k++){
            int x = i + xOff[k] ;
            int y = j + yOff[k] ;
            
            minPathHelper(grid, visited, x, y, path + grid[i][j], minPath) ;
        }
        visited[i][j] = false ;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int minPath = INT_MAX ;
        int m = grid.size() ;
        int n = grid[0].size() ;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false)) ;
        
        minPathHelper(grid, visited, 0, 0, 0, minPath) ;
        
        return minPath ;
    }
    */
    
    
};