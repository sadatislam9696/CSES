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
 
int dx[6] = {0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 1, -1};
 
const int M = 1e9 + 7;
const int N = 1e6 + 9;
 
int b[N];
void solution(){
    int n; 
    cin >> n; 
 
    int a[n + 1], ans = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[a[i]]++;
        if(b[a[i]] >= 2) ans = max(ans, a[i]);
    }
 
    for(int i = 2; i < N; i++){
        int cnt = 0;
        for(int j = i + i; j < N; j += i){
            if(b[j] >= 1){
                cnt++;
                if(cnt >= 2)break;
            }
        }
        if(cnt >= 1 and b[i])ans = max(ans, i);
        if(cnt >= 2)ans = max(ans, i);
    }
 
 
    cout << ans;
}
int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
 
    int t = 1, c = 1;
    //cin >> t;
    //cin.ignore();
    while(t--){
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}
