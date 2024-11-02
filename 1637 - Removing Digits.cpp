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

const int mod = 10000007;
const int N = 1e6 + 9;
const int inf = 1e9;

int n, dp[N];
int find_ans(int n){
     if(n == 0)return 0;
     if(dp[n] != -1)return dp[n];
     int x = n; 
     int ans = inf; 
     vector<int>d; 
     while(x){
        d.push_back(x % 10);
        x /= 10;
     }

     for(auto it : d){
        if(it != 0)ans = min(ans, 1 + find_ans(n - it));
     }
     return dp[n] = ans;
}
void solution(){
    cin >> n; 
    memset(dp, -1, sizeof dp);
    cout << find_ans(n) << nn;
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
