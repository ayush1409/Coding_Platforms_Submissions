// Problem : https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int max(int a, int b){
        return a>b? a : b ;
    }
    
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0 ;
        
        int maxEndingHere = nums[0] ;
        int maxSoFar = nums[0] ;
        
        for(int i = 1 ; i < nums.size() ; i++){
            maxEndingHere = max(maxEndingHere + nums[i], nums[i]) ;
            maxSoFar = max(maxEndingHere, maxSoFar) ;
        }
        
        return maxSoFar ;
    }
};
