// Problem : https://leetcode.com/problems/course-schedule/

class Solution {
public:
    
    bool dfs(vector<vector<int>> &adjList, int i, vector<bool> &visit, vector<bool> &dfsVisit){
        visit[i] = true ;
        dfsVisit[i] = true ;
        
        for(auto j : adjList[i]){
            if(!visit[j]){
                if(dfs(adjList, j, visit, dfsVisit))
                    return true ;
            }
            else if(dfsVisit[j])
                return true ;
        }
        
        dfsVisit[i] = 0 ;
        return false ;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses) ;
        vector<bool> visit(numCourses, false) ;
        vector<bool> dfsVisit(numCourses, false) ;
        bool result ;
        
        for(int i = 0 ; i < numCourses ; i++){
            for(int j = 0 ; j < prerequisites.size() ; j++){
                if(prerequisites[j][0] == i)
                    adjList[i].push_back(prerequisites[j][1]) ;
            }
        }
        
        for(int i = 0 ; i < numCourses ; i++){
            if(!visit[i])
                result = dfs(adjList, i, visit, dfsVisit) ;
            if(result)
                return !result ;    // result = true when cycle exists
        }
        
        return true ;
    }
};