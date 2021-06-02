// Problem: https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result ;
        int n = nums.size() ;
        set<vector<int>> tset ;
        vector<int> triplet ;
        
        if(nums.size() <= 2)
            return result ;
        
        sort(nums.begin(), nums.end()) ;
        
        for(int i = 0 ; i < n ; ){
            int a = nums[i] ;
            int l = 0, r = n-1 ;
            triplet.push_back(a) ;
            
            while(l < r){
                if(l == i){
                    l++ ;
                    continue ;
                }
                if(r == i){
                    r-- ;
                    continue ;
                }
                
                int b = nums[l] ;
                int c = nums[r] ;
                
                if(b + c == -a){
                    triplet.push_back(b) ;
                    triplet.push_back(c) ;
                    sort(triplet.begin(), triplet.end()) ;
                    tset.insert(triplet) ;
                    triplet.clear();
                    triplet.push_back(a) ;
                    
                    while(l < n && nums[l] == b)
                        l++ ;
                    while(r >= 0 && nums[r] == c)
                        r-- ;

                }
                else if(b + c < -a){
                    l++ ;
                }
                else
                    r-- ;
            }
            triplet.clear() ;
            while(i < n && nums[i] == a)
                i++ ;
            
        }
        
        for(auto t: tset)
            result.push_back(t) ;
        
        return result ;
    }
};