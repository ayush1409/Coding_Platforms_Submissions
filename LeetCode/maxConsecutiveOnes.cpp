// Problem: https://leetcode.com/problems/max-consecutive-ones/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0 ;
        int maxCount = 0 ;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0)
                count = 0 ;
            else
                count++ ;
            maxCount = max(maxCount, count) ;
        }
        
        return maxCount ;
    }
};