vector<int> getMax(vector<string> operations) {
    stack<pair<int, int> > s ;
    vector<int> result ;
    int max = INT_MIN ;
    int val ;
    string val_str ;
    for(int i=0 ; i<operations.size() ; i++){
        if(operations[i][0] == '1'){
            // perform push
            
            val = stoi(operations[i].substr(2, operations[i].size())) ;    
            if(val > max){
                max = val ;
            }
            s.push(make_pair(val, max)) ;
                   
        }
        else if(operations[i][0] == '2'){
            // perform pop
            if(!s.empty())
                s.pop() ;
                
            if(s.empty())
                max = INT_MIN ;
            else
                max = s.top().second ;
        }
        else if(operations[i][0] == '3'){
            //cout<<s.top().second<<endl ;
            result.push_back(s.top().second) ;
        }
    }
    return result ;
    
}