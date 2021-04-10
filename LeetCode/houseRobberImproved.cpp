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
        
        int max_iMinus2 = nums[0] ;
        int max_iMinus1 = max(nums[0], nums[1]) ;
        int currentMax = max_iMinus1;
        
        for(int i = 2 ; i < nums.size() ; i++){
            currentMax = max(max_iMinus1, max_iMinus2 + nums[i]) ;
            max_iMinus2 = max_iMinus1 ;
            max_iMinus1 = currentMax ;
        }
        
        return currentMax ;
    }
};
