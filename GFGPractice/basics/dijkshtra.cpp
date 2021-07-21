#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, vector<bool> &visited);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];

void dijkshtra(vector<vector<pair<int, int>>> &graph, int src, vector<int> &distance){
	int n = graph.size() ;

	distance[src] = 0 ;
	priority_queue<int, vector<int>, greater<int>> pq ;
	pq.push(src) ;

	while(!pq.empty()){
		int u = pq.top() ;
		pq.pop() ;

		for(auto v : graph[u]){
			if(distance[u] + v.second < distance[v.first]){
				distance[v.first] = distance[u] + v.second ;
				pq.push(v.first) ;
			}
		}
	}	
}

void solve() {
	int n, src, e ;
	cin>>n>>e ;
	vector<vector<pair<int, int>>> graph(n) ;
	
	int u, v, w ;
	// input graph
	for(int i = 0 ; i < e; i++){
		cin>>u>>v>>w ;
		graph[u].push_back({v, w}) ;
		graph[v].push_back({u, w}) ;
	}

	//cin>>src ;
	src = 0 ;
	vector<int> distance(n, INT_MAX) ;
	dijkshtra(graph, src, distance) ;

	cout<<"From node "<<src<<endl ;
	for(int i = 0 ; i < n ; i++){
		cout<<"distance to node "<<i<<" is : "<<distance[i]<<endl ;
	}
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    //cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

int mpow(int base, int exp) {
  	base %= mod;
  	int result = 1;
  	while (exp > 0) {
    	if (exp & 1) result = ((ll)result * base) % mod;
    	base = ((ll)base * base) % mod;
    	exp >>= 1;
  	}
  	return result;
}

void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
    //u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
}

void dfs(int u, vector<bool> &visited){
	visited[u] = true ;
	for(auto nbr : g[u]){
		if(!visited[nbr])
			dfs(nbr, visited) ;
	}
}

