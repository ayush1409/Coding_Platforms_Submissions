// Problem : https://leetcode.com/problems/construct-target-array-with-multiple-sums/

class Solution {
public:
    unsigned int getMinIdx(vector<int> &target){
        unsigned int minIdx = 0 ;
        for(unsigned int i = 1 ; i < target.size() ; i++){
            if(target[minIdx] > target[i]) 
                minIdx = i ;
        }
        return minIdx ;
    }
    
    unsigned int getMaxIdx(vector<int> &target){
        unsigned int maxIdx = 0 ;
        for(unsigned int i = 1 ; i < target.size() ; i++){
            if(target[maxIdx] < target[i]) 
                maxIdx = i ;
        }
        return maxIdx ;
    }
    
    unsigned int sumWithoutMax(vector<int> &nums, int maxIdx){
        unsigned int sum = 0 ;
        for(unsigned int i = 0 ; i < nums.size() ; i++)
            if(i != maxIdx)
                sum += nums[i] ;
        return sum ;
    }
    
    bool getOnesCount(vector<int> &target){
        unsigned int count = 0 ;
        for(int i = 0 ; i < target.size() ; i++){
            if(target[i] == 1)
                count++ ;
        }
        return count == target.size() ;
    }
    
    bool isPossible(vector<int>& target) {
        if(target.size() == 1 && target[0] != 1)
            return false ;
        
        unsigned int maxIdx, minIdx, count = 0, sum;
        
        maxIdx = getMaxIdx(target) ;
        minIdx = getMinIdx(target) ;
        
        while(target[maxIdx] > 1 && target[minIdx] >= 1){
            sum = sumWithoutMax(target, maxIdx) ;
                
             
            if(target[minIdx] == 1 && target.size() == 2)
                return true ;   
            
            if(target[maxIdx] % sum == 1){
                target[maxIdx] = 1 ;
                if(getOnesCount(target))
                    return true ;
                maxIdx = getMaxIdx(target) ;
                minIdx = getMinIdx(target) ;
                continue ;
            }
            else if(target[maxIdx] % sum == 0)
                return false ;
            
            target[maxIdx] -= sum ;
            maxIdx = getMaxIdx(target) ;
            minIdx = getMinIdx(target) ;
        }
        
        return getOnesCount(target) ;
    }
};