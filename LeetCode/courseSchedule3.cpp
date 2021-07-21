

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int totalTime = 0, maxDur;
        
        sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b) {
            if(a[1] < b[1])
                return true ;
            else if(a[1] == b[1])
                return a[0] < b[0] ;
            else
                return false ;
        }) ;
        
        priority_queue<int> pq;
        
        for(int i = 0 ; i < courses.size() ; i++){
            if(totalTime + courses[i][0] <= courses[i][1]){
                totalTime += courses[i][0] ;
                pq.push(courses[i][0]) ;
            }
            else{
                if(pq.empty())
                    continue ;
                
                maxDur = pq.top() ;
                if(maxDur > courses[i][0]){
                    // replace the maxDur by courses[i]
                    pq.pop() ;
                    pq.push(courses[i][0]) ;
                    
                    totalTime -= maxDur ;
                    totalTime += courses[i][0] ;
                }
            }
        }
        
        return pq.size() ;
        /*
        for(int i = 0 ; i < courses.size() ; i++){
            
            if(totalTime + courses[i][0] <= courses[i][1]){
                // schedule course
                totalTime += courses[i][0] ;
                courseCount++ ;
            }
        }
        
        return courseCount ;
        */
    }
};