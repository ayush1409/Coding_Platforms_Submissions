// Problem: https://leetcode.com/problems/single-element-in-a-sorted-array/submissions/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size() ;
        int low = 0, high = n-1, mid ;
        
        while(low <= high){
            mid = low + (high - low)/2 ;
            
            if(mid > 0 && nums[mid] == nums[mid-1]){    // first occurance in left
                if((mid-1) % 2)     // first occurance at odd index
                    high = mid - 1 ;
                else
                    low = mid + 1;
            }
            else if(mid < high && nums[mid] == nums[mid+1]){ // first occurance is mid
                if(mid % 2)         // first occurance at odd index
                    high = mid - 1 ;
                else
                    low = mid + 1 ;
            }
            else
                break ;
        }
        
        return nums[mid] ;
    }
};