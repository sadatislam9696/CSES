/***   Bismillahir Rahmanir Rahim   ***/

#include<bits/stdc++.h>
using namespace std;

#define     nn          '\n'
#define     ss          second
#define     ff          first
#define     sp(d, n)    fixed << setprecision(d) << n
#define     srt(v)      sort(v.begin(),v.end());
#define     rsrt(v)     sort(v.rbegin(),v.rend());
#define     rev(v)      reverse(v.begin(),v.end());
#define     mem(a, x)   memset(a, x, sizeof a)
#define     yes         cout << "YES" << nn
#define     no          cout << "NO" << nn

using ll =  long long;
using ld =  long double;
using ull = unsigned long long;
const ld pi = acos(-1.0);
template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

int dx[6] = {0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 1, -1};

const int M = 1e9 + 7;
const int N = 1e3 + 9;

void solution() {
    ll n;
    cin >> n;

    ll ans =  0;
    for (ll i = 0; (1LL << i) <= n; i++) {
        ll block = ((n + 1) / (1LL << (i + 1)));
        ans += 1LL * block * (1LL << i);

        ll rem = (n + 1) % (1LL << (i + 1));
        ans += max(0LL, rem - (1LL << i));
    }
    cout << ans << nn;
}
int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1, c = 1;
    //cin >> t;
    //cin.ignore();
    while (t--) {
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}
