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

int findP(int v, vector<int> &parent){
	if(parent[v] == -1)
		return v ;
	return findP(parent[v], parent) ;
}

void merge(int u, int v, vector<int> &parent){
	int uP = findP(u, parent) ;
	int vP = findP(v, parent) ;

	parent[uP] = vP ;
}

bool isCyclic(vector<pair<int,int>> &edge_list, vector<int> &parent){
	int u, v, uParent, vParent ;
	for(auto edge : edge_list){
		u = edge.first ;
		v = edge.second ;
		uParent = findP(u, parent) ;
		vParent = findP(v, parent) ;

		if(uParent == vParent)
			return true ;

		merge(uParent, vParent, parent) ;
	}

	return false ;
}

void solve() {
	int V,e,u,v ;
	cin>>V>>e ;

	vector<int> parent(V, -1) ;
	vector<pair<int, int>> edge_list ;

	for(int i = 0 ; i < e ; i++){
		cin>>u>>v ;
		edge_list.push_back({u,v}) ;
	}	

	if(isCyclic(edge_list, parent))
		cout<<"Cyclic graph\n" ;
	else
		cout<<"Non-Cyclic graph\n" ;
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

