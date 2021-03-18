// Problem : https://leetcode.com/problems/find-peak-element/submissions/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0 ;
        int right = nums.size() - 1, mid ;
        
        while(left < right){
            mid = left + (right - left)/2 ;
            if(nums[mid] < nums[mid+1])
                left = mid + 1 ;
            else
                right = mid;
        }
        return left ;
    }
};
