// Problem: https://leetcode.com/problems/island-perimeter/

class Solution {
public:

    int perimeter = 0 ;
    vector<int> xOff = {0,0,-1,1} ;
    vector<int> yOff = {-1,1,0,0} ;
    
    void calculatePerimeter(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j){
        visited[i][j] = true ;
        int m = grid.size() , n = grid[0].size() ;
        int x, y ;
        for(int k = 0 ; k < 4 ; k++){
            x = i + xOff[k] ;
            y = j + yOff[k] ;
            
            if(x >=0 && x <= m-1 && y >= 0 && y <= n-1){
                if(grid[x][y])
                    if(!visited[x][y])
                        calculatePerimeter(grid, visited, x, y) ;
                    else
                        continue ;
                else 
                    perimeter++ ;
            }
            else
                perimeter++ ;
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;
        
        //if(m == 1 && n == 1)
        //    return 4 ;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false)) ;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++)
                if(!visited[i][j] && grid[i][j]){
                    calculatePerimeter(grid, visited, i, j) ;
                    break ;
                }
        }
        
        return perimeter ;
    }
};