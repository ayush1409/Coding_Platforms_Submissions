// Problem : https://leetcode.com/problems/minimum-distance-to-the-target-element/

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int result = INT_MAX ;
        int i = start, j = start ;
        
        while(i >= 0 && j < nums.size()){
            if(nums[i] == target){
                if(result > abs(i - start))
                    result = abs(i - start) ;
            }
            if(nums[j] == target){
                if(result > abs(j - start))
                    result = abs(j - start) ;
            }
            i-- ;
            j++ ;
        }
        
        while(i >= 0){
           if(nums[i] == target){
                if(result > abs(i - start))
                    result = abs(i - start) ;
            } 
            i-- ;
        }
        
        while(j < nums.size()){
            if(nums[j] == target){
                if(result > abs(j - start))
                    result = abs(j - start) ;
            }
            j++ ;
        }
        
        return result ;
    }
};