//Time : O(n), Space : O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, minSoFar = prices[0], n = prices.size() ;
        
        if(n == 1)
            return 0 ;
        
        for(int i = 1 ; i < n ; i++){
            maxProfit = max(prices[i] - minSoFar, maxProfit) ;
            
            if(minSoFar > prices[i])
                minSoFar = prices[i] ;
        }
        
        return maxProfit ;
    }
};