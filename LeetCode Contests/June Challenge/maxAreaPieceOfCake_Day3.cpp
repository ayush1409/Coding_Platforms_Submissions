class Solution {
public:
    long long int max(long long int x, long long int y){
        return x > y ? x : y ;
    }
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long int maxWidth = 0 ;
        long long int maxLength = 0 ;
        long long int diff = 0 ;
        sort(horizontalCuts.begin(), horizontalCuts.end()) ;
        sort(verticalCuts.begin(), verticalCuts.end()) ;
        
        for(int i = 0 ; i < horizontalCuts.size() ; i++){
            if(i == 0)
                diff = horizontalCuts[0] ;
            else
                diff = horizontalCuts[i] - horizontalCuts[i-1] ;
            maxLength = max(diff, maxLength) ;
        }
        maxLength = max(maxLength, h - horizontalCuts[horizontalCuts.size()-1]) ;
        
        //cout<<"h : "<<h<<", w: "<<w<<endl ;
        //cout<<maxLength ;
        
        diff = 0 ;
        for(int i = 0 ; i < verticalCuts.size() ; i++){
            if(i == 0)
                diff = verticalCuts[0] ;
            else
                diff = verticalCuts[i] - verticalCuts[i-1] ;
            maxWidth = max(diff, maxWidth) ;
        }
        maxWidth = max(maxWidth, w - verticalCuts[verticalCuts.size()-1]) ;
        
        //cout<<maxWidth ;
        return (maxLength * maxWidth) % 1000000007 ;
    }
};