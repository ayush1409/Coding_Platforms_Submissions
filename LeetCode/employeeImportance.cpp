// Problem: https://leetcode.com/problems/employee-importance/

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> um ;
        int result = 0 ;
        
        for(auto employee: employees)
            um.insert({employee -> id, employee}) ;
        
        if(um.find(id) == um.end())
            return 0 ;
        
        queue<Employee*> q ;
        q.push(um.find(id) -> second) ;
        
        while(!q.empty()){
            Employee *curr = q.front();
            int empId = curr -> id;
            q.pop() ;
            
            result += curr -> importance ;
            
            for(auto sub : curr -> subordinates){
                auto it = um.find(sub) ;
                if(it != um.end())
                    q.push(it -> second) ;
            }
            
        }
        
        return result ;
    }
};