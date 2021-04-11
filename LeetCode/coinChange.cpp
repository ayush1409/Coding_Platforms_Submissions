// Problem : https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if(amount == 0)
            return 0 ;
        
        vector<int> numOfCoins(amount+1, INT_MAX) ;
        
        numOfCoins[0] = 0 ;
        
        for(int coin : coins){
            for(int amnt = 1 ; amnt <= amount ; amnt++){
                if(coin <= amnt){
                    if(numOfCoins[amnt - coin] == INT_MAX)
                        continue ;
                    numOfCoins[amnt] = min(numOfCoins[amnt], 1 + numOfCoins[amnt - coin]) ;
                }
            }
        }
        
        if(numOfCoins[amount] != INT_MAX)
            return numOfCoins[amount] ;
        else
            return -1 ;
    }
};
