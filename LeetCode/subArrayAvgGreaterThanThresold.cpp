// Problem : https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i = 0, j = 0, count = 0 ;
        long long sum = 0 ;
        while(j < arr.size()){
            sum += arr[j] ;
            
            // window expansion
            if(j-i+1 < k)
                j++ ;
            else if(j-i+1 == k){
                // compute answer from the current window
                if(sum/k >= threshold)
                    count++ ;
                
                // slide the window
                sum -= arr[i] ;
                i++ ;
                j++ ;
                
            }
        }
        
        return count ;
    }
};