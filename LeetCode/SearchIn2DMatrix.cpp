// Problem : https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        unsigned int row = 0 ;
        unsigned int col = matrix[row].size() - 1 ;
        
        // Search the desired row
        while(row < matrix.size() && target > matrix[row][col]){
            row++ ;
        }
        
        // Row does not found
        if(row == matrix.size())
            return false ;
        
        return binary_search(matrix[row].begin(), matrix[row].end(), target) ;
    }
};