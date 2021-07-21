class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size() ;
        int n = mat[0].size() ;
        
        if(m*n != r*c)
            return mat ;
        
        vector<vector<int>> result(r, vector<int>(c, 0)) ;
        int i = 0, j = 0, k = 0, l = 0 ;
 
        while(i < m && k < r){
            
            result[k][l] = mat[i][j] ;
    
            j++, l++ ;
            
            if(j == n){
                i++ ; j = 0 ;
            }
            
            if(l == c){
                k++ ; l = 0 ;
            }
    
        }
        return result ;
    }
};