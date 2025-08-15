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
const int N = 2e5 + 9;

int n;
set<int>s[N];
int a[N], ans[N];
vector<int>adj[N];

void dfs(int u, int p){
    
    s[u].insert(a[u]);
    for(int v : adj[u]){
        if(v == p)continue;
        dfs(v, u);

        if(s[u].size() < s[v].size()){
            swap(s[u], s[v]);
        }

        for(auto it : s[v]){
            s[u].insert(it);
        }
    }
    
    ans[u] = s[u].size();
}

void solution(){
    cin >> n; 
    for(int i = 1; i <= n; i++){
       cin >> a[i];
    }

    for(int i = 1; i < n; i++){
        int u, v; 
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }  

    dfs(1, -1);
    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
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
