// Problem : https://leetcode.com/problems/move-zeroes/

class Solution {
public:
   
    void swap(int &x, int &y){
        int temp = x ;
        x = y ;
        y = temp ;
    }
    
    void moveZeroes(vector<int>& nums) {
        int target = 0 ;
        int i = -1 ;
        unsigned int count = 0 ;
        
        for(int j = 0 ; j<nums.size() ; j++){
            if(nums[j] == target){
                count++ ;
                continue ;
            }else{
                i++ ;
                nums[i] = nums[j] ;
            }
        }
        
        if(i != -1 && count > 0){
            for(int j = i+1 ; j<nums.size() ; j++){
                nums[j] = target ;
            }
        }
        /*
        // In this approach relative ordering of the non target elements may changed 
        int i = nums.size() ;
        int target = 0 ; 
        for(int j = nums.size()-1 ; j >= 0 ; j--){
            if(nums[j] == target){
                i-- ;
                swap(nums[i], nums[j]) ;
            }
        }
        */
    }
};
