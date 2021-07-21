class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size() ;
        vector<int> incSubSeq(n, 1) ;
        int maxSubSeq = INT_MIN ;
        vector<int> result ;        // Stores the maximum subsequence
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++)
                if(nums[i] > nums[j] && incSubSeq[i] <= incSubSeq[j])
                    incSubSeq[i] = 1 + incSubSeq[j] ;
        }
        
        for(auto subs: incSubSeq)
            if(subs > maxSubSeq)
                maxSubSeq = subs ;
        
        /*
        // How to get max SubSeq
        int seqSize = maxSubSeq ;
        for(int i = n-1 ; i >= 0 ;){
            while(incSubSeq[i] < seqSize && i >= 0)
                i-- ;
            if(i < 0)
                break ;
            result.push_back(nums[i]) ;
            seqSize-- ;
            i--;
        }
        
        reverse(result.begin(), result.end()) ;
        for(auto x: result)
            cout<<x<<" " ;
        cout<<endl ;
        */
        
        return maxSubSeq ;
        
    }
};