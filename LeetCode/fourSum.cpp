// Problem: https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answer ;
        vector<int> quad ;
        
        int i, j, low, high, a=INT_MIN, b=INT_MIN, c=INT_MIN, d=INT_MIN, newTarget ;
        int n = nums.size() ;
        
        sort(nums.begin(), nums.end()) ;
        
        for(int i = 0 ; i < n ; ){
            a = nums[i] ;
            
            for(int j = i+1 ; j < n ; ){
                
                b = nums[j] ;
                
                // apply 2-sum here
                newTarget = target - (a + b) ;
                
                low = j+1 ;
                high = n-1 ;
                
                while(low < high){
                    if(nums[low] + nums[high] == newTarget){
                        c = nums[low] ;
                        d = nums[high] ;
                        quad.insert(quad.begin(), {a,b,c,d}) ;
                        sort(quad.begin(), quad.end()) ;
                        answer.push_back(quad) ;
                        quad.clear() ;
                        
                        while(low < n && nums[low] == c) low++;
                        
                        while(high >= 0 && nums[high] == d) high-- ;
                    }
                    else if(nums[low] + nums[high] > newTarget)
                        high-- ;
                    else
                        low++ ;
                }
                
                while(j < n && b == nums[j]) j++ ;
                if(j >= n)
                    break ;
                
            }
            
            while(i < n && a == nums[i]) i++ ;
            if(i >= n)
                break ;
        }
        
        return answer ;
    }
};