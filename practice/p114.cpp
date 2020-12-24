#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
#define int long long
#define SZ(x) ((int)(x).size()) 
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/


const int mod = 998244353;

int add(int x, int y){
    x += y;
    while(x >= mod) x -= mod;
    while(x < 0) x += mod;
    return x;
}

int mul(int x, int y){
    return (x * y) % mod;
}

int binpow(int x, int y){
    int z = 1;
    while(y){
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

int inv(int x){
    return binpow(x, mod - 2);
}

int divide(int x, int y){
    return mul(x, inv(y));
}


void solve(){


    int n, k; cin>>n>>k;

    int x, y; cin>>x>>y;

    if(n == 1){
    	cout<<1<<el;
    	return;
    }

    int A = 1, B = 0, C = 0;

    int xx = add(mul(n - 1, inv(n)), mul(inv(n), inv(n)));
    int xy = mul(inv(2 * n), inv(n));


    while(k--){
    	int nA = add(mul(A, xx), mul(mul(2 * n - 2, B), xy));
    	int nB = add(mul(B, xx), mul(add(mul(n - 1, C), add(mul(n - 2, B), A)), xy));
    	int nC = add(mul(C, xx), mul(add(mul(2 * n - 4, C), mul(2, B)), xy));
    	A = nA, B = nB, C = nC;
    }

    cout<<A<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}