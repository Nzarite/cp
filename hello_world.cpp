#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define foi(n) for(ll i=0; i<(n); i++)
#define loop(i, k, n) for(ll (i)=(k); (i)<=(n); (i)++)
#define loopr(i, k, n) for(ll (i)=(k); (i)>=(n); (i)--)
#define input(v) for(auto &inv:v) cin>>inv
#define output(v) for(auto &prv:v) cout<<prv<<" "; cout<<'\n'
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define ps(x,y) fixed<<setprecision(y)<<x
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define minv(a) *min_element(all(a))
#define maxv(a) *max_element(all(a))
#define py cout<<"YES\n"
#define pn cout<<"NO\n"
 
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<string> vstr;
typedef set<int> seti;
typedef set<ll> setl;
typedef multiset<int> mseti;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
 
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
vector<ll> primeFactors(ll n) {vector<ll> v; while(!(n&1)){v.push_back(2);n>>=1;} for(ll i=3; i*i <= n; i+=2){while(n % i == 0) {v.push_back(i); n=n/i;}} if(n>2) v.push_back(n); return v;} 
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
bool isPrime(ll n) {if (n<=1) return false; for (ll i=2; i*i<=n; i++) {if (n%i==0) return false;} return true;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
 
#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define dbg(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void solve();
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif

    ll test_case = 1;
    // cin >> test_case;
    while (test_case--)
    {
        solve();
    }
}

void solve()
{
    cout << "hello world\n";
}