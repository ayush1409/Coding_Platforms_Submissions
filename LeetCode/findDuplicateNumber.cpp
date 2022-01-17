// Problem : https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0] ;
        
        // Tortoise method, Time: O(N), Space: O(1)
        // 1st meet(detects the cycle)
        do{
            slow = nums[slow] ;
            fast = nums[nums[fast]] ;
        }while(slow != fast) ;
        
        slow = nums[0] ;
        
        // 2nd meet (detects the starting point of the loop)
        while(slow != fast){
            slow = nums[slow] ;
            fast = nums[fast] ;
        }
        
        return slow ;
    }
};

