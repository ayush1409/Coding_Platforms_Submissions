// Problem: https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longestSeq = 0, currentSeq = 0, n = nums.size() ;
        
        unordered_set<int> uset ;
        
        for(int i = 0 ; i < n ; i++)
            uset.insert(nums[i]) ;
        
        for(int i = 0 ; i < n ; i++){
            currentSeq = 1 ;
            
            if(uset.find(nums[i]-1) == uset.end()){
                for(int j = nums[i]+1 ; ;j++){
                    if(uset.find(j) == uset.end())
                        break ;
                    currentSeq++ ;
                }
            }
            
            longestSeq = max(longestSeq, currentSeq) ;
        }
        
        return longestSeq ;
    }
};

// pseudo code
/*
unordered set: uset
longestSeq = 0, currentSeq = 0

for i in 0 to n-1:
    uset.insert(nums[i])

for i in 0 to n-1:
    if nums[i]-1 exists in uset
        do nothing
    else:
        keep increamenting nums[i] and check existing of element in uset
        if exists in uset, increment the sequence count i.e currentSeq++
        else continue
    make longestSeq as max(currentSeq, longestSeq)
            
return longestSeq
*/