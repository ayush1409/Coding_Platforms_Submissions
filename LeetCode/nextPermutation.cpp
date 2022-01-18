// Problem : https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void swap(int &a, int &b){
        int temp = a ;
        a = b ;
        b = temp ;
    }
    
    void nextPermutation(vector<int>& nums) {
        int idx1, idx2 ;
        
        if(nums.size() <= 1)
            return ;
        
        for(idx1 = nums.size()-1 ; idx1 >= 0 ; idx1--)
            if(idx1 < nums.size() - 1 && nums[idx1] < nums[idx1+1])
                break ;
        
        if(idx1 < 0){
            reverse(nums.begin(), nums.end()) ;
            return ;    
        }
        
        idx2 = nums.size() - 1 ;
        while(idx2 >= 0 && nums[idx1] >= nums[idx2])
            idx2-- ;
        
        swap(nums[idx1], nums[idx2]) ;
        
        if(idx1 + 1 < nums.size())
            reverse(nums.begin() + idx1 + 1, nums.end()) ;
    }
};