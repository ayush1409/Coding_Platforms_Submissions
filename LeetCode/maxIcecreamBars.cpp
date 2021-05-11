// Problem : https://leetcode.com/problems/maximum-ice-cream-bars/
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int count = 0 ;
        sort(costs.begin(), costs.end()) ;
        
        for(int i = 0 ; i < costs.size() ; i++){
            if(coins - costs[i] >= 0){
                count++ ;
                coins -= costs[i] ;
            }
            else
                return count ;
        }
        
        return count ;
    }
};