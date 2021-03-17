class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1 ;
        unsigned int mid1, mid2 ;
       
        vector<int> locations(2, -1) ;
        
        //Lower Bound
        while(l<=r){
            mid1 = l + (r-l)/2 ;
            
            if(nums[mid1] == target && (mid1 == 0 || nums[mid1 - 1] != target)){
                locations[0] = mid1 ;
                break ;
            }
            if(nums[mid1] < target)
                l = mid1 + 1 ;
            else
                r = mid1 - 1;
        }
        
        l = 0 ;
        r = nums.size() - 1 ;
        
        // Upper Bound
        if(locations[0] != -1){
            while(l<=r){
                mid2 = l + (r-l)/2 ;
                
                if(nums[mid2] == target && (mid2 == nums.size()-1 || nums[mid2+1] != target)){
                    locations[1] = mid2 ;
                    break ;
                }
                if(nums[mid2] > target)
                    r = mid2 - 1 ;
                else
                    l = mid2 + 1 ;
                
            }
        }
    
        return locations ;
        
    }
};
