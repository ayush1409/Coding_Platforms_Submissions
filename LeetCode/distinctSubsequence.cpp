// Problem : https://leetcode.com/problems/distinct-subsequences/

class Solution {
public:
    int max(int a, int b, int c){
        return a > b ? (a > c ? a : c) : (b > c ? b : c) ;
    }
    int numDistinct(string s, string t) {
        int n = s.size() ;
        int m = t.size() ;
        
        vector<vector<unsigned int>> sequence(m+1, vector<unsigned int>(n+1, 0)) ;
        
        for(int j = 0 ; j <= n ; j++){
            sequence[0][j] = 1 ;
        }
    
        for(int i = 1 ; i<= m ; i++)
        {
            for(int j = i ; j <= n ; j++)
            {
                if(t[i-1]==s[j-1])
                    sequence[i][j] = sequence[i][j-1] + sequence[i-1][j-1];
                else
                    sequence[i][j] = sequence[i][j-1] ;
            }
        }
        
        return sequence[m][n] ;
    }
};