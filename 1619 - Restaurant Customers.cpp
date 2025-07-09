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
const int N = 4e5 + 9;

int dif[N];
void solution(){
    int n; 
    cin >> n; 

    set<int>s; 
    vector<pair<int, int>>v; 
    for(int i = 1; i <= n; i++){
        int a, b; 
        cin >> a >> b; 

        s.insert(a);
        s.insert(b);
        v.push_back({a, b});
    }

    int val = 1;
    map<int, int>com;
    for(auto it : s){
        com[it] = val++;
    }

    for(int i = 0; i < n; i++){
        v[i].ff = com[v[i].ff];
        v[i].ss = com[v[i].ss];
    }
    
    for(auto it : v){
        dif[it.ff]++;
        dif[it.ss + 1] --;
    }
    for(int i = 1; i < N; i++){
        dif[i] += dif[i - 1];
    }

    val = 0; 
    for(int i = 1; i < N; i++){
        val = max(val, dif[i]);
    }
    cout << val << nn;
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
