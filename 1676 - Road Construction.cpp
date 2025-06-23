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
const int N = 1e3 + 9;

void solution(){
   int n, m; 
   cin >> n >> m; 

   vector<pair<int, int>>adj[n + 1];
   for(int i = 1; i <= m; i++){
      int u, v, c; 
      cin >> u >> v >> c; 
      adj[u].push_back({c, v});
      adj[v].push_back({c, u});
   }  

   minHeap<pair<int, int>>q; 
   q.push({0, 1});

   int vis[n + 1] = {0};
   vis[1] = 1;

   ll ans = 0;
   while(!q.empty()){
      int u = q.top().ss;
      int w = q.top().ff; 
      q.pop(); 

      if(!vis[u]){
         vis[u] = 1;
         ans += w;
      }
      for(auto it : adj[u]){
         int v = it.ss; 
         int c = it.ff; 
         if(!vis[v]){
            q.push({c, v});
         }
      }
   }

   int flag = 0;
   for(int i = 1; i <= n; i++){
      if(!vis[i])flag = 1;
   }

   if(flag)cout << "IMPOSSIBLE" << nn;
   else cout << ans << nn;
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
