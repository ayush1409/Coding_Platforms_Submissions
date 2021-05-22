// Problem : https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    void dfs(vector<vector<int>> &adjList, int i, vector<bool> &visited, stack<int> &st){
        visited[i] = true ;
        
        for(auto j : adjList[i]){
            if(!visited[j])
                dfs(adjList, j, visited, st) ;
        }
        
        st.push(i) ;
    }
    
    bool detectCycle(vector<vector<int>> &adjList, int i, vector<bool> &visit, vector<bool> &dfsVisit){
        visit[i] = true ;
        dfsVisit[i] = true ;
        
        for(auto j : adjList[i]){
            if(!visit[j]){
                if(detectCycle(adjList, j, visit, dfsVisit))
                    return true ;
            }
            else if(dfsVisit[j])
                return true ;
        }
        
        dfsVisit[i] = 0 ;
        return false ;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses) ;
        vector<int> result ;
        vector<bool> visited(numCourses, false) ;
        vector<bool> dfsVisit(numCourses, false) ;
        stack<int> st ;
        int x ;
        bool cycleExist = false ;
        
        for(int i = 0 ; i < prerequisites.size() ; i++)
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]) ;
        
        for(int i = 0 ; i < numCourses ; i++){
            if(!visited[i])
                cycleExist = detectCycle(adjList, i, visited, dfsVisit) ;
            if(cycleExist)
                break ;    // cycleExist == true when cycle exists
        }
        
        if(cycleExist)
            return result ;
        
        for(int i = 0 ; i < numCourses ; i++)
            visited[i] = false ;
        
        for(int i = 0 ; i < numCourses ; i++){
            if(!visited[i]){
                dfs(adjList, i, visited, st) ;
            }
        }
        
        while(!st.empty()){
            x = st.top() ;
            st.pop() ;
            result.push_back(x) ;
        }
        
        reverse(result.begin(), result.end()) ;
        
        return result ;
    }
};