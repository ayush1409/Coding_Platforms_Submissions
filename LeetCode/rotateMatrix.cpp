// Problem: https://leetcode.com/problems/rotate-image/
// Time: O(N^2), Space: O(1)

class Solution {
public:
    void transpose(vector<vector<int>> &matrix, int n){
        int temp ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                swap(matrix[i][j], matrix[j][i]) ;
            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        if(n <= 1)
            return ;
        // transpose the matrix
        transpose(matrix, n) ;
        
        // reverse each row
        for(int i = 0 ; i < n ; i++){
            reverse(matrix[i].begin(), matrix[i].end()) ;
        }
    }
};