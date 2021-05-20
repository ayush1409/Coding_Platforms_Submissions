// Problem : https://leetcode.com/problems/time-needed-to-inform-all-employees/

class Solution {
public:
    int max(int x, int y){
        return x > y ? x : y ;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int maxInformTime = 0 ;
        
        // From employee to manager (move up)
        for(int i = 0 ; i < n ; i++){
            int j = i, currTime = 0 ;
            
            while(j != -1){
                currTime = manager[j] == -1 ? currTime : currTime + informTime[manager[j]];
                j = manager[j] ;
            }
            
            maxInformTime = max(maxInformTime, currTime );
        }
        
        return maxInformTime ;
    }
};