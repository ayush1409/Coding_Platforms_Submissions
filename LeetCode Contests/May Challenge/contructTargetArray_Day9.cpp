/*
    Problem : Given an array of integers target. From a starting array, A consisting of all 1's, you may perform the following procedure :

    let x be the sum of all elements currently in your array.
    choose index i, such that 0 <= i < target.size and set the value of A at index i to x.
    You may repeat this procedure as many times as needed.
    Return True if it is possible to construct the target array from A otherwise return False.

    Example 1:
    Input: target = [9,3,5]
    Output: true
    Explanation: Start with [1, 1, 1] 
    [1, 1, 1], sum = 3 choose index 1
    [1, 3, 1], sum = 5 choose index 2
    [1, 3, 5], sum = 9 choose index 0
    [9, 3, 5] Done

    Example 2:
    Input: target = [1,1,1,2]
    Output: false
    Explanation: Impossible to create target array from [1,1,1,1].

    Example 3:
    Input: target = [8,5]
    Output: true
    
    Constraints:
    N == target.length
    1 <= target.length <= 5 * 10^4
    1 <= target[i] <= 10^9
*/

// My Code
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
/*
From Discusion code(More Optimized)
class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        unsigned int sum = 0;
        for (int num : target)
            sum += num, pq.push(num);
        while (pq.top() != 1) {
            int num = pq.top();
            pq.pop();
            sum -= num;
            if (num <= sum || sum < 1) return false;
            num %= sum, sum += num, pq.push(num ? num : sum);
        }
        return true;
    }
};
*/