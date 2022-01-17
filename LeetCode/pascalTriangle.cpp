// Problem : https://leetcode.com/problems/pascals-triangle/submissions/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result ;
        vector<int> buffer ;
        result.push_back(vector<int>(1, 1)) ;
        if(numRows == 1)
            return result ;
        
        for(int i = 1 ; i < numRows ; i++){
            buffer.push_back(1) ;
            for(int j = 0 ; j < i-1 ; j++)
                buffer.push_back(result[i-1][j] + result[i-1][j+1]) ;
            buffer.push_back(1) ;
            
            result.push_back(buffer) ;
            buffer.clear() ;
        }
        
        return result ;
    }
};