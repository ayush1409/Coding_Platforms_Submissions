// Problem : https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {

        vector<vector<int> > powersets ;
        vector<int> currentSet ;
        int n ;
        
        powersets.push_back(currentSet) ;
        
        if(nums.size() == 0)
            return powersets ;
        
        for(int i = 0 ; i < nums.size() ;i++){
            
            /*
            if(powersets.size() == 0){
                powersets.append(currentSet) ;
                continue ;
            }
            */
            
            n = powersets.size() ;
            
            for(int j = 0 ; j < n ; j++){
                vector<int> current(powersets[j].begin(), powersets[j].end());
                current.push_back(nums[i]) ;
                powersets.push_back(current) ;
            }
        }
        
        return powersets ;
    }
};
