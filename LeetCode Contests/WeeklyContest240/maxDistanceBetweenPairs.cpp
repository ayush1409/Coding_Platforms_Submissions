class Solution {
public:
    int max(int x, int y){
        return x > y ? x : y ;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size() ;
        int n = nums2.size() ;
        vector<pair<int, int>> validPairs ;
        int distanceMax = 0 ;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = i ; j < n ; j++){
                if(nums1[i] <= nums2[j])
                    validPairs.push_back({i,j}) ;
                else
                    break ;
            }
        }
        
        if(validPairs.size() == 0)
            return 0 ;
        
        for(auto x : validPairs){
            distanceMax = max(distanceMax, x.second - x.first) ;
        }
        
        return distanceMax ;
    }
};