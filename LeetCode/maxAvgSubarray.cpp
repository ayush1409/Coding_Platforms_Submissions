// Problem : https://leetcode.com/problems/maximum-average-subarray-i/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0, j = 0;
        double maxAvg = -FLT_MAX, sum = 0 ;
        
        while(j < nums.size()){
            sum += nums[j] ;
            
            // expanding the window
            if(j-i+1 < k)
                j++ ;
            // reached a window size
            else if(j-i+1 == k){        
                maxAvg = max(sum/k, maxAvg) ;
                
                // slide the window
                sum -= nums[i] ;
                i++ ;
                j++ ;
            }
        }
        
        return maxAvg ;
    }
};