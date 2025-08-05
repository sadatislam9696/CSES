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
int tree[4 * N], a[N];
void build(int node, int l, int r){
    if(l == r){
        tree[node] = a[l];
        return;
    }

    int mid = (l + r) / 2; 
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
int query(int node, int l, int r, int val){
    if(tree[node] < val){
        return -1;
    }
    if(l == r){
        return l;
    }
    int mid = (l + r) / 2; 
    if(tree[2 * node] >= val){
        return query(2 * node, l, mid, val);
    }
    else return query(2 * node + 1, mid + 1, r, val);
}
void update(int node, int l, int r, int ind, int val){
    if(l == r and l == ind){
        tree[node] -= val;
        return;
    }
    int mid = (l + r) / 2; 
    if(ind <= mid){
        update(2 * node, l, mid, ind, val);
    }
    else update(2 * node + 1, mid + 1, r, ind, val);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

void solution(){
    cin >> n >> m; 
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }  
    
    build(1, 1, n);
    while(m--){
        int x; 
        cin >> x;
        int ind = query(1, 1, n, x);
        if(ind == -1){
            cout << 0 << ' ';
        }
        else{
            cout << ind << ' ';
            update(1, 1, n, ind, x);
        }
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
