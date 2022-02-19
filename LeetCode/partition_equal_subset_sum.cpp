// Problem: https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool subset_sum(vector<int> &nums, long int sum){
        
        int n = nums.size() ;
        
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1)) ;
        sort(nums.begin(), nums.end()) ;
        
        for(int i = 0 ; i <= n ; i++){
            for(long int j = 0 ; j <= sum ; j++){
                if(i == 0)
                    dp[i][j] = false ;
                else if(j == 0)
                    dp[i][j] = true ;
                else{
                    if(nums[i-1] <= j)
                        dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]] ;
                    else
                        dp[i][j] = dp[i-1][j] ;
                }
            }
        }
        return dp[n][sum]; 
    }
    
    bool canPartition(vector<int>& nums) {
        long sum = 0, target_sum;
        int n = nums.size() ;
    
        for(int i = 0 ; i < n ; i++)
            sum += nums[i] ;
        
        if(sum % 2)
            return false ;
        
        return subset_sum(nums, sum/2) ;
    }
};