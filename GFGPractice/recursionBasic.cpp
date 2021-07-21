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
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];

// Print decreasing then increasing
void printPDI(int n){
	if(n == 0)
		return ;

	cout<<n ;
	printPDI(n-1) ;
	cout<<n ;
}

// return max of array
int maxArr(vi &vec, int i){
	if(i == vec.size()-1)
		return vec[i] ;
	int m = maxArr(vec, i+1) ;

	return vec[i] > m ? vec[i] : m ;
} 

// return first matching index
int firstIdx(vi &vec, int i, int target){
	if(i == vec.size())
		return -1 ;

	if(i < vec.size() && vec[i] == target)
		return i ;
	return firstIdx(vec, i+1, target) ;
}

// to return the last index
int lastIndex(vi &vec, int i, int target){
	if(i == -1)
		return -1 ;

	if(i >= 0 && vec[i] == target)
		return i ;
	else
		lastIndex(vec, i-1, target) ;

}

// to return the last occurance(2nd approach)
int lastIndexII(vi &vec, int i, int target){
	if(i == vec.size())
		return -1 ;

	int idx = lastIndexII(vec, i + 1, target) ;
	if(idx == -1)
		return vec[i] == target ? i : -1 ;
	else
		return idx ;
}

// return exponent(n,x)
int exp(int n, int x){
	if(x == 1)
		return n ;

	int ans = exp(n, x/2) ;
	ans = ans * ans ;
	if(x % 2)
		ans *= n ;

	return ans ;
}

// Return all indices
void allIndices(vi &vec, int i, int target, vi &result){
	if(i == vec.size())
		return  ;
	if(vec[i] == target)
		result.push_back(i) ;
	allIndices(vec, i+1, target, result) ;
}

// return all indices approach 2
vi allIndicesII(vi &nums, int i , int target, int findSoFar){
	if(i == nums.size() && findSoFar != 0)
		return vi(findSoFar, 0) ;

	if(i == nums.size() && findSoFar == 0)
		return vi();

	vi ans ;

	if(nums[i] == target){
		ans = allIndicesII(nums, i+1, target, findSoFar + 1) ;
		ans[findSoFar] = i ;
	}
	else ans = allIndicesII(nums, i+1, target, findSoFar) ;

	return ans ;
}  

void solve() {
	vi vec = {22,66,332,34,11,55,67,555,11} ;

	auto result = allIndicesII(vec, 0, 11, 0);
	for(auto x : result)
		cout<<x<<" " ;
	cout<<endl ;
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
    u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
}

void dfs(int u, int par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}

