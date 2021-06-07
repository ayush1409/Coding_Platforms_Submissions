// Problem: https://leetcode.com/problems/counting-bits/
class Solution {
public:
    vector<int> countBits(int n) {
        //if(n == 0)
        //    return 0 ;
        vector<int> bits(n+1, 0) ;
        int x ;
        
        for(int i = 1 ; i <= n ; i++){
            int x = i ;
            while(x > 0){
                bits[i] += x & 1 ;
                x /= 2 ;
            }
        }
        
        return bits ;
    }
};