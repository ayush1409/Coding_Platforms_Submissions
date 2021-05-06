// Problem : https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size() ;
        int maxSoFar = arr[n-1] ;
        vector<int> result(n, -1) ;
        //arr[n-1] = -1 ;
        
        for(int i = n-2 ; i >= 0 ; i--){
            result[i] = maxSoFar ;
            if(i < n-1 && arr[i] > maxSoFar)
                maxSoFar = arr[i] ;
        }
        
        return result ;
    }
};