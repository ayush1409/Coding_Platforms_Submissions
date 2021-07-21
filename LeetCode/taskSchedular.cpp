// Problem: https://leetcode.com/problems/task-scheduler/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char, int> m ;     // task -> count
        int time = 0 ;
        
        for(auto task: tasks){
            if(m.find(task) != m.end())
                m[task]++ ;
            else
                m[task] = 1 ;
        }
 
        priority_queue<int> pq ;
        
        for(auto task: m){
            pq.push(task.second) ;    
        }
        
        while(!pq.empty()){
            vector<int> canRun ;
            
            for(int i = 0 ; i <= n ; i++){
                if(!pq.empty()){
                    canRun.push_back(pq.top()) ;
                    pq.pop() ;
                }
            }
            
            for(auto x : canRun){
                if(x-1 > 0)
                    pq.push(x-1) ;
            }
            
            time += pq.empty() ? canRun.size() : n+1 ;
        }
        
        return time ;
    }
};