// Problem : https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() ;
        int n = matrix[0].size() ;
        
        int low = 0, high = m*n - 1 ;
        int i, j, mid ;
        
        while(low <= high){
            mid = low + (high - low)/2 ;
            i = mid / n ;
            j = mid % n ;
            
            if(matrix[i][j] < target)
                low = mid + 1 ;
            else if(matrix[i][j] > target)
                high = mid - 1 ;
            else 
                return true ;
        }
        
        return false ;
    }
};