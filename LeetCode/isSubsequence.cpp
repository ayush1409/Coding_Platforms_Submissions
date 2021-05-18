// Problem : https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size() ;
        int n = t.size() ;
        vector<vector<bool>> isSeq(m+1, vector<bool>(n+1, false)) ;
        
        for(int j = 0 ; j <= n ; j++)
            isSeq[0][j] = true ;
        
        for(int i = 1 ; i <= m ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(s[i-1] == t[j-1])
                    isSeq[i][j] = isSeq[i-1][j-1] ;
                else
                    isSeq[i][j] = isSeq[i-1][j] && isSeq[i][j-1] ;
            }
        }
        
        return isSeq[m][n] ;
    }
};