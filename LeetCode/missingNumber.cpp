// Problem : https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int xorSum = 0;
        
        for(int i : nums){
            xorSum ^= i ;
        }
        
        
        for(int i = 0 ; i <= nums.size() ; i++)
            xorSum ^= i ;
        
        return xorSum ;
        
    }
};
