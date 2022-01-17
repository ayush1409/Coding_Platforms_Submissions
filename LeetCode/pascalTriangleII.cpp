// Problem : https://leetcode.com/problems/pascals-triangle-ii/submissions/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0)
            return vector<int>(1,1) ;
        
        vector<int> result ;
        long int buff = 1;
        result.push_back(1) ;
               
        for(int j = 1 ; j < rowIndex ; j++){
            buff = (buff * (rowIndex - j + 1)) / j ;
            result.push_back(buff) ;
        }
        result.push_back(1) ;
        
        return result ;
    }
};

