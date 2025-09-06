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

using ll =  long long;
using ld =  long double;
using ull = unsigned long long;
const ld pi = acos(-1.0);
template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;

const int M = 1e9 + 7;
const ll N = 2e5 + 9;

struct segtree {
    ll t[4 * N];

    void build(int n, int b, int e, ll ar[]) {
        if (b == e) {
            t[n] = ar[b];
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l + 1;
        build(l, b, mid, ar);
        build(r, mid + 1, e, ar);
        t[n] = min(t[l], t[r]);
    }

    void update(int n, int b, int e, int i, ll v) {
        if (i < b || e < i) return;
        if (b == e && b == i) {
            t[n] = v;
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l + 1;
        update(l, b, mid, i, v);
        update(r, mid + 1, e, i, v);
        t[n] = min(t[l], t[r]);
    }

    ll query(int n, int b, int e, int i, int j) {
        if (e < i || b > j) return LLONG_MAX;
        if (b >= i && e <= j) return t[n];
        int mid = (b + e) >> 1, l = n << 1, r = l + 1;
        return min(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
    }
} inc, dic;

void solution() {
    int n, q;
    cin >> n >> q;
    int c[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    ll a[n + 1] = {0};
    ll b[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        a[i] = 1LL * c[i] + i;
    }
    for (int i = n; i >= 1; i--) {
        b[i] = 1LL * c[i] + (n - i) + 1;
    }

    inc.build(1, 1, n, a);
    dic.build(1, 1, n, b);

    while (q--) {
        int ty;
        cin >> ty;
        if (ty == 1) {
            int idx, v;
            cin >> idx >> v;
            inc.update(1, 1, n, idx, 1LL * idx + v);
            dic.update(1, 1, n, idx, 1LL * ((n - idx) + 1) + v);
        } else {
            int idx;
            cin >> idx;
            ll mn = inc.query(1, 1, n, idx, n) - idx;
            mn = min(mn, dic.query(1, 1, n, 1, max(1, idx - 1)) - ((n - idx) + 1));
            cout << mn << nn;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}
