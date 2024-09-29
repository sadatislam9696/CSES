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

int dx[6] = {0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 1, -1};

const int M = 1e9 + 7;
const int N = 1e5 + 9;

vector<int>adj[N];
int dis[N], p[N]; 
bool vis[N];

void solution(){
   int n, m; 
   cin >> n >> m; 
   
   for(int i = 1; i <= m; i++){
      int u, v; cin >> u >> v; 
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   queue<int>q;
   q.push(1); vis[1] = 1; dis[1] = 0;
   
   
   while(!q.empty()){
      int u = q.front();
      q.pop();

      for(auto v : adj[u]){
          if(!vis[v]){
             q.push(v);
             vis[v] = true;
             dis[v] = dis[u] + 1;
             p[v] = u;
          }
      }

   }

   if(dis[n] == 0){
      cout << "IMPOSSIBLE" << nn;
      return;
   }

   vector<int>ans;
   int v = n;
   while(v != 1){
      ans.push_back(v);
      v = p[v];
   }
   ans.push_back(1);
   
   rev(ans);
   cout << ans.size() << nn;
   for(auto it : ans){
       cout << it << ' ';
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
