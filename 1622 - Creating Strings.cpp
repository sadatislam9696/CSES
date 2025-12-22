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
    string s;
    cin >> s;

    map<char, int>cnt;
    for (auto it : s) {
        cnt[it]++;
    }

    int fact[10];
    fact[0] = 1;
    for (int i = 1; i <= 9; i++) {
        fact[i] = fact[i - 1] * i;
    }

    int ans = fact[s.size()];
    for (auto it : cnt) {
        ans /= fact[it.ss];
    }

    cout << ans << nn;

    sort(s.begin(), s.end());
    do {
        cout << s << nn;
    } while (next_permutation(s.begin(), s.end()));


}
int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1, c = 1;
    // cin >> t;
    //cin.ignore();
    while (t--) {
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}
