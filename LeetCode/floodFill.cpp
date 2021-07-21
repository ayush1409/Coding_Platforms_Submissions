// Problem: https://leetcode.com/problems/flood-fill/

class Solution {
public:
    vector<int> xOff = {0,0,-1,1} ;
    vector<int> yOff = {-1,1,0,0} ;
    
    void colorImage(vector<vector<int>> &image, vector<vector<bool>> &visited, int i, int j, int color, int newColor){
        int m = image.size(), n = image[0].size() ;
        visited[i][j] = true ;
        image[i][j] = newColor ;
        int x, y ;
        
        for(int k = 0 ; k < 4 ; k++){
            x = i + xOff[k] ;
            y = j + yOff[k] ;
            
            if(x >= 0 && x <= m-1 && y >= 0 && y <= n-1){
                if(!visited[x][y] && image[x][y] == color)
                    colorImage(image, visited, x, y, color, newColor) ;
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size() ;
        int n = image[0].size() ;
        vector<vector<bool>> visited(m, vector<bool>(n, false)) ;   
        
        int color = image[sr][sc] ;
        colorImage(image, visited, sr, sc, color, newColor) ;
        
        return image ;
    }
};