class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        vector<int> result;
        unsigned int crashTime = 1 ;
        long int m1 = memory1, m2 = memory2 ;
        unsigned int sum = memory1 + memory2 ;
        
        for(int i = 2 ; i * (i-1)/2 < sum ; i++)
            crashTime++ ;
        result.push_back(crashTime) ;
        
        int i = 1 ;
        while(m1 - i >= i && m2 - i >= i){
            if(m1 >= m2)
                m1 -= i ;
            else
                m2 -= i ;
            i++ ;
        }
        
        while(memory1 - m1 >= i){
            m1 -= i ;
            i++ ;
        }
        
        while(memory2 - m2){
            m2 -= i ;
            i++ ;
        }
        
        result.push_back(m1) ;
        result.push_back(m2) ;
        return result ;
    }
};