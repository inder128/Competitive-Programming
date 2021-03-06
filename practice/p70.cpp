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

const int N = 100;
const int mod = 998244353;
int fact[N], invFact[N];

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

void precalc(){
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i);
    for(int i = 0; i < N; i++)
        invFact[i] = inv(fact[i]);
}

int C(int n, int k){
    return mul(fact[n], mul(invFact[k], invFact[n - k]));
}

void solve(){
	int d, q; cin>>d>>q;

	vi primes;
	for (int i = 2; i*i <= d; ++i){
		if(d % i) continue;
		primes.pb(i);
		while(d % i == 0){
			d /= i;
		}
	}
	if(d > 1) primes.pb(d);

	while(q--){
		int u, v; cin>>u>>v;

		vi diff(primes.size());
		for (int i = 0; i < primes.size(); ++i){
			while(u % primes[i] == 0){
				u /= primes[i];
				diff[i]++;
			}
		}
		for (int i = 0; i < primes.size(); ++i){
			while(v % primes[i] == 0){
				v /= primes[i];
				diff[i]--;
			}
		}

		int ans = 1, neg = 0, pos = 0;
		for(int d : diff){
			if(d > 0){
				ans = mul(ans, inv(fact[d]));
				pos += d;
			}
			else{
				ans = mul(ans, inv(fact[-d]));
				neg -= d;
			}
		}
		ans = mul(ans, fact[pos]);
		ans = mul(ans, fact[neg]);

		cout<<ans<<el;
	}
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    //cin>>T;
    precalc();
    while(T--){
        solve();
    }
    return 0;
}