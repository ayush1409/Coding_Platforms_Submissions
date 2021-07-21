class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size() ;
        int n = nums2.size() ;
        int maxLength = INT_MIN ;
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0)) ;
        
        for(int i = 0 ; i <= m ; i++)
            dp[i][0] = 0 ;
        
        for(int j = 0 ; j <= n ; j++)
            dp[0][j] = 0 ;
        
        for(int i = 1 ; i <= m ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(nums1[i-1] == nums2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1 ;
            }
        }
        
        for(int i = 0 ; i <= m ; i++){
            for(int j = 0 ; j <= n ; j++){
                if(maxLength < dp[i][j])
                    maxLength = dp[i][j] ;
            }
        }
        
        return maxLength ;
    }
};