// Problem : https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int j = -1, count = 0, maxLen = 0 ;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0)
                count++ ;
            
            while(count > k){
                j++ ;
                if(nums[j] == 0)
                    count-- ;
            }
            
            int len = i - j ;
            //cout<<len ;
            if(len > maxLen)
                maxLen = len ;
        }
        
        return maxLen ;
        
    }
};