// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    
    int maxMeetings(int start[], int end[], int n)
    {
        int meetingCount = 0 ;
        vector<pair<int, int>> meet ;
        int time = 0 ;
        
        for(int i = 0 ; i < n ; i++)
            meet.push_back({start[i], end[i]}) ;
        
        sort(meet.begin(), meet.end(), 
                [](pair<int, int> &a, pair<int, int> &b){
                    return a.second == b.second ? 
                    a.first < b.first : a.second < b.second;
                }) ;
        
        for(auto x : meet)
            cout<<"{ "<<x.first<<", "<<x.second<<"} "<<endl ;
        int t = meet[0].second ;
        meetingCount++ ;
        for(int i = 1 ; i < meet.size() ; i++){
            if(t <= meet[i].first){
                t = meet[i].second ;
                meetingCount++ ;
            }
        }
        return meetingCount ;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends