class Solution {
public:
    
    void grayCodeHelper(vector<int> &result, int i, int n){
        if(i == n)
            return ;
        
        for(int j = result.size()-1 ; j >= 0 ; j--){
            result.push_back(result[j] | (1 << i)) ;
        }
        
        grayCodeHelper(result, i+1, n) ;
    }
    
    vector<int> grayCode(int n) {
        
        vector<int> result = {0, 1} ;
        grayCodeHelper(result, 1, n) ;
        
        return result ;
    }
};