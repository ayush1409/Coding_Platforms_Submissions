// Problem: https://leetcode.com/problems/combination-sum/

class Solution {
public:
    
    void combination(int i, vector<int> &candidates, int target, vector<int> &nums, vector<vector<int>> &answer){
        int n = candidates.size() ;
    
        if(i == n){
            //cout<<i<<endl ;
            if(target == 0){
                answer.push_back(nums) ;
            }
            return ;
        }
        
        // picking candidates[i]
        
        if(candidates[i] <= target){
            nums.push_back(candidates[i]) ;
            combination(i, candidates, target - candidates[i], nums, answer) ;
            nums.pop_back() ;
        }
        
        // not picking candidates[i]
        combination(i+1, candidates, target, nums, answer) ;    
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer ;
        //int sum = 0 ;
        vector<int> nums ;
        
        combination(0, candidates, target, nums, answer) ;
        
        return answer ;
    }
};