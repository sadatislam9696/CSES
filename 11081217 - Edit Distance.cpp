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

const int inf = 1e9 + 9;
const int M = 1e9 + 7;
const int N = 5000;

string s, r;
int n, m, dp[N][N]; 
int find_ans(int i, int j){
    if(i == n){
      if(j == m){
        return 0;
      }
      return m - j;
    }
    if(j == m){
      return n - i;
    }
    if(dp[i][j] != -1)return dp[i][j];
    int ans = INT_MAX;
    if(s[i] == r[j]){
       ans = min(ans, find_ans(i + 1, j + 1));
    }
    ans = min(ans, 1 + find_ans(i + 1, j + 1));
    ans = min(ans, 1 + find_ans(i, j + 1));
    ans = min(ans, 1 + find_ans(i + 1, j));
  
    dp[i][j] = ans;
    return ans;
}
void solution(){
    cin >> s >> r; 
    n = s.size(); m = r.size();
    memset(dp, -1, sizeof dp);
    cout << find_ans(0, 0) << nn;
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

