#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define all(x) x.begin(), x.end()
#define loop(i, k, n) for (ll(i) = (k); (i) <= (n); (i)++)
#define loopr(i, k, n) for (ll(i) = (k); (i) >= (n); (i)--)
#define ff first
#define ss second
#define input(a) for (auto &i : a)cin >> i;
#define output(a) for (auto &i : a)cout << i << ' ';cout << '\n';
#define py cout << "YES\n"
#define pn cout << "NO\n"
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
    cin >> test_case;
    while (test_case--)
    {
        solve();
    }
}

void solve()
{
    cout << "Hello World";
}