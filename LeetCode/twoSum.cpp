// Problem: https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size(), j ;
        //sort(nums.begin(), nums.end()) ;
        
        vector<int> ans ;
        // (element, index) pair stored
        unordered_map<int, int> umap ;
        unordered_map<int, int>::iterator it ;
        
        for(int i = 0 ; i < n ; i++){
            it = umap.find(target - nums[i]) ;
            
            if(it != umap.end()){
                j = it -> second;
                if(i < j){
                    ans.push_back(i) ;
                    ans.push_back(j) ;
                }
                else{
                    ans.push_back(j) ;
                    ans.push_back(i) ;
                }
                break ;
            }
            
            umap[nums[i]] = i ;
        }
        
        return ans ;
    }
};