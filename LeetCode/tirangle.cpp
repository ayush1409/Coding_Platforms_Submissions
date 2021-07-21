// Problem : https://leetcode.com/problems/triangle/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size() ;
        int x, y ;
        
        vector<vector<int>> dp(n, vector<int>(n, 0)) ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; ; j++){
                if(j > i)
                    break ;
                x = (i-1 >= 0 && j-1 >= 0) ? dp[i-1][j-1] : 0 ;
                y = (i-1 >= 0) ? dp[i-1][j] : 0 ;
                
                if(i == j){
                    dp[i][j] = triangle[i][j] + x ;
                } else if(j == 0){
                    dp[i][j] = triangle[i][j] + y ;
                }else
                    dp[i][j] = triangle[i][j] + min(x, y) ;
                                    
            }
        }
        
        int minPath = dp[n-1][0] ;
        
        for(int j = 1 ; j < n ; j++)
            if(minPath > dp[n-1][j])
                minPath = dp[n-1][j] ;
        
        return minPath ;
    }
};