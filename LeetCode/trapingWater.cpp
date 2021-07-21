// Problem: https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ;
        if(n == 0)
            return 0 ;
        
        int water = 0 ;
        vector<int> leftMax(n, 0) ;
        vector<int> rightMax(n, 0) ;
        
        leftMax[0] = height[0] ;
        for(int i = 1 ; i < n ; i++){
            if(height[i] > leftMax[i-1])
                leftMax[i] = height[i] ;
            else
                leftMax[i] = leftMax[i-1] ;
        }
        
        rightMax[n-1] = height[n-1] ;
        for(int j = n-2 ; j >= 0 ; j--){
            if(height[j] > rightMax[j+1])
                rightMax[j] = height[j] ;
            else
                rightMax[j] = rightMax[j+1] ;
        }
        
        for(int i = 0 ; i < n ; i++){
            if(height[i] > leftMax[i] || height[i] > rightMax[i])
                continue ;
            water += min(leftMax[i], rightMax[i]) - height[i] ;
        }
        
        return water ;
    }
};