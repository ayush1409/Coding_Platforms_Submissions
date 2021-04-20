// Problem : https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {

        vector<vector<int> > powerset ;
        vector<int> currentSet ;
        int n ;
        
        powerset.push_back(currentSet) ;
        
        if(nums.size() == 0)
            return powerset ;
        
        for(int i = 0 ; i < nums.size() ;i++){
            
            /*
            if(powerset.size() == 0){
                powerset.append(currentSet) ;
                continue ;
            }
            */
            
            n = powerset.size() ;
            
            for(int j = 0 ; j < n ; j++){
                vector<int> current(powerset[j].begin(), powerset[j].end());
                current.push_back(nums[i]) ;
                powerset.push_back(current) ;
            }
        }
        
        return powerset ;
    }
};
