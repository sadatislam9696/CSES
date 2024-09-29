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
int indeg[N];
bool vis[N];

void solution(){
   int n, m; 
   cin >> n >> m;

   for(int i = 1; i <= m; i++){
     int u, v; cin >> u >> v; 
     indeg[v]++;
     adj[u].push_back(v);
   }

   vector<int>z;
   for(int i = 1; i <= n; i++){
     if(indeg[i] == 0){
       z.push_back(i);
       vis[i] = 1;
     }
   }

   vector<int>ans;
   while(ans.size() < n){
     if(z.empty()){
        cout << "IMPOSSIBLE" << nn;
        return;
     }

     int cur = z.back();
     z.pop_back();
     ans.push_back(cur);

     for(auto v : adj[cur]){
       indeg[v]--;
       if(indeg[v] == 0  and !vis[v]){
         z.push_back(v);
         vis[v] = 1;
       }
     }
   }

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
