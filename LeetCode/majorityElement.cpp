// Problem: https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element , count = 0, n = nums.size() ;
        
        // Moore's voting algorithm
        for(int i = 0 ; i < n ; i++){
            if(count == 0)
                element = nums[i] ;
            if(element == nums[i])
                count++ ;
            else
                count-- ;
        }
        
        return element ;
    }
};