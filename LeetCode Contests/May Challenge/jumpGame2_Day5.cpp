class Solution {
public:
    
    int min(int x , int y){
        return x < y ? x : y ;
    }
    int jumpGameHelper(vector<int> &nums, vector<int> &minJumps, int i){
        if(i >= nums.size() - 1)
            return 0 ;
        
        if(minJumps[i] != 2000)
            return minJumps[i] ;
        
        for(int j = 1 ; j <= nums[i] ; j++){
            minJumps[i] = min(minJumps[i] , 1 + jumpGameHelper(nums, minJumps, i+j)) ;
        }
        
        return minJumps[i] ;
    }
    
    int jump(vector<int>& nums) {
        if(nums.size() == 1)
            return 0 ;
        vector<int> minJumps(nums.size(), 2000) ;
        return jumpGameHelper(nums, minJumps, 0) ;
    }
};