// Problem: https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = INT_MIN, num2 = INT_MIN, count1 = 0, count2 = 0 ;
        int n = nums.size() ;
        vector<int> result ;
        
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == num1)
                count1++ ;
            else if(nums[i] == num2)
                count2++ ;
            else if(count1 == 0){
                num1 = nums[i] ;
                count1 = 1 ;
            }
            else if(count2 == 0){
                num2 = nums[i] ;
                count2 = 1;
            }
            else{
                count1-- ;
                count2-- ;
            }
        }
        
        count1 = 0 ;
        count2 = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == num1)
                count1++ ;
            if(nums[i] == num2)
                count2++ ;
        }
        
        if(count1 > n/3)
            result.push_back(num1) ;
        if(count2 > n/3)
            result.push_back(num2) ;
        
        return result ;
        
    }
};