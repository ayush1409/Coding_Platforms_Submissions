/*  
    Problem : 
    Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
    Each element in the array represents your maximum jump length at that position.
    Your goal is to reach the last index in the minimum number of jumps.
    You can assume that you can always reach the last index.

    Example 1:
    Input: nums = [2,3,1,1,4]
    Output: 2
    Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

    Example 2:
    Input: nums = [2,3,0,1,4]
    Output: 2

    Constraints:
    1 <= nums.length <= 1000
    0 <= nums[i] <= 105
*/

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