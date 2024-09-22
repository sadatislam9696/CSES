
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

int dx[] = {1, -1, 0, 0, -1, 1, 1, -1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int M = 1e9 + 7;
const int N = 1e5 + 9;

vector<int>adj[N];
bool vis[N];

void dfs(int u){
   vis[u] = 1;
   for(auto v : adj[u]){
      if(!vis[v]){
         dfs(v);
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
       adj[v].push_back(u);
   }

   int cnt = 0;
   vector<int>ans;
   for(int i = 1; i <= n; i++){
      if(!vis[i]){
         cnt++;
         ans.push_back(i);
         dfs(i);
      }
   }

   cout << cnt - 1 << nn;
   n = ans.size();

   for(int i = 1; i < n; i++){
      cout << ans[i - 1] << ' ' << ans[i] << nn;
   }
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
