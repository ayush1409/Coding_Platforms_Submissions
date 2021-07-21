// Problem: https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    
    void canVisit(vector<vector<int>> &rooms, int i, vector<bool> &visited){
        visited[i] = true ;
        
        for(auto nbr: rooms[i])
            if(!visited[nbr])
                canVisit(rooms, nbr, visited) ;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size() ;
        vector<bool> visited(n, false) ;
        
        canVisit(rooms, 0, visited) ;
        
        for(auto visit : visited)
            if(!visit)
                return false ;
        
        return true ;
    }
};