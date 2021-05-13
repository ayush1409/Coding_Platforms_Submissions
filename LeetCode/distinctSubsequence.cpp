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
        
        /* Sample Test cases passed only(Not correct)
        for(int i = 1 ; i <= m ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(j >= i){
                    /*
                    if(i == j && t[i] != s[j]){
                        sequence[i][j] = 0 ;
                        continue ;
                    }
                    if(i == j && t[i] == s[j]){
                        sequence[i][j] = 1 ;
                        continue ;
                    }
                    */
        /*
                    if(t[i-1] == s[j-1]){
                        if(i == 1 || j == 1){
                            sequence[i][j] = max(sequence[i-1][j], sequence[i-1][j-1], sequence[i][j-1]) ;
                            continue ;
                        }
                        if(t[i-2] == s[j-2])
                            sequence[i][j] = max(sequence[i-1][j], sequence[i-1][j-1], sequence[i][j-1]) ;
                        else
                            sequence[i][j] = 1 + max(sequence[i-1][j], sequence[i-1][j-1], sequence[i][j-1]) ;
                    }
                    else{
                        sequence[i][j] = max(sequence[i-1][j], sequence[i-1][j-1], sequence[i][j-1]) ;
                    }
                }
            }
        }
        */
        for(int i = 1 ; i<= m ; i++)
        {
            for(int j = i ; j < n ; j++)
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