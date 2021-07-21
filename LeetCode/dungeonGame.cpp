// Problem: https://leetcode.com/problems/dungeon-game/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size() ;
        int n = dungeon[0].size() ;
        int x, y ;
        vector<vector<int>> life(m, vector<int>(n, 0)) ;
        
        for(int i = m-1 ; i >= 0 ; i--){
            for(int j = n-1 ; j >= 0 ; j--){
                if(i == m-1 && j == n-1)
                    life[i][j] = min(0, dungeon[i][j]) ;
                else if(i == m-1){
                    life[i][j] = min(0, life[i][j+1] + dungeon[i][j]) ;
                }
                else if(j == n-1){
                    life[i][j] = min(0, life[i+1][j] + dungeon[i][j]) ;
                }
                else{
                    life[i][j] = min(0, max(life[i+1][j], life[i][j+1]) + dungeon[i][j]) ;
                }
            }
        }        
        
        return abs(life[0][0]) + 1 ;
    }
};