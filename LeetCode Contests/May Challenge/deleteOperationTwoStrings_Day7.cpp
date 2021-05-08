/*
    Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
    In one step, you can delete exactly one character in either string.

    Example 1:
    Input: word1 = "sea", word2 = "eat"
    Output: 2
    Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

    Example 2:
    Input: word1 = "leetcode", word2 = "etco"
    Output: 4

    Constraints:
    1 <= word1.length, word2.length <= 500
    word1 and word2 consist of only lowercase English letters.
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
      
        unsigned int m = word1.size() ; 
        unsigned int n = word2.size() ;
        
        int ops[m+1][n+1] ;
        
        for(unsigned int j = 0 ; j <= n ; j++)
            ops[0][j] = j ;
        
        for(unsigned int i = 0 ; i <= m ; i++){
            ops[i][0] = i ;    
        }
        
        for(unsigned int i = 1 ; i <= m ; i++){
            for(unsigned int j = 1 ; j <= n ; j++){
                if(word1[i-1] == word2[j-1])
                    ops[i][j] = ops[i-1][j-1] ;
                else
                    ops[i][j] = 1 + min(ops[i-1][j], ops[i][j-1]) ;
            }
        }
        
        return ops[m][n];
    }
};