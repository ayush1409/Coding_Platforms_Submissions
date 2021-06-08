class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() ;
        vector<int> finalCost(n, 0) ;
        finalCost[n-1] = cost[n-1] ;
        finalCost[n-2] = cost[n-2] ;
        
        for(int i = n-3 ; i >= 0 ; i--)
            finalCost[i] = cost[i] + min(finalCost[i+1], finalCost[i+2]) ;
        
        return min(finalCost[0], finalCost[1]) ;
    }
};