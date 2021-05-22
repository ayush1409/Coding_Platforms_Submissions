// Problem : https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    
    // Kahn algorithm for topological sort (using BFS)
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses, 0) ;
        vector<vector<int>> adjList(numCourses) ;
        queue<int> q;
        vector<int> result ;
        int countNodes = 0 ;
        
        for(int i = 0 ; i < prerequisites.size(); i++){
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]) ;
            indeg[prerequisites[i][1]]++ ;   
        }
        
        
        for(int i = 0 ; i < numCourses ; i++){
            if(indeg[i] == 0)
                q.push(i) ;
        }
    
        while(!q.empty()){
            int curr = q.front() ;
            q.pop() ;
            
            for(auto j : adjList[curr]){
                indeg[j]-- ;
                if(indeg[j] == 0)
                    q.push(j) ;
            }
            
            countNodes++ ;
            if(countNodes > numCourses){
                result.clear() ;
                return result ;
            }
            
            result.push_back(curr) ;
        }
        
        if(countNodes != numCourses){
            result.clear() ;
            return result ;
        }
        
        reverse(result.begin(), result.end()) ;
        
        return result ;
    }
};