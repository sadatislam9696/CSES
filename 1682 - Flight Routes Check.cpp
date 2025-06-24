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

int n, m;
bool vis[N];
vector<int>adj[N], adjr[N];

void dfs(int u, vector<int>g[]){
   vis[u] = 1;
   for(auto v : g[u]){
      if(!vis[v]){
         dfs(v, g);
      }
   }
}
void solution(){
   int n, m; 
   cin >> n >> m; 

   for(int i = 1; i <= m; i++){
      int u, v; 
      cin >> u >> v; 

      adj[u].push_back(v);
      adjr[v].push_back(u);
   }

   dfs(1, adj);
   for(int i = 1; i <= n; i++){
      if(!vis[i]){
         cout << "NO" << nn;
         cout << 1 << ' ' << i << nn;
         return; 
      }
      vis[i] = 0;
   }

   dfs(1, adjr);
   for(int i = 1; i <= n; i++){
      if(!vis[i]){
         cout << "NO" << nn;
         cout << i << " " << 1 << nn;
         return;
      }
   }
   cout << "YES" << nn;
}
int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    //cin.ignore();
    while(t--){
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}
