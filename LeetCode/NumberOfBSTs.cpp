// Problem : https://leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:
    int numTrees(int n) {
        vector<unsigned int> Trees(n+1) ;
        
        for(int i = 0 ; i<=n ; i++)
            Trees[i] = 0 ;
        
        Trees[0] = 1;
        Trees[1] = 1;
        
        for(int i = 2 ; i<=n ; i++){
            for(int j = 0 ; j < i ; j++)
                Trees[i] += Trees[j] * Trees[i-j-1] ;
        }
        
        return Trees[n] ;
    }
};
