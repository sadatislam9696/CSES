/***    Bismillahir Rahmanir Rahim    ***/

#include<bits/stdc++.h>
using namespace std;

#define     nn          '\n'
#define     ll          long long
#define     ss          second
#define     ff          first
#define     yes         cout << "YES" << nn
#define     no          cout << "NO" << nn
#define     mem(a, x)   memset(a , x ,sizeof a)
#define     pi          3.1415926536
#define     deg(n)      n*PI/180
#define     sp(n,d)     fixed << setprecision(d) << n
#define     srt(v)      sort(v.begin(),v.end());
#define     rsrt(v)     sort(v.rbegin(),v.rend());
#define     rev(v)      reverse(v.begin(),v.end());

int dx[] = {0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};

const int N = 1001;
char a[N][N], vis[N][N];
int n, m;

bool is_valid(int x, int y){
    return(x > 0 and y > 0 and x <= n and y <= m and !vis[x][y] and a[x][y] == '.');
}
void dfs(int r, int c){

    for(int i = 1; i <= 5; i++){
        int x = r + dx[i];
        int y = c + dy[i];
        if(is_valid(x, y)){
            vis[x][y] = 1;
            dfs(x, y);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while(t--)
    {
       cin >> n >> m;
       for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            vis[i][j] = (a[i][j] == '#');
        }
       }

       int cnt = 0;
       for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!vis[i][j]){
                dfs(i, j);
                cnt++;
            }
        }
       }

       cout << cnt << nn;
    }
    return 0;
}
