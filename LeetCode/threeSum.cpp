// Problem: https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer ;
        vector<int> triplet ;
        int a = INT_MIN, b = INT_MIN, c = INT_MIN, i, low, high, target ;
        int n = nums.size() ;
        
        sort(nums.begin(), nums.end()) ;
        
        for(int i = 0 ; i < n ;){
            while(i < n && a == nums[i]) i++ ;
            if(i >= n)
                break ;
            
            a = nums[i] ;
            
            target = -a ;
            
            low = i+1 ;
            high = n-1 ;
            
            // two sum b + c = -a
            while(low < high){
                if(nums[low] + nums[high] > target)
                    high-- ;
                else if(nums[low] + nums[high] < target)
                    low++ ;
                else{
                    triplet.push_back(a) ;
                    triplet.push_back(nums[low]) ;
                    triplet.push_back(nums[high]) ;
                    sort(triplet.begin(), triplet.end()) ;
                    b = nums[low] ;
                    c = nums[high] ;
                    answer.push_back(triplet) ;
                    triplet.clear() ;
                    
                    while(low < n && nums[low] == b) low++ ;
                    
                    while(high >= 0 && nums[high] == c) high-- ;
                }
            }
        }
        
        return answer ;
    }
};
