// Problem: https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ;
        
        if(n <= 2)
            return 0 ;
        
        int leftMax = 0, rightMax = 0, l = 0, r = n-1, water = 0;
    
        while(l <= r){
            if(height[l] <= height[r]){
                if(height[l] > leftMax)
                    leftMax = height[l] ;
                else
                    water += leftMax - height[l] ;
                l++ ;
            }
            else{
                if(height[r] > rightMax)
                    rightMax = height[r] ;
                else
                    water += rightMax - height[r] ;
                r-- ;
            }
        }
        
        return water ;
    }
};