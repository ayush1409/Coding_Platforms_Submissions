// Problem: https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int Xor = 0 ;
        
        for(int i = 0 ; i < nums.size() ; i++)
            Xor = Xor ^ nums[i] ;
        
        return Xor ;
    }
};
