// Problem: https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0, j = 0 ;
        vector<int> ans ;
        deque<int> dq ;
        
        // window expansion
        for(i = 0 ; i < k ; i++){
            while(!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back() ;
            dq.push_back(i) ;
        }
        
        for( ; i < nums.size() ; i++){
            ans.push_back(nums[dq.front()]) ;
            
            // remove all outoff window elements from the front
            while(!dq.empty() && i-k >= dq.front())
                dq.pop_front() ;
            
            // keep poping until we get the next candidate for the upcoming maximum
            while(!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back() ;
            dq.push_back(i) ;
        }
        
        ans.push_back(nums[dq.front()]) ;
        
           
        /*
        // All test cases are not passing
        while(j < nums.size()){
            // insert the current maximum candidate in the queue and remove all the redundant candiates 
            if(!dq.empty() && dq.back() < nums[j])
                dq.pop_back() ;
            dq.push_back(nums[j]) ;
            
            if(j-i+1 < k)
                j++ ;
            else if(j-i+1 == k){
                // first element in the queue contains the window maximum
                ans.push_back(dq.front()) ;
                
                // slide the window
                if(dq.front() == nums[i])
                    dq.pop_front() ;
                i++ ;
                j++ ;
            }
        }
        */
        
        return ans ;
    }
};