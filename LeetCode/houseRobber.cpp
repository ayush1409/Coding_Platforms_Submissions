class Solution {
public:
    int max(int a, int b){
        return a > b ? a : b ;
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0 ;
        
        if(nums.size() == 1)
            return nums[0] ;
        
        vector<int> maxAmount(nums.size()) ;
        
        maxAmount[0] = nums[0] ;
        maxAmount[1] = max(nums[0], nums[1]) ;
        
        for(int i = 2 ; i < nums.size() ; i++){
            maxAmount[i] = max(maxAmount[i-1], maxAmount[i-2] + nums[i]) ;
        }
        
        return maxAmount[nums.size() - 1] ;
    }
};
