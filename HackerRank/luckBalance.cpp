// Problem : https://www.hackerrank.com/challenges/luck-balance/problem

bool contests_compare(vector<int> c1, vector<int> c2){
    return c1[0] < c2[0] ;
}

int luckBalance(int k, vector<vector<int>> contests) {
    
    int imp_cnt = 0 ;
    int luck = 0 ;
    sort(contests.begin(), contests.end(), contests_compare) ;
    
    for(int i=0 ; i<contests.size() ; i++){
        if(contests[i][1] == 1)
            imp_cnt++ ;
    }
    
    int contest_to_win = imp_cnt - k ;
    
    for(int i=0 ; i<contests.size() ; i++){
        if(contest_to_win > 0 && contests[i][1] == 1){
            luck -= contests[i][0] ;
            contest_to_win-- ;
            continue ;
        }
        
        luck += contests[i][0] ;
    }
    
    return luck ;
}