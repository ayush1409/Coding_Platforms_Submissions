// Problem: https://leetcode.com/problems/maximal-square/

class Solution {
public:
    int min(int a, int b, int c){
        return a < b ? (a < c ? a: c) : (b < c ? b : c) ;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        
        /*
        // Approach 1: dp[i][j] stores the max square we can form by making it as bottom right corner
        int m = matrix.size() ;
        int n = matrix[0].size() ;
        int largest = INT_MIN ;
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0)) ;
    
        for(int i = 1 ; i <= m ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(matrix[i-1][j-1] == '1')
                    dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) ;
                if(largest < dp[i][j])
                    largest = dp[i][j] ;
            }    
        }
    
        return largest*largest ;
        */
        
        // Approach 2: dp[i][j] stores the max square we can form by making it as top left corner
        int m = matrix.size() ;
        int n = matrix[0].size() ;
        int largest = 0 ;
        int x, y, z ;
        
        vector<vector<int>> dp(m, vector<int>(n, 0)) ;
        
        for(int i = m-1 ; i >= 0 ; i--){
            for(int j = n-1 ; j >= 0 ; j--){
                if(matrix[i][j] == '1'){
                    x = (j+1 < n) ? dp[i][j+1] : 0 ;
                    y = (i+1 < m && j+1 < n) ? dp[i+1][j+1] : 0 ;
                    z = (i+1 < m) ? dp[i+1][j] : 0 ;
                    
                    dp[i][j] = 1 + min(x, y, z) ;
                    
                    if(largest < dp[i][j])
                        largest = dp[i][j] ;
                }
            }
        }
        
        return largest * largest ;
        
    }
};