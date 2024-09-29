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
const int N = 1e3 + 9;

char a[N][N];
bool vis[N][N];
int dis[N][N];
pair<int, int>path[N][N];
int n, m;  

bool is_valid(int i, int j){
   return (i >= 1 and i <= n and j >= 1 and j <= m);
}

void solution(){
     cin >> n >> m; 
     int x1, x2, y1, y2;

     for(int i = 1; i <= n; i++){
       for(int j = 1; j <= m; j++){
           cin >> a[i][j];
           if(a[i][j] == 'A'){
             x1 = i; y1 = j;
           }
           else if(a[i][j] == 'B'){
             x2 = i; y2 = j;
           }
       }
     }

     queue<pair<int, int>>q;
     q.push({x1, y1});
     vis[x1][y1] = 1; dis[x1][y1] = 0;
     
     while(!q.empty()){
        int u1 = q.front().ff;
        int u2 = q.front().ss;

        q.pop();
        
        for(int i = 0; i < 4; i++){
           int di = u1 + dx[i];
           int dj = u2 + dy[i];

           if(is_valid(di, dj) and !vis[di][dj] and (a[di][dj] == '.' or a[di][dj] == 'B')){
               vis[di][dj] = 1;
               dis[di][dj] = dis[u1][u2] + 1;
               path[di][dj] = make_pair(u1, u2);
               q.push({di, dj});
           }
        }
     }

     if(dis[x2][y2] == 0){
       cout << "NO" << nn;
       return;
     }

     cout << "YES" << nn;
     cout << dis[x2][y2] << nn;

     vector<char>ans;
     int i = x2, j = y2;
     while(a[i][j] != 'A'){
        int initial_i = i;
        int initial_j = j;

        i = path[i][j].ff;
        j = path[initial_i][j].ss;

        if(initial_i + 1 == i){
          ans.push_back('U');
        }
        else if(initial_j + 1 == j){
          ans.push_back('L');
        }
        else if(initial_j - 1 == j){
          ans.push_back('R');
        }
        else ans.push_back('D');
     }
     
     rev(ans);
     for(auto it : ans){
       cout << it;
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
