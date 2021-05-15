// Problem : https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        unsigned int mod = 1000000007 ;
        vector<vector<int>> dp(target + 1, vector<int>(d + 1, 0)) ;
        
        for(int i = 1 ; i <= f ; i++){
            if(i > target)
                break ;
            dp[i][1] = 1;
        }
        
        dp[0][0] = 1 ;
        
        for(int sum = 2 ; sum <= target ; sum++){
            for(int j = 2 ; j <= d ; j++){
                for(int x = 1 ; x <= f ; x++){
                    if(sum < x)
                        break ;
                    dp[sum][j] = (dp[sum][j] + dp[sum - x][j-1]) % mod ;
                }
            }
        }
        
        return dp[target][d] ;
    }
};