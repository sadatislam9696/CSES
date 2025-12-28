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

const ll N = 2e6 + 9, mod = 1e9 + 7;
ll fact[N], ifact[N];
int power(int x, int n) { // O(log n)
    int ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x % mod;
        }
        x = 1LL * x * x % mod;
        n >>= 1;
    }
    return ans;
}

int inverse(int a) { // O(log mod)
    return power(a, mod - 2);
}

void prec() { // O(n)
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = 1LL * fact[i - 1] * i % mod;
    }
    ifact[N - 1] = inverse(fact[N - 1]);
    for (int i = N - 2; i >= 0; i--) {
        ifact[i] = 1LL * ifact[i + 1] * (i + 1) % mod; // 1 / i! = (1 / (i + 1)!) * (i + 1)
    }
}

int nPr(int n, int r) { // O(1)
    if (n < r) return 0;
    return 1LL * fact[n] * ifact[n - r] % mod;
}

int nCr(int n, int r) { // O(1)
    if (n < r) return 0;
    return 1LL * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

void solution() {
    int n, m;
    cin >> n >> m;

    n--;
    m = m + n;

    cout << nCr(m, n) ;
}
int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    prec();

    int t = 1, c = 1;
    // cin >> t;
    //cin.ignore();
    while (t--) {
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}
