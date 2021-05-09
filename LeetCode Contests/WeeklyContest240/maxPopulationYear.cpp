class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int population ;
        int global_min_year = 2051, global_max_population = 0 ;
        
        for(int x = 1950 ; x < 2050 ; x++){
            population = 0 ;
            for(int i = 0 ; i < logs.size() ; i++){
                if(x >= logs[i][0] && x < logs[i][1])
                    population++ ;
            }
            if(population > global_max_population){
                global_max_population = population ;
                global_min_year = x ;
            }
        }
        
        return global_min_year ;
    }
};