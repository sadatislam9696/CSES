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

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int M = 1e9 + 7;
const int N = 1e5 + 9;

vector<int>adj[N];
bool vis[N];
int c[N], path[N];
int n, m, node, flag;
int parent;

void dfs(int u, int p){
   vis[u] = 1;

   for(auto v : adj[u]){
     if(!vis[v]){
       path[v] = u;
       dfs(v, u);
     }
     else{
       if(v != p and !flag){
         node = v;
         parent = u;
         flag = 1;
       }
     }
   }
}
void solution(){
     cin >> n >> m; 
     for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
     }
     
     flag = 0;
     for(int i = 1; i <= n; i++){
       if(!vis[i]){
         dfs(i, 0);
       }
     }

     if(!flag){
       cout << "IMPOSSIBLE" << nn;
       return;
     }
     
     int v = parent;
     vector<int>ans;
     while(v != node){
        ans.push_back(v);
        v = path[v];
     }
     ans.push_back(v);
     rev(ans);

     cout << ans.size() + 1 << nn;
     cout << ans[ans.size() - 1] << ' ';
     for(auto v : ans){
       cout << v << ' ';
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
