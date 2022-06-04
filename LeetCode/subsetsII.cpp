// Problem: https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    
    void subsets_util(int i, const vector<int> &nums, vector<int> &subset, set<vector<int>> &subset_list){
        int n = nums.size() ;
        if(i == n){
            vector<int> temp(subset.begin(), subset.end()) ;
            sort(temp.begin(), temp.end()) ;
            subset_list.insert(temp) ;
            return ;
        }
        
        // not selecting the element
        subsets_util(i+1, nums, subset, subset_list) ;
        
        // selecting the element
        subset.push_back(nums[i]) ;
        subsets_util(i+1, nums, subset, subset_list) ;
        subset.pop_back() ;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> subset_list ;
        vector<int> subset ;
    
        subsets_util(0, nums, subset, subset_list) ;
        
        return vector<vector<int>>(subset_list.begin(), subset_list.end()) ;
        
        
    }
};
